
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#ifndef __BMPLOADER_H
#define __BMPLOADER_H

#if _MCS_VER >= 1020
  #pragma once
#endif


#include "image.h"
#include <gl/glaux.h>

class bmpLoader:public image
{
private:
   AUX_RGBImageRec *TextureImage;  // Create Storage Space For The Texture
   unsigned char* imageData;
   int width;
   int height;
         

public:
bmpLoader();
~bmpLoader();
bool load(char *filename);
//unsigned char* getData(){return TextureImage->data;}
unsigned char* getData(){return imageData;}
void unload(){}
//int getWidth(){return TextureImage->sizeX;}
int getWidth(){return width;}
//int getHeight(){return TextureImage->sizeY;}
int getHeight(){return height;}
unsigned int getBPP();
RGB<unsigned char> getColor(int x,int y){RGB<unsigned char> ret={0,0,0};return ret;}
};

#endif