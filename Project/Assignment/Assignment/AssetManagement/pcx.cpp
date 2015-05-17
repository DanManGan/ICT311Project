
#include "pcx.h"

pcx::pcx(char* name, unsigned char* data, int width, int height) :
	Texture(name, data, width, height, 24)
{	
}

pcx::~pcx()
{
}

unsigned char* pcx::GetData()
{
	return m_imageData;
}

int pcx::GetWidth()
{
	return m_width;
}

int pcx::GetHeight()
{
	return m_height;
}

unsigned int pcx::GetBPP()
{
  return m_BPP;
}

RGB<unsigned char> pcx::GetColor(int x,int y)
{
	RGB<unsigned char> color={0,0,0};
	return color;
}


