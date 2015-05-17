
#include "tga.h"

tga::tga(char* name, unsigned char* data, int width, 
	int height, unsigned int BPP) :
	Texture(name, data, width, height, BPP)
{
}

tga::~tga()
{ 	
}

unsigned char* tga::GetData()
{
	return m_imageData;
}

int tga::GetHeight()
{
	return m_height;
}

int tga::GetWidth()
{
	return m_width;
}

unsigned int tga::GetBPP()
{
	return m_BPP;
}

RGB<unsigned char> tga::GetColor(int x,int y)
{
	RGB<unsigned char> color={0,0,0};

	if((x < GetWidth()) && (y < GetHeight())) {
		color.r  = m_imageData[( ( y*m_height )+x )*m_BPP];
		color.g= m_imageData[( ( y*m_height )+x )*m_BPP+1];
		color.b = m_imageData[( ( y*m_height )+x )*m_BPP+2];
	}
 
	return color;
}