
#include "Terrain.h"
#include "../Singletons.h"
#include "../AssetManagement/multitexture.h"

#include <iostream>
#include <fstream>
#include <time.h>

//--------------------------------------------------------------------------------------

Terrain::Terrain() : 
	m_terrainData(nullptr), 
	m_texMapID(0),
	m_detailMapTexID(0),
	m_numTerrainTexRepeat(1),
	m_numDetailMapRepeat(1),
	m_size(0),
	m_texMap(false),
	m_texMapDetail(false),
	m_textureGenerator(textureGenerator()),
	m_lighting(TerrainLighting()),
	m_scale(1.0f, 1.0f, 1.0f)
{
	initMultiTextures();
}

//--------------------------------------------------------------------------------------

Terrain::~Terrain()
{
	UnloadHeightfield();
}

//--------------------------------------------------------------------------------------

bool Terrain::LoadHeightfield(char *file, const int size)
{
	// open file to read in binary
	std::ifstream infile(file, std::ios::binary);
	if(!infile) {
		std::cerr << "Cannot open file: " << file << std::endl;
		return false;
	}

	// terrain exists delete existing
	if(m_terrainData)
		delete[] m_terrainData;
	// allocate memory for new terrain
	if(size > 0)
		m_terrainData = new unsigned char[size * size];
	// if failed to assign memory return false
	if(m_terrainData == nullptr)
		return false;
	else {
		// read in height field
		infile.seekg(0, std::ios::end); // get file length
		int length = infile.tellg();
		// read data as block
		infile.seekg(0, std::ios::beg);
		infile.read(reinterpret_cast<char *>(m_terrainData), length);
		infile.close();
		m_size = size;
	}

	return true;
}

//--------------------------------------------------------------------------------------

bool Terrain::LoadHeightfield(Texture* file)
{
	if(m_terrainData)
		delete[] m_terrainData;

	if(file->GetHeight() != file->GetWidth())
		return false;

	m_size = file->GetWidth();

	int verticeCount = m_size * m_size;

	unsigned char *d = new unsigned char[verticeCount];
	
	int count = 0;
	for (int i = 0; i < verticeCount * 3; i+=3 )
	{
		d[count] = file->GetData()[i];
		count++;
	}
	m_terrainData = d;

	return true;
}

//--------------------------------------------------------------------------------------

void Terrain::UnloadHeightfield()
{
	//check to see if the data has been set
	if(m_terrainData)
	{
		//delete the data
		delete[] m_terrainData;

		//reset the map dimensions also
		m_size= 0;
	}
}

//--------------------------------------------------------------------------------------

bool Terrain::SaveHeightfield(char *file)
{
	// open file to read in binary
	std::ofstream outfile(file, std::ios::binary);
	if(!outfile) {
		std::cerr << "Cannot open file: " << file << std::endl;
		return false;
	}

	// confirm terrain exists
	if(!m_terrainData)
		return false;
	else {
		outfile.write(reinterpret_cast<char *>(m_terrainData), m_size);
		outfile.close();
	}

	return true;
}

//--------------------------------------------------------------------------------------

int Terrain::GetSize()
{
	return m_size;
}

//--------------------------------------------------------------------------------------

unsigned char Terrain::GetHeightColour(int xPos, int zPos)
{
	if(Inbounds(xPos, zPos)) {
		return m_terrainData[zPos*m_size+xPos];
	}

	return 1;
}

//--------------------------------------------------------------------------------------

float Terrain::GetHeightScaled(int xPos, int zPos)
{
	if(Inbounds(xPos, zPos)) {
		return ((float)(m_terrainData[(zPos*m_size)+xPos]) * m_scale.y);
	}

	return xPos * zPos;
}

//--------------------------------------------------------------------------------------

float Terrain::GetHeightUnscaled(int xPos, int zPos)
{
	if(Inbounds(xPos, zPos)) {
		return ((float)(m_terrainData[(zPos*m_size)+xPos]));
	}

	return xPos * zPos;
}

//--------------------------------------------------------------------------------------

float Terrain::GetHeightAverage(float xPos, float zPos)
{
	float xLow = floorf(xPos);
	float zLow = floorf(zPos);
	float xHigh = ceilf(xPos);
	float zHigh = ceilf(zPos);

	if(xLow == xHigh && zLow == zHigh) {
		return GetHeightScaled(xPos, zPos);
	}
	else {
		float hh = GetHeightScaled(xHigh, zHigh);
		float hl = GetHeightScaled(xHigh, zLow);
		float lh = GetHeightScaled(xLow, zHigh);
		float ll = GetHeightScaled(xLow, zLow);

		float aveH = hh*(xPos-xLow) + lh*(1.0f-(xPos-xLow));
		float aveL = hl*(xPos-xLow) + ll*(1.0f-(xPos-xLow));

		return aveH*(zPos-zLow) + aveL*(1.0f-(zPos-zLow));
	}
}

//--------------------------------------------------------------------------------------

void Terrain::SetScaleFactor(float xScale, float yScale, float zScale)
{
	m_scale.x = xScale;
	m_scale.y = yScale;
	m_scale.z = zScale;
}

//--------------------------------------------------------------------------------------

void Terrain::SetHeightAtPoint(unsigned char height, int xPos, int zPos)
{
	m_terrainData[(zPos*m_size ) + xPos]= height;
}

//--------------------------------------------------------------------------------------

bool Terrain::GenFaultFormation(int iterations, int size, int minHeight, 
	int maxHeight, float weight, bool random)
{
	int x1, x2, z1, z2;
	float* heights = nullptr;
	int displacement;

	if(size <= 0)
		return false;
	if(random) // create true random map
		srand(time(nullptr));

	// terrain exists delete existing
	if(m_terrainData)
		delete[] m_terrainData;
	// allocate heightfield array memory
	m_size = size;
	heights = new float[m_size*m_size];
	m_terrainData = new unsigned char[m_size*m_size];
	if(heights == nullptr || m_terrainData == nullptr)
		return false;

	// initialise heightfiled array to zeros
	for(int i = 0; i < m_size*m_size; i++)
		heights[i] = 0;

	// generate heightfield
	for(int j = 0; j < iterations; j++) {
		// calculate reducing displcement value is how much to alter the hight
		displacement = maxHeight - ((maxHeight-minHeight)*j) / iterations;

		// pick the first point P1(x1, z1) at random from the entire heigh map
		x1 = (rand() % m_size);
		z1 = (rand() % m_size);

		// pickup second random point & ensure it's different from first
		do {
			x2 = (rand() % m_size);
			z2 = (rand() % m_size);
		}
		while (x2 == x1 && z2 == z1);

		// for each point P(x, z) in the filed calculate the new height values
		for(int z = 0; z < m_size; z++) {
			for(int x = 0; x < m_size; x++) {
				// determine which side of the line P1P2 point P lies on
				if((x-x1) * (z2-z1) - (x2-x1) * (z-z1) > 0) {
					heights[(z*m_size)+x] += (float)displacement;
				}
			}
		}
		AddFilter(heights, weight);

		// normalis heightfield
		NormaliseTerrain(heights);

		// copy the float heightfield to terrainData (in unsigned char)
		for(int z = 0; z < m_size; z++) {
			for(int x = 0; x < m_size; x++) {
				SetHeightAtPoint((unsigned char)heights[(z*m_size) + x], x, z);
			}
		}
	}
	delete[] heights;

	return true;
}

//--------------------------------------------------------------------------------------

unsigned char* Terrain::GetProTexData()
{
	return m_textureGenerator.getNewTexData();
}

//--------------------------------------------------------------------------------------

int Terrain::GetProTexWidth()
{
	return m_textureGenerator.getNewTexWidth();
}

//--------------------------------------------------------------------------------------

int Terrain::GetProTexHeight()
{
	return m_textureGenerator.getNewTexHeight();
}

//--------------------------------------------------------------------------------------

bool Terrain::SetTexture(unsigned int tex)
{
	std::cout << "tex" << tex << std::endl;
	if(tex) {
		m_texMapID = tex;
		m_texMap = true;
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------------

bool Terrain::SetDetailMap(unsigned int tex)
{
	if(tex) {
		m_detailMapTexID = tex;
		m_texMapDetail = true;
		return true;
	}

	return false;
}

//--------------------------------------------------------------------------------------

void Terrain::SetNumTerrainTexRepeat(int num)
{
	m_numTerrainTexRepeat = num;
}

//--------------------------------------------------------------------------------------

void Terrain::SetNumDetailMapRepeat(int num)
{
	m_numDetailMapRepeat = num;
}

//--------------------------------------------------------------------------------------

bool Terrain::AddProceduralTexture(Texture* tex)
{
	return m_textureGenerator.addTexture(tex);
}

//--------------------------------------------------------------------------------------

bool Terrain::CreateProceduralTexture()
{
	return m_textureGenerator.CreateProceduralTexture(m_terrainData, m_size);
}

//--------------------------------------------------------------------------------------

unsigned char Terrain::GetBrightnessAtPoint(int x, int z)
{
	return m_lighting.GetBrightnessAtPoint(x, z);
}

//--------------------------------------------------------------------------------------

unsigned char* Terrain::GetLightMap()
{
	return m_lighting.GetLightmap();
}

//--------------------------------------------------------------------------------------

RGB<float> Terrain::GetLightMapColour()
{
	return m_lighting.GetLightmapColour();
}

//--------------------------------------------------------------------------------------

void Terrain::SetLightingColor(unsigned char red,unsigned char green, unsigned char blue)
{
	m_lighting.SetLightmapColor(red, green, blue);
}

//--------------------------------------------------------------------------------------

void Terrain::SetSlopeLightingParams(int dirx,int dirz,float minB,float maxB,float soft)
{
	m_lighting.SetSlopeLightingParams(dirx, dirz, minB, maxB, soft);
}

//--------------------------------------------------------------------------------------

bool Terrain::CreateSlopeLighting()
{
	m_lighting.SetLightingType(SLOPE_LIGHT);
	return m_lighting.CreateSlopeLighting(m_terrainData, m_size+20);
}

//--------------------------------------------------------------------------------------

bool Terrain::Inbounds(int xPos, int zPos)
{
	return(zPos >= 0 && zPos < m_size && 
			xPos >= 0 && xPos < m_size);
}

//--------------------------------------------------------------------------------------

void Terrain::FilterPass(float* dataP, int increment, float weight)
{
	float yPrev = dataP[0]; 
	int j = increment;
	float k = weight;

	for(int i = 1; i < m_size; i++) {
		*(dataP+j) = k*yPrev + (1-k) * (*(dataP+j));
		yPrev = *(dataP+j);
		j += increment;
	}
}

//--------------------------------------------------------------------------------------

void Terrain::AddFilter(float* terrainData, float weight)
{
	int i;

	// erode left to right, starting from the beginning
	for(i = 0; i < m_size; i++)
		FilterPass(&terrainData[m_size*i], 1, weight);

	// erode right to left, starting from the end of each row
	for(i = 0; i < m_size; i++)
		FilterPass(&terrainData[m_size*i + m_size-1], -1, weight);

	// erode top to bottm, starting at the beginning of the column
	for(i = 0; i < m_size; i++)
		FilterPass(&terrainData[i], m_size, weight);

	// erode from bottom to top, starting from the end of the column
	for(i = 0; i < m_size; i++)
		FilterPass(&terrainData[m_size*(m_size-1) + i], -m_size, weight);
}

//--------------------------------------------------------------------------------------

void Terrain::NormaliseTerrain(float* terrainData)
{
	float fMin, fMax, fHeight;
	int i;

	fMin = terrainData[0];
	fMax = terrainData[0];

	// find the min/max values of terrainData
	for(i = 1; i < m_size*m_size; i++) {
		if(terrainData[i] > fMax)
			fMax = terrainData[i];
		else if(terrainData[i] < fMin)
			fMin = terrainData[i];
	}

	// find the altitude range
	if(fMax <= fMin)
		return;
	fHeight = fMax - fMin;

	// scale to 0-255 range
	for(i = 0; i < m_size*m_size; i++)
		terrainData[i] = ((terrainData[i]-fMin) / fHeight) * 255.0f;
}

//--------------------------------------------------------------------------------------

void Terrain::GetTexCoords( int texNum, unsigned int& x, unsigned int& y )
{
	unsigned int width = m_textureGenerator.getTexHeight(texNum);
	unsigned int height= m_textureGenerator.getTexWidth(texNum);
	int repeatX= -1; // number of repeats in X direction
	int repeatY= -1; // number of repeats in Y direction
	int i = 0;

	//loop until we figure out how many times the tile has repeated (on the X axis)
	while( repeatX==-1 ){
		i++;
		//if x is less than the total width, found
		if(x < (width * i))
			repeatX = i - 1;
	}

	//prepare to figure out the repetition on the Y axis
	i= 0;
	//loop until we figure out how many times the tile has repeated (on the Y axis)
	while(repeatY== -1){
		i++;
		//if y is less than the total height good
		if(y < (height * i))
			repeatY = i - 1;
	}

	//update the given texture coordinates
	x = x-(width*repeatX);
	y = y-(height*repeatY);
}

//////////////////////////////////////////////////////////////////////////////////
