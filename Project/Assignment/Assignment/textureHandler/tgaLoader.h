
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#ifndef __TGALOADER_H
#define __TGALOADER_H

#if _MCS_VER >= 1020
  #pragma once
#endif
 #pragma comment(lib,"glfw.lib")

#include "image.h"
#include <gl/glfw.h>

class tgaLoader:public image
{
 private:
    GLFWimage* iData;
    unsigned char* imageData;
    int width;
    int height;
	unsigned int BPP;
         

public:
	tgaLoader();
	~tgaLoader();
	bool load(char *filename);
	unsigned char* getData(){return imageData;}
	int getWidth();
	int getHeight();
	void unload(){}
	unsigned int getBPP();
	RGB<unsigned char> getColor(int x,int y);
};

#endif