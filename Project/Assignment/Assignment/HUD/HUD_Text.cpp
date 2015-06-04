#include"HUD_Text.h"
#include <gl\glut.h>
#include <GL/glfw.h>

HUD_Text::HUD_Text()
{
	text = "";
	color.r = 0.0f;
	color.g = 0.0f;
	color.b = 0.0f;
}

HUD_Text::HUD_Text(float x, float y, float w, float h, 
					float r, float g, float b,
					std::string t)
{
	HUD_Element(x, y, w, h);
	text = t;

	color.r = r;
	color.g = g;
	color.b = b;
}

//--------------------------------------------------------------------------------------

void HUD_Text::SetColor(float r, float g, float b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

//--------------------------------------------------------------------------------------

std::string HUD_Text::GetText()
{
	return text;
}

//--------------------------------------------------------------------------------------

void HUD_Text::SetText(std::string t)
{
	text = t;
}

//--------------------------------------------------------------------------------------

void HUD_Text::Render()
{
	glTranslatef(xPos, yPos, 0.0);
	glScalef(width/100.0f, height/100.0f, 1.0f);
	for(int i = 0; i < text.length(); i++)
	{
		glColor3f(color.r, color.g, color.b);
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, text[i]);
	}
}