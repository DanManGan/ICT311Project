
#include "Texture.h"

Texture::Texture() :
	m_texture(0)
{
}

//Texture::Texture(char* filePath)
//{
//	m_texture = m_textureManager.loadTexture(filePath);
//}

Texture::Texture(unsigned int textureID)
{
	m_texture = textureID;
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