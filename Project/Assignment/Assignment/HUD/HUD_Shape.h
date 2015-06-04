#ifndef HUD_SHAPE_H
#define HUD_SHAPE_H

#include"HUD_Element.h"

struct RGB
{
	float r;
	float g;
	float b;
};

class HUD_Shape : public HUD_Element
{
public:
	HUD_Shape();
	HUD_Shape(float r, float g, float b);

	void SetColor(float r, float g, float b);

	void Render();

private:
	RGB color; 
};

#endif