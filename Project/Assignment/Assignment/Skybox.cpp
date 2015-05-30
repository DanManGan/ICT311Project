#include "Skybox.h"
#include "Graphics\ViewOpenGL.h"
#include <gl\glext.h>

bool Skybox::LoadTexture(int size, char* filename) {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//if(!m_textures[size].Load())
		//return false;

	return true;
}

void Skybox::Render() {
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
		glTranslatef(m_vecCenter.x, m_vecCenter.y, m_vecCenter.z);

		//front face
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMax.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMin.z);
		glEnd();

		//back face
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMin.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMin.z);
		glEnd();

		//right face
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMin.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMax.z);
		glEnd();

		//left face
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMax.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMin.z);
		glEnd();

		//top face
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMax.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMin.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMin.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMax.z);
		glEnd();

		//bottom face
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMin.z);
		glEnd();
	glPopMatrix();
}