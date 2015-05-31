
#include "TerrainLighting.h"

#include <iostream>
#include <fstream>

//--------------------------------------------------------------------------------------

TerrainLighting::TerrainLighting() :
	m_lightmapData(nullptr),
	m_lightmapSize(0),
	m_directionX(0),
	m_directionZ(0),
	m_minBrightness(0),
	m_maxBrightness(0),
	m_softness(0),
	m_lightingType(SLOPE_LIGHT)
{
	m_lightmapColour.reset();
}
	
//--------------------------------------------------------------------------------------

TerrainLighting::~TerrainLighting()
{
	UnloadLightmap();
}

//--------------------------------------------------------------------------------------

bool TerrainLighting::LoadLightmap(char *file, const int size)
{
	// open file to read in binary
	std::ifstream infile(file, std::ios::binary);
	if(!infile) {
		std::cerr << "Cannot open file: " << file << std::endl;
		return false;
	}

	// terrain exists delete existing
	if(m_lightmapData)
		delete[] m_lightmapData;
	// allocate memory for new terrain
	if(size > 0)
		m_lightmapData = new unsigned char[size * size];
	// if failed to assign memory return false
	if(m_lightmapData == nullptr)
		return false;
	else {
		// read in height field
		infile.seekg(0, std::ios::end); // get file length
		int length = infile.tellg();
		// read data as block
		infile.seekg(0, std::ios::beg);
		infile.read(reinterpret_cast<char *>(m_lightmapData), length);
		infile.close();
		m_lightmapSize = size;
		m_lightingType = LIGHTMAP;
	}

	return true;
}

//--------------------------------------------------------------------------------------

void TerrainLighting::UnloadLightmap()
{
	//check to see if the data has been set
	if(m_lightmapData) {
		//delete the data
		delete[] m_lightmapData;

		//reset the map dimensions also
		m_lightmapSize= 0;
	}
}

//--------------------------------------------------------------------------------------

bool TerrainLighting::SaveLightmap(char *file)
{
	// open file to read in binary
	std::ofstream outfile(file, std::ios::binary);
	if(!outfile) {
		std::cerr << "Cannot open file: " << file << std::endl;
		return false;
	}

	// confirm terrain exists
	if(!m_lightmapData)
		return false;
	else {
		outfile.write(reinterpret_cast<char *>(m_lightmapData), m_lightmapSize);
		outfile.close();
	}

	return true;
}

//--------------------------------------------------------------------------------------

unsigned char* TerrainLighting::GetLightmap()
{
	return m_lightmapData;
}

//--------------------------------------------------------------------------------------

int TerrainLighting::GetSize()
{
	return m_lightmapSize;
}

//--------------------------------------------------------------------------------------

unsigned char TerrainLighting::GetBrightnessAtPoint(int x, int z)
{
	return (m_lightmapData[(z*m_lightmapSize) + x]);
}

//--------------------------------------------------------------------------------------

RGB<float> TerrainLighting::GetLightmapColour()
{
	return m_lightmapColour;
}

//--------------------------------------------------------------------------------------

float TerrainLighting::GetValueAtPoint(unsigned char* verts, int size, int xPos, int zPos)
{
		return verts[(zPos*size)+xPos];
}

//--------------------------------------------------------------------------------------

int TerrainLighting::GetDirectionX()
{
	return m_directionX;
}

//--------------------------------------------------------------------------------------

int TerrainLighting::GetDirectionZ()
{
	return m_directionZ;
}

//--------------------------------------------------------------------------------------

float TerrainLighting::GetMinBrightness()
{
	return m_minBrightness;
}

//--------------------------------------------------------------------------------------

float TerrainLighting::GetMaxBrightness()
{
	return m_maxBrightness;
}

//--------------------------------------------------------------------------------------

float TerrainLighting::GetSoftness()
{
	return m_softness;
}

//--------------------------------------------------------------------------------------

LIGHTING_TYPE TerrainLighting::GetLightingType()
{
	return m_lightingType;
}

//--------------------------------------------------------------------------------------

void TerrainLighting::SetLightmapSize(int size)
{
	m_lightmapSize = size;
}

//--------------------------------------------------------------------------------------

bool TerrainLighting::SetBrightnessAtPoint( int x, int z, unsigned char brightness)
{
	if(Inbounds(x, z)) {
		m_lightmapData[(z*m_lightmapSize) + x] = brightness;
		return true;
	}
	return false;
}

//--------------------------------------------------------------------------------------

void TerrainLighting::SetDirection(int x, int z)
{
	m_directionX = x;
	m_directionZ = z;
}

//--------------------------------------------------------------------------------------

void TerrainLighting::SetBrightness(float min, float max)
{
	m_minBrightness = min;
	m_maxBrightness = max;
}

//--------------------------------------------------------------------------------------

void TerrainLighting::SetSoftness(float soft)
{
	m_softness = soft;
}

//--------------------------------------------------------------------------------------

void TerrainLighting::SetLightingType(LIGHTING_TYPE type)
{
	m_lightingType = type;
}

//--------------------------------------------------------------------------------------

void TerrainLighting::SetLightmapColor(unsigned char red,unsigned char green, unsigned char blue)
{
	m_lightmapColour.r = (float)red;
	m_lightmapColour.g = (float)green;
	m_lightmapColour.b = (float)blue;
}

//--------------------------------------------------------------------------------------

void TerrainLighting::SetSlopeLightingParams(int dirx,int dirz,float minB,float maxB,float soft)
{
		//set the light direction
		m_directionX= dirx;
		m_directionZ= dirz;

		//set the min/max shading values
		m_minBrightness= minB;
		m_maxBrightness= maxB;

		//the light's softness
		m_softness= soft;
}

//--------------------------------------------------------------------------------------

bool TerrainLighting::CreateSlopeLighting(unsigned char *heightmap, int mapSize)
{
	float fShade;
	int x, z;

	//if using light map or height map empty
	if(!heightmap || m_lightingType == LIGHTMAP)
		return false;

	// if light map exists delete existing
	if(m_lightmapData)
		delete[] m_lightmapData;

	//allocate memory for the new lightmap data buffer
	m_lightmapSize = mapSize;
	m_lightmapData= new unsigned char [m_lightmapSize*m_lightmapSize];

	//loop through all vertices
	for( z=0; z<m_lightmapSize; z++ ) {
		for( x=0; x<m_lightmapSize; x++ ) {
			int xl=x-m_directionX; 
			int zl=z-m_directionZ; //position of the nearby vertex

			if(!Inbounds(xl, zl)) {
				fShade = 1.0f; // (x,z) is on the edge of heightmap, not blocked
			} 
			else {
				fShade= 1.0f - (GetValueAtPoint(heightmap, mapSize, xl, zl)
						- GetValueAtPoint(heightmap, mapSize, x, z)) / m_softness;
			}

			if( fShade<m_minBrightness )
				fShade= m_minBrightness;
			if( fShade>m_maxBrightness )
				fShade= m_maxBrightness;
			SetBrightnessAtPoint( x, z, ( unsigned char )( fShade*255 ) );
		}
	}

	return true;
}

//--------------------------------------------------------------------------------------

bool TerrainLighting::Inbounds(int xPos, int zPos)
{
	return(zPos >= 0 && zPos < m_lightmapSize && 
			xPos >= 0 && xPos < m_lightmapSize);
}