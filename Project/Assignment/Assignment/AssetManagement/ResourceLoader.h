
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include "GameAsset.h"

class ResourceLoader
{
public:
    //virtual GameAsset * Create (FILE * fin) = 0;
	virtual GameAsset* Create(char* filePath) = 0;

    virtual const char * GetExtension () = 0;

	bool ValidFile(char* filePath);
};

#endif: