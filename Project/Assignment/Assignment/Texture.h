
#ifndef TEXTURE_H
#define TEXTURE_H

#include "GameAsset.h"
#include "textureHandler/image.h"

#include <string>



class Texture : public GameAsset
{
public:

	
	Texture();
	
	Texture(image* rawImage);

	//Texture(char* filePath);

	~Texture();

	//void Load(char* filePath);

	void SetTexture(unsigned int texture);

	unsigned int Get();

	image* GetImage();

protected:

	unsigned int m_texture;
	image* m_image;

private:
	
};

#endif