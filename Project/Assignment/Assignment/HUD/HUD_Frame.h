#ifndef HUD_FRAME_H
#define HUD_FRAME_H


#include"HUD_Picture.h"
#include"HUD_Shape.h"
#include"HUD_Text.h"

#include<string>
#include<map>

class HUD_Frame
{
public:
	HUD_Frame();

	void CreateShape(std::string name, 
					float x, float y, float w, float h,
					float r, float g, float b);
	void CreatePicture(std::string name, 
						float x, float y, float w, float h,
						unsigned int texture);
	void CreateText(std::string name,
					float x, float y, float w, float h,
					float r, float g, float b,
					std::string text);

	HUD_Element* getElement(std::string name);

	int getElementCount() {return elements;};

	void Render();

private:
	int elements;
	typedef std::map<std::string, HUD_Element*> HUD_Elements;
	typedef HUD_Elements::iterator ElementIter;

	HUD_Elements m_HUD;
};

#endif