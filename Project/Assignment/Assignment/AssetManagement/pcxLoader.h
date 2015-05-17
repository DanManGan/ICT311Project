
#ifndef PCXLOADER_H
#define PCXLOADER_H

#include "ResourceLoader.h"
#include "GameAsset.h"

class pcxLoader : public ResourceLoader
{
public:

	virtual GameAsset* Create(char* filePath);

	virtual const char* GetExtension();

private:
	bool TexMapScalePow2(unsigned char* data, int& width, int& height);
	
};

#endif