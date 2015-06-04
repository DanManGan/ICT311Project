#include"HUD_Picture.h"
#include"../Singletons.h"

#include "../AssetManagement/multitexture.h"
#include <gl\glut.h>
#include <GL/glfw.h>

HUD_Picture::HUD_Picture()
{
	texture = 0;
}

HUD_Picture::HUD_Picture(float x, float y, float w, float h, unsigned int tex)
{
	HUD_Element(x, y, w, h);
	texture = tex;
}

//--------------------------------------------------------------------------------------

unsigned int HUD_Picture::GetTexture()
{
	return texture;
}


//--------------------------------------------------------------------------------------

void HUD_Picture::SetTexture(unsigned int tex)
{
	texture = tex;
}

//--------------------------------------------------------------------------------------

void HUD_Picture::Render()
{
	// setup and bind texture
	glActiveTextureARB(GL_TEXTURE0_ARB );
	//bind texture 0
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture);

	glBegin(GL_QUADS);
		glMultiTexCoord2fARB( GL_TEXTURE0_ARB, 1, 1);
		glVertex2f(xPos+width, yPos+height); 
		glMultiTexCoord2fARB( GL_TEXTURE0_ARB, 0, 1);
		glVertex2f(xPos, yPos+height);
		glMultiTexCoord2fARB( GL_TEXTURE0_ARB, 0, 0);
		glVertex2f(xPos,yPos);
		glMultiTexCoord2fARB( GL_TEXTURE0_ARB, 1, 0);
		glVertex2f(xPos+width, yPos);
	glEnd();

	glActiveTextureARB( GL_TEXTURE0_ARB );
	glDisable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, 0 );
}