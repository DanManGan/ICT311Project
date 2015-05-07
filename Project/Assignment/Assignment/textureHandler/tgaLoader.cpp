
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#include "tgaLoader.h"
#include <memory.h>
#include <iostream>
using namespace std;


tgaLoader::tgaLoader()
{ 
 iData=NULL;
 imageData=NULL;
}

tgaLoader::~tgaLoader()
{ 
	if(iData)
		glfwFreeImage(iData);	
}

bool tgaLoader::load(char *filename)
{
 iData=new GLFWimage();
  	  if(glfwReadImage(filename, iData, GL_RGB )==GL_FALSE)
	  {
		  std::cout << "glfwReadImage Failed: " << filename << std::endl;
		iData=NULL;
		return false;
	  }   
	  height=iData->Height;
   width=iData->Width;
   BPP=iData->BytesPerPixel;
   //point imageData to iData 
   imageData=iData->Data;
 return true;
}

int tgaLoader::getHeight()
{
	return iData->Height;
}

int tgaLoader::getWidth()
{
	return iData->Width;
}

unsigned int tgaLoader::getBPP()
{
	return iData->BytesPerPixel*8;
}

RGB<unsigned char> tgaLoader::getColor(int x,int y)
{
	RGB<unsigned char> color={0,0,0};

		if( ( x<getWidth() ) && ( y<getHeight() ) )
		{
			color.r  = imageData[( ( y*height )+x )*BPP];
			color.g= imageData[( ( y*height )+x )*BPP+1];
			color.b = imageData[( ( y*height )+x )*BPP+2];
		}
 return color;
}