
#ifndef TGA_H
#define TGA_H

#include "Texture.h"

class tga : public Texture
{
public:

	tga(char* name, unsigned char* data, int width, 
		int height, unsigned int BPP);

	~tga();

	unsigned char* GetData();

	int GetWidth();

	int GetHeight();

	unsigned int GetBPP();

	RGB<unsigned char> GetColor(int x,int y);

private:

};

#endif