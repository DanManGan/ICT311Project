/******************************************************************************
* fileName: md2Loader.h
* Author  : David Bennett
* Legal   : use it, dont, whatever. Just dont bitch at me.
* Date    : 17/03/2005
* Purpose : class for reading in a quake md2 model
*         : contains opengl code. Replace with functions from your own graphics
*           engine.
******************************************************************************/
#ifndef MD2LOADER_H
#define MD2LOADER_H


#include "md2.h"
#include "../Extras/Vector3D.h"
#include "ResourceLoader.h"
#include "GameAsset.h"


class md2Loader : public ResourceLoader
 {

public:


   /*****************************************************************************
   *Purpose: Loads an MD2 model from file
   *Pre : filename is an assigned value
   *Post: model is loaded
   *returns: true if model loaded, otherwise false
   *Vars: filename - the filename containing the MD2 model
   *****************************************************************************/
	GameAsset* Create(char* filePath);

    const char * GetExtension();


private:

 
   struct frame* readFrames(md2Header* head, char* buf);
   struct triangle* readTriangles(md2Header* head, char* buf);
 struct   texCoord* readTextures(md2Header* head, char* buf);
     bool validFile(md2Header* head);

  };

#endif