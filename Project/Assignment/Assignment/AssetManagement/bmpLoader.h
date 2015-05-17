
#ifndef BMPLOADER_H
#define BMPLOADER_H

#include "ResourceLoader.h"
#include "GameAsset.h"

class bmpLoader : public ResourceLoader//, public image 
{
public:

	virtual GameAsset* Create(char* filePath);

	virtual const char* GetExtension();

};

#endif