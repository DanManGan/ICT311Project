
#ifndef TGALOADER_H
#define TGALOADER_H

#include "ResourceLoader.h"
#include "GameAsset.h"

class tgaLoader : public ResourceLoader
{
public:

	virtual GameAsset* Create(char* filePath);

	virtual const char* GetExtension();

};

#endif