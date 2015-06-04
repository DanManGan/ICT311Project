#ifndef HUD_PICTURE_H
#define HUD_PICTURE_H

#include"HUD_Element.h"
#include"../AssetManagement/Texture.h"

class HUD_Picture : public HUD_Element
{
public:
	HUD_Picture();

	unsigned int GetTexture();
	void SetTexture(unsigned int tex);

	void Render();

private:
	unsigned int texture;
};

#endif