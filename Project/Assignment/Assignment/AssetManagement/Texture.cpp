
#include "Texture.h"

Texture::Texture() :
	GameAsset(),
	m_textureID(0),
	m_imageData(nullptr),
	m_width(0),
	m_height(0), 
	m_BPP(0)
{
}

Texture::Texture(char* name, unsigned char* data, int width, 
	int height, unsigned int BPP) :
	GameAsset((std::string)name),
	m_textureID(0), 
	m_imageData(data),
	m_width(width),
	m_height(height),
	m_BPP(BPP)
{
}

//Texture::Texture(char* name, unsigned int texID) : 
//	GameAsset(name), 
//	//m_image(rawImage),
//	m_textureID(texID)
//{
//}

Texture::~Texture()
{
	if(m_imageData) {
		//delete[] m_imageData;
		delete m_imageData;
		m_imageData = nullptr;
	}
}

bool Texture::SetData(unsigned char* data)
{
	if(data) {
		m_imageData = data;
		return true;
	}
	return false;
}

bool Texture::SetWidth(int width)
{
	if(width > 0) {
		width = m_width;
		return true;
	}
	return false;
}

bool Texture::SetHeight(int height)
{
	if(height > 0) {
		height = m_height;
		return true;
	}
	return false;
}

bool Texture::SetBPP(unsigned int BPP)
{
	if(BPP > 0) {
		m_BPP = BPP;
		return true;
	}
	return false;
}

//
//bool Texture::SetImage(image* rawImage)
//{
//	if(rawImage) {
//		if(m_image)
//			m_image = nullptr;
//
//		m_image = rawImage;
//
//		return true;
//	}
//
//	return false;
//}

bool Texture::SetTexID(unsigned int texture)
{
	if(texture) {
		m_textureID = texture;
		return true;
	}
	return false;
}

Texture* Texture::GetTexture()
{
	return this;
}

unsigned int Texture::GetTexID()
{
	return m_textureID;
}

void Texture::Unload()
{
	delete[] m_imageData;
	m_imageData = nullptr;
	m_textureID = 0;
	m_width = 0;
	m_height = 0;
	m_BPP = 0;
}

unsigned char* Texture::GetData()
{
	return m_imageData;
}

int Texture::GetWidth()
{
	return m_width;
}

int Texture::GetHeight()
{
	return m_height;
}

unsigned int Texture::GetBPP()
{
	return m_BPP;
}

RGB<unsigned char> Texture::GetColor(int x,int y)
{
	RGB<unsigned char> color={0,0,0};
	return color;
}