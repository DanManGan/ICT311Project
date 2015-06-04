#ifndef HUD_ELEMENT_H
#define HUD_ELEMENT_H

class HUD_Element
{
public:
	HUD_Element();
	HUD_Element(float x, float y, float w, float h);

	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();

	void SetX(float x);
	void SetY(float y);
	void SetWidth(float w);
	void SetHeight(float h);

protected:
	float xPos;
	float yPos;

	float width;
	float height;
};

#endif