
#ifndef TEXTURE_H
#define TEXTURE_H

#include "GameAsset.h"

#include <string>



class Texture : public GameAsset
{
public:

	
	Texture();

	Texture(unsigned int textureID);

	//Texture(char* filePath);

	~Texture();

	//void Load(char* filePath);

	void SetTexture(unsigned int texture);

	unsigned int Get();

protected:
	unsigned int m_texture;


private:
	
};

#endif