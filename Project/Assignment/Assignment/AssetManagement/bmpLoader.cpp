
#pragma comment( lib, "glaux.lib" )

#include "bmpLoader.h"
#include "bmp.h"


#include <fstream>
#include <gl/glaux.h>

GameAsset* bmpLoader::Create(char* filePath) 
{
	if(!ValidFile(filePath))
		return nullptr;

	AUX_RGBImageRec* TextureImage = auxDIBImageLoad(filePath);       // Load The Bitmap And Return A Pointer
	int width = TextureImage->sizeX;
	int height = TextureImage->sizeY;
	unsigned char* imageData = TextureImage->data;

	free(TextureImage);

	return new bmp(filePath, imageData, width, height);
}

const char* bmpLoader::GetExtension () 
{ 
	return ".bmp"; 
}