
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#include "textureManager.h"
#include "imageFactory.h"
#define GL_CLAMP_TO_EDGE 0x812F


textureManager::textureManager()
{
	numTextures=0;
}

bool textureManager::setActiveTexture(GLuint texID)
{
//	cout<<"texid from array "<<tex[texID]<<endl;
 glEnable(GL_TEXTURE_2D);
 glBindTexture(GL_TEXTURE_2D,texID);
 return true;
}


image* textureManager::loadTextureRaw(char* filename)
{
 imageFactory imageLoader;
 image* texture=imageLoader.create(filename);
     if(!texture)
	 {
		 cout<<"texture load error"<<endl;
		 return NULL;
	 }
     if(!texture->load(filename))
     {
	   cout<<"error in tm loadtmmc"<<endl;
	   return NULL;
     }
 return texture;
}

GLuint textureManager::loadTexture(char* filename)
{
 image* texture=loadTextureRaw(filename);
        if(!texture)
		  return -1;
numTextures++;

	  //unsigned int texID;
	  	glEnable(GL_TEXTURE_2D);
   // glGenTextures(1, &texID);
		 glGenTextures(1, &numTextures);

glBindTexture(GL_TEXTURE_2D, numTextures); 
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); 
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR ); 
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,texture->getWidth(),texture->getHeight(),0,GL_RGB,GL_UNSIGNED_BYTE,texture->getData());
	glBindTexture(GL_TEXTURE_2D, numTextures); 
	delete texture;
	texture=NULL;
	return numTextures;
}


GLuint textureManager::createNewTexture(unsigned char* tex,int width,int height)
{
numTextures++;
 glGenTextures( 1, &numTextures);
 glEnable( GL_TEXTURE_2D );
  glBindTexture( GL_TEXTURE_2D, numTextures);



 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );		
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
//   int iType=texture.GetBPP();
  //				if( iType==24 )
int					iType= GL_RGB;
	//			else
//	int				iType= GL_RGBA;
			//create a mipmapped texture
	
			//gluBuild2DMipmaps( GL_TEXTURE_2D, iType, texture.GetWidth(), texture.GetHeight(), iType, GL_UNSIGNED_BYTE, texture.GetData() );
				gluBuild2DMipmaps( GL_TEXTURE_2D, iType, width, height, iType, GL_UNSIGNED_BYTE, tex );
			//textureSet=true;
glBindTexture( GL_TEXTURE_2D, numTextures);

	return numTextures;
}


GLuint textureManager::loadTextureMipmapClamp(char* filename)
{
 imageFactory imageLoader;
 image *texture=imageLoader.create(filename);
     if(!texture)
	 {
		 cout<<"texture load error"<<endl;
		 return -1;
	 }
   
   if(!texture->load(filename))
   {
	   cout<<"error in tm loadtmmc"<<endl;
	   return -1;
   }
 //build the texture for use with OpenGL

 

numTextures++;
 glGenTextures( 1, &numTextures);
 glEnable( GL_TEXTURE_2D );
  glBindTexture( GL_TEXTURE_2D, numTextures);



 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );		
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
//   int iType=texture.GetBPP();
  //				if( iType==24 )
int					iType= GL_RGB;
	//			else
//	int				iType= GL_RGBA;
			//create a mipmapped texture
	
			//gluBuild2DMipmaps( GL_TEXTURE_2D, iType, texture.GetWidth(), texture.GetHeight(), iType, GL_UNSIGNED_BYTE, texture.GetData() );
				gluBuild2DMipmaps( GL_TEXTURE_2D, iType, texture->getWidth(), texture->getHeight(), iType, GL_UNSIGNED_BYTE, texture->getData() );
			//textureSet=true;
glBindTexture( GL_TEXTURE_2D, numTextures);
    delete texture;
	return numTextures;
}
