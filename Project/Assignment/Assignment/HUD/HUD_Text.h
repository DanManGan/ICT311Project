#ifndef HUD_TEXT_H
#define HUD_TEXT_H

#include"HUD_Element.h"

#include<string>

class HUD_Text : public HUD_Element
{
public:
	HUD_Text();
	HUD_Text(float x, float y, float w, float h,
		float r, float g, float b,
		std::string t);

	std::string GetText();
	void SetText(std::string t);

	void SetColor(float r, float g, float b);

	CLASS_TYPE(HUD_TEXT);

	void Render();
private:
	std::string text;

	struct RGB
	{
		float r;
		float g;
		float b;
	};

	RGB color;
};

#endif