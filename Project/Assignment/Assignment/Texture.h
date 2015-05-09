
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Asset.h"

template <class T>
struct RGB
{
	T r;
	T g;
	T b;
	void set(RGB<T> rgb){r=rgb.r;g=rgb.g;b=rgb.b;}
    void reset(){r=0;g=0;b=0;}
};

class Texture : public Asset
{
public:
	virtual bool load(char *filename)=0;
	virtual unsigned char* getData()=0;
	virtual int getWidth()=0;
	virtual int getHeight()=0;
	virtual void unload()=0;
	virtual unsigned int getBPP()=0;
	virtual RGB<unsigned char> getColor(int x,int y)=0;
};

#endif