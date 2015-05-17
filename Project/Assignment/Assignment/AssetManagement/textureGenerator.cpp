
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#include "textureGenerator.h"
#include <iostream>
#include "../Singletons.h"
using namespace std;
//#include <gl/glut.h>

textureGenerator::textureGenerator()
{
	for(int i=0;i<4;i++)
		tex[i]=nullptr;
	numTextures=0;
	newTex=nullptr;
	newTexWidth=0;
	newTexHeight=0;
	newTexBPP=3;  //24 bit
	newTexName = "";
}

textureGenerator::~textureGenerator()
{
	//delete newTex;

	//if(numTextures > 0) {
	//  for(int i=0;i<numTextures;i++) {
	//	delete tex[i];
	//	tex[i] = nullptr;
	//  }
	//}
}


//bool textureGenerator::addTexture(char* filename)
//{
//      if(numTextures<4)
//	  { 
//		numTextures++;
//		  if(tex[numTextures-1]=texManager->loadTextureRaw(filename))
//		 	return true;
//		  else
//		    numTextures--;
//	  }
// return false;
//}

bool textureGenerator::addTexture(Texture* texture)
{
	if(numTextures < 4 && texture) { 
		numTextures++;
		if(tex[numTextures-1]=texture) {
			std::cout << "tex " << numTextures << " loaded" << std::endl;
			return true;
		}
		else
		numTextures--;
	}
	return false;
}

int textureGenerator::getNumTextures()
{
	return numTextures;
}

bool textureGenerator::isLoaded(int index)
{
	if(index<4 && index >-1)
	  return (tex[index]!=NULL);

	return false;
}

RGB<unsigned char> textureGenerator::getColor(int texNum,int x, int y)
{
	RGB<unsigned char> val={0,0,0};

	if(texNum>3 || texNum<0)
		return val;

	return tex[texNum]->GetColor(x,y);
}

void textureGenerator::setColor( int x, int y, RGB<unsigned char> color)
{
	if( ( x<newTexWidth ) && ( y<newTexHeight ) ) {
		newTex[( ( y*newTexHeight )+x )*newTexBPP]  = color.r;
		newTex[( ( y*newTexHeight )+x )*newTexBPP+1]= color.g;
		newTex[( ( y*newTexHeight )+x )*newTexBPP+2]= color.b;
	}
}

bool textureGenerator::setupNewTexture(int width, int height)
{
	//to add - ensure power of 2
	newTexHeight=height;
	newTexWidth=width;
	newTex=new unsigned char[newTexHeight*newTexWidth*newTexBPP];
	if(!newTex)
		return false;
	return true;
}

float textureGenerator::getRange()
{
	  if(numTextures>0)
		  return 255.0f/(float)numTextures;
	return 0.0f;
}

float textureGenerator::getTextureMax(int texNum)
{
	  if(texNum>numTextures-1)
		  return 0.0f;
	  else
		  return((255.0f/(float)numTextures)*(texNum+1));
}

unsigned int textureGenerator::getTexWidth(int texNo)
{
     if(texNo>0 && texNo <numTextures)
		 return tex[texNo]->GetWidth();
 return -1;
}

unsigned int textureGenerator::getTexHeight(int texNo)
{
     if(texNo>0 && texNo <numTextures)
		 return tex[texNo]->GetHeight();
 return -1;
}

//--------------------------------------------------------------------------------------

bool textureGenerator::CreateProceduralTexture(std::string name, unsigned char* terrain, int terrainSize)
{
	if(!terrain || numTextures == 0)
		return false;
	
	newTexName = name;

	unsigned char curHeight; //current height in the heightmap
	float weight; //weight of influence of tex to height
	unsigned int texX = 0, texZ = 0;

	//setup room for the new texture
	setupNewTexture(terrainSize,terrainSize);
	RGB<unsigned char> color;
	RGB<unsigned char> totalColor;
	float range = getRange();

	//loop through each value in the heightmap and get height value
	for(int z = 0; z < terrainSize; z++) {
		for(int x = 0; x < terrainSize; x++) {
			totalColor.reset();
			curHeight = GetHeightColour(terrain, terrainSize, x,z); //get unscaled heightmap value
			for(int i = 0; i < getNumTextures(); i++) { 
				// setup texture coords
				texX = x;
				texZ = z;
				GetTexCoords(i, texX, texZ);

				//calculate weight for each texture map
				weight = (range-abs((float)curHeight - getTextureMax(i)))/range;
				if(weight  > 0.0) { //texture is influenced by the height, calculate its color weighting
					color = getColor(i, texX, texZ);
					totalColor.r += color.r * weight;
					totalColor.g += color.g * weight;
					totalColor.b += color.b * weight;
				}
			} //add the combined color weightings to the new texture.
			setColor(x, z, totalColor);
		}
	}
	//load the new texture into memory ready for use
	//m_texMapProceduralID = texManager->createNewTexture(getTex(), size, size);
	//m_texMapNormal = false;
	//m_texMapProcedural = true;

	//dont repeat this texture
//	m_numTerrainTexRepeat=1;


	return true;
}

//--------------------------------------------------------------------------------------

Texture* textureGenerator::GetProceduralTexture(std::string name)
{
	newTexName = name;
	return new Texture((char*)newTexName.c_str(), newTex, newTexWidth, newTexHeight, newTexBPP);
}

//--------------------------------------------------------------------------------------

unsigned char textureGenerator::GetHeightColour(unsigned char* data, int size, int xPos, int zPos)
{
	if(Inbounds(size, xPos, zPos)) {
		return data[zPos*size+xPos];
	}

	return 1;
}

//--------------------------------------------------------------------------------------

bool textureGenerator::Inbounds(int size, int xPos, int zPos)
{
	return(zPos >= 0 && zPos < size && 
			xPos >= 0 && xPos < size);
}

//--------------------------------------------------------------------------------------

void textureGenerator::GetTexCoords( int texNum, unsigned int& x, unsigned int& y )
{
	unsigned int width = getTexHeight(texNum);
	unsigned int height= getTexWidth(texNum);
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