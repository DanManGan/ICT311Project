

#include "ScreenText.h"
#include <iostream>

ScreenText::ScreenText()
{
	m_printLargeCentred = false;
	m_printMediumTopLeft = false;
}

//--------------------------------------------------------------------------------------

void ScreenText::Render()
{
	// sets up a 2d ortho viewing area on the screen for text to be written to
	glDisable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, m_winWidth, 0.0, m_winHeight);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();
			
			if(m_printLargeCentred) PrintLargeCentredText();
			if(m_printMediumTopLeft) PrintMediumTopLeftText();
			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
}

//--------------------------------------------------------------------------------------

void ScreenText::SetLargeCenteredText(deque<string> &strings)
{
	m_largeCentredText.clear();
	m_largeCentredText = strings;
}

//--------------------------------------------------------------------------------------

void ScreenText::SetLargeCentredOn(bool state)
{
	m_printLargeCentred = state;
}

//--------------------------------------------------------------------------------------

void ScreenText::PrintLargeCentredText()
{
	GLuint linesUp = m_largeCentredText.size() / 2;
	GLint xpos = (GLint)m_winWidth / 2;
	GLint ypos = (GLint)((m_winHeight / 2) + (linesUp * 30));
	deque<string>::iterator strIterator;

	glColor3f(1.0, 0.0, 0.0); // set text to red
	for (strIterator = m_largeCentredText.begin(); 
			strIterator != m_largeCentredText.end(); strIterator++)
	{
		xpos -= ((strIterator->length()/2) * 10);
		glRasterPos2i(xpos, ypos);
		PrintCharsToScreen(GLUT_BITMAP_TIMES_ROMAN_24, strIterator->c_str());
		ypos -=30;
		xpos = (GLint)(m_winWidth / 2);
	}
}

//--------------------------------------------------------------------------------------

void ScreenText::SetMediumTopLeftText(deque<string> &strings)
{
	m_mediumTopLeftText.clear();
	m_mediumTopLeftText = strings;
}

//--------------------------------------------------------------------------------------

void ScreenText::SetMediumTopLeftOn(bool state)
{
	m_printMediumTopLeft = state;
}

//--------------------------------------------------------------------------------------

void ScreenText::PrintMediumTopLeftText()
{
	GLint xpos = 100;
	GLint ypos = (GLint)m_winHeight - 50;
	deque<string>::iterator strIterator;

	glColor3f(1.0, 0.0, 0.0); // set text to red
	for (strIterator = m_mediumTopLeftText.begin(); 
			strIterator != m_mediumTopLeftText.end(); strIterator++)
	{
		glRasterPos2i(xpos, ypos);
		PrintCharsToScreen(GLUT_BITMAP_HELVETICA_18, strIterator->c_str());
		ypos -=25;
	}
}

//--------------------------------------------------------------------------------------

void ScreenText::PrintCharsToScreen(void *font,const char *str)
{  
	const char *c;

	for (c = str; *c != '\0'; c++) // iterate through & print
		glutBitmapCharacter(font, *c);
}

//--------------------------------------------------------------------------------------

void ScreenText::SetScreenSize(GLfloat width, GLfloat height)
{
	m_winWidth = width;
	m_winHeight = height;
}