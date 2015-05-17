
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
	//if(m_image)
	//	m_image = nullptr;
	delete[] m_imageData;
	m_imageData = nullptr;
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

Texture* Texture::GetImage()
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