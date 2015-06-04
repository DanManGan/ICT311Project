#ifndef HUD_PICTURE_H
#define HUD_PICTURE_H

#include"HUD_Element.h"
#include"../AssetManagement/Texture.h"

class HUD_Picture : public HUD_Element
{
public:
	HUD_Picture();
	HUD_Picture(float x, float y, float w, float h, unsigned int tex);

	unsigned int GetTexture();
	void SetTexture(unsigned int tex);

	CLASS_TYPE(HUD_PICTURE);

	void Render();

private:
	unsigned int texture;
};

#endif