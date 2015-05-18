
#ifndef BMP_H
#define BMP_H

#include "Texture.h"

class bmp : public Texture
{
public:

	bmp(char* name, unsigned char* data, int width, int height);

	~bmp();
	
	//unsigned char* GetData();

	//int GetWidth();

	//int GetHeight();

	unsigned int GetBPP();

	RGB<unsigned char> GetColor(int x,int y);

private:

};

#endif