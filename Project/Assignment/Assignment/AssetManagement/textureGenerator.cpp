
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

#include "textureGenerator.h"
#include <iostream>
#include "../Singletons.h"
using namespace std;
//#include <gl/glut.h>

textureGenerator::textureGenerator()
{
	for(int i=0;i<4;i++)
		tex[i]=NULL;
	numTextures=0;
	newTex=NULL;
	newTexWidth=0;
	newTexHeight=0;
	newTexBPP=3;  //24 bit
}

textureGenerator::~textureGenerator()
{
	delete newTex;
	  for(int i=0;i<4;i++)
		delete tex[i];
}


//bool textureGenerator::addTexture(char* filename)
//{
//      if(numTextures<4)
//	  { 
//		numTextures++;
//		  if(tex[numTextures-1]=texManager->loadTextureRaw(filename))
//		 	return true;
//		  else
//		    numTextures--;
//	  }
// return false;
//}

bool textureGenerator::addTexture(Texture* texture)
{
      if(numTextures < 4 && texture)
	  { 
		numTextures++;
		  if(tex[numTextures-1]=texture)
		 	return true;
		  else
		    numTextures--;
	  }
 return false;
}

int textureGenerator::getNumTextures()
{
	return numTextures;
}

bool textureGenerator::isLoaded(int index)
{
	if(index<4 && index >-1)
	  return (tex[index]!=NULL);
 return false;
}

RGB<unsigned char> textureGenerator::getColor(int texNum,int x, int y)
{
	RGB<unsigned char> val={0,0,0};
	if(texNum>3 || texNum<0)
		return val;
 return tex[texNum]->GetColor(x,y);
}

void textureGenerator::setColor( int x, int y, RGB<unsigned char> color)
{
		if( ( x<newTexWidth ) && ( y<newTexHeight ) )
		{
			newTex[( ( y*newTexHeight )+x )*newTexBPP]  = color.r;
			newTex[( ( y*newTexHeight )+x )*newTexBPP+1]= color.g;
			newTex[( ( y*newTexHeight )+x )*newTexBPP+2]= color.b;
		}
}

bool textureGenerator::setupNewTexture(int width, int height)
{
	//to add - ensure power of 2
	newTexHeight=height;
	newTexWidth=width;
	newTex=new unsigned char[newTexHeight*newTexWidth*newTexBPP];
	  if(!newTex)
		  return false;
 return true;
}

float textureGenerator::getRange()
{
	  if(numTextures>0)
		  return 255.0f/(float)numTextures;
	return 0.0f;
}

float textureGenerator::getTextureMax(int texNum)
{
	  if(texNum>numTextures-1)
		  return 0.0f;
	  else
		  return((255.0f/(float)numTextures)*(texNum+1));
}

unsigned int textureGenerator::getTexWidth(int texNo)
{
     if(texNo>0 && texNo <numTextures)
		 return tex[texNo]->GetWidth();
 return -1;
}

unsigned int textureGenerator::getTexHeight(int texNo)
{
     if(texNo>0 && texNo <numTextures)
		 return tex[texNo]->GetHeight();
 return -1;
}