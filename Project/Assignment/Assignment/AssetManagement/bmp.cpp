
#include "bmp.h"

bmp::bmp(char* name, unsigned char* data, int width, int height) :
	Texture(name, data, width, height, 24)
{	
}

bmp::~bmp()
{
}
//
//unsigned char* bmp::GetData()
//{
//	return m_imageData;
//}
//
//int bmp::GetWidth()
//{
//	return m_width;
//}
//
//int bmp::GetHeight()
//{
//	return m_height;
//}
//
//unsigned int bmp::GetBPP()
//{
//  return m_BPP;
//}
//
//RGB<unsigned char> bmp::GetColor(int x,int y)
//{
//	RGB<unsigned char> color={0,0,0};
//	return color;
//}