
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#ifndef __TEXTUREGENERATOR_H 
#define __TEXTUREGENERATOR_H 
#if _MCS_VER >= 1020
  #pragma once
#endif

#include "Texture.h"

class textureGenerator
{

public:
	textureGenerator();
	~textureGenerator();
	//bool addTexture(char* filename);

	bool addTexture(Texture* texture);

	int getNumTextures();
	bool isLoaded(int index);
	RGB<unsigned char> getColor(int texNum,int x, int y);
	void setColor(int x, int y, RGB<unsigned char> color);
	unsigned char* getTex(){return newTex;}
	bool setupNewTexture(int width, int height);
	float getRange();
	float getTextureMax(int texNum);
	unsigned int getTexWidth(int texNo);
	unsigned int getTexHeight(int texNo);

	bool CreateProceduralTexture(std::string name, unsigned char* data, int size);
	Texture* GetProceduralTexture(std::string name);

private:
	
	unsigned char GetHeightColour(unsigned char* data, int size, int xPos, int zPos);

	bool Inbounds(int size, int xPos, int zPos);

	void GetTexCoords( int texNum, unsigned int& x, unsigned int& y );


	Texture* tex[4];   //textures 0-3, 4 in total
	unsigned char* newTex;
	int newTexWidth;
	int newTexHeight;
	int newTexBPP;
	int numTextures;

	std::string newTexName;
	
};

#endif