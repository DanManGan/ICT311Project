
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#pragma comment( lib, "glaux.lib" )

#include "bmpLoader.h"
#include <fstream>
using namespace std;
#include <gl/glaux.h>

bmpLoader::bmpLoader()
{
 TextureImage=NULL;
 imageData=NULL;
}

//checks if file exists.
bool validFile(char *filename)
{

 fstream testExists(filename);
   if(testExists.is_open())
   {
	   testExists.close();
	   return true;
   }
	return false;
}

bmpLoader::~bmpLoader()
{
 delete[] imageData;
}

bool bmpLoader::load(char *filename) 
{
	if(!validFile(filename))
		return false;
  TextureImage=auxDIBImageLoad(filename);       // Load The Bitmap And Return A Pointer
  width=TextureImage->sizeX;
  height=TextureImage->sizeY;
  imageData=TextureImage->data;
  free(TextureImage);
  return true;
}

unsigned int bmpLoader::getBPP()
{
  return 24;
}

