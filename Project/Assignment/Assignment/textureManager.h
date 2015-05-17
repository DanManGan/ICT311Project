
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#ifndef __TEXTUREMANAGER_H
#define __TEXTUREMANAGER_H

#if _MCS_VER >= 1020
  #pragma once
#endif

#include <vector>
#include <string>
#include <iostream>
using namespace std;

//#include "pcx.h"
//#include "image.h"
//#include "bmpLoader.h"
//#include "tgaLoader.h"
#include <gl/glut.h>

class textureManager
{
private:
	GLuint numTextures;
public:
	textureManager();
	bool setActiveTexture(GLuint texID);
	GLuint loadTexture(char* filename);
//	image* loadTextureRaw(char* filename);
	GLuint loadTextureMipmapClamp(char* filename);
	unsigned int getBPP();
	GLuint createNewTexture(unsigned char* tex,int width,int height);
};

#endif