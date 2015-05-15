
#include "Texture.h"

Texture::Texture() :
	m_texture(0),
	m_image(nullptr)
{
}

//Texture::Texture(char* filePath)
//{
//	m_texture = m_textureManager.loadTexture(filePath);
//}

Texture::Texture(image* rawImage)
{
	m_image = rawImage;
}

Texture::~Texture()
{
}

//void Texture::Load(char* filePath)
//{
//	m_texture = m_textureManager.loadTexture(filePath);
//}

void Texture::SetTexture(unsigned int texture)
{
	m_texture = texture;
}

unsigned int Texture::Get()
{
	return m_texture;
}