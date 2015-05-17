
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
private:
	Texture* tex[4];   //textures 0-3, 4 in total
	unsigned char* newTex;
	int newTexWidth;
	int newTexHeight;
	int newTexBPP;
	int numTextures;
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
};

#endif