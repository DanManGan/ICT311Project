
#ifndef OBJLOADER_H
#define OBJLOADER_H


#include "ResourceLoader.h"
#include "GameAsset.h"

class objLoader : public ResourceLoader
{
public:


   /*****************************************************************************
   *Purpose: Loads an obj model from file
   *Pre : filename is an assigned value
   *Post: model is loaded
   *returns: true if model loaded, otherwise false
   *Vars: filename - the filename containing the MD2 model
   *****************************************************************************/
	GameAsset* Create(char* filePath);

    const char * GetExtension();

private:
	unsigned int LoadTexWrap(const char * filename);

};

#endif