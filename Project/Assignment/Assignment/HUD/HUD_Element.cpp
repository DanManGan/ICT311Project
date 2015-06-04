#include"HUD_Element.h"

HUD_Element::HUD_Element()
{
	xPos = 0.0f;
	yPos = 0.0f;
	width = 0.0f;
	height = 0.0f;
}

HUD_Element::HUD_Element(float x, float y, float w, float h)
{
	xPos = x;
	yPos = y;
	width = w;
	height = h;
}

//--------------------------------------------------------------------------------------

float HUD_Element::GetX()
{
	return xPos;
}

//--------------------------------------------------------------------------------------

float HUD_Element::GetY()
{
	return yPos;
}

//--------------------------------------------------------------------------------------

float HUD_Element::GetWidth()
{
	return width;
}

//--------------------------------------------------------------------------------------

float HUD_Element::GetHeight()
{
	return height;
}

//--------------------------------------------------------------------------------------

void HUD_Element::SetX(float x)
{
	xPos = x;
}

//--------------------------------------------------------------------------------------

void HUD_Element::SetY(float y)
{
	yPos = y;
}

//--------------------------------------------------------------------------------------

void HUD_Element::SetWidth(float w)
{
	width = w;
}

//--------------------------------------------------------------------------------------

void HUD_Element::SetHeight(float h)
{
	height = h;
}