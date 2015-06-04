#include"HUD_Shape.h"
#include <gl\glut.h>
#include <GL/glfw.h>


HUD_Shape::HUD_Shape()
{
	color.r = 0.0f;
	color.g = 0.0f;
	color.b = 0.0f;
}

HUD_Shape::HUD_Shape(float x, float y, float w, float h,float r, float g, float b)
{
	HUD_Element(x, y, w, h);
	color.r = r;
	color.g = g;
	color.b = b;
}

//--------------------------------------------------------------------------------------

void HUD_Shape::SetColor(float r, float g, float b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

//--------------------------------------------------------------------------------------

void HUD_Shape::Render()
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_QUADS);
	glVertex2f(xPos+width, yPos+height);
	glVertex2f(xPos, yPos+height);
	glVertex2f(xPos, yPos);
	glVertex2f(xPos+width, yPos);
	glEnd();
}

