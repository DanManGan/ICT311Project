#ifndef HUD_SHAPE_H
#define HUD_SHAPE_H

#include"HUD_Element.h"

class HUD_Shape : public HUD_Element
{
public:
	HUD_Shape();
	HUD_Shape(float x, float y, float w, float h, float r, float g, float b);

	void SetColor(float r, float g, float b);

	CLASS_TYPE(HUD_SHAPE);

	void Render();

private:
	struct RGB
	{
		float r;
		float g;
		float b;
	};

	RGB color;
};

#endif