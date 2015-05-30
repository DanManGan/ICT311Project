#include "Skybox.h"
#include "ViewOpenGL.h"
#include <gl\glext.h>
#include "..\Singletons.h"

bool Skybox::LoadTexture(int size, char* filename) {
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	if(!graphics->SetupTextureClamp(assetManager->GetAsset(filename)))
		return false;

	m_textureIDs[size] = graphics->SetupTextureClamp(assetManager->GetAsset(filename));
	return true;
}

void Skybox::Render() {
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
		glTranslatef(m_vecCenter.x, m_vecCenter.y, m_vecCenter.z);

		//front face
		glBindTexture(GL_TEXTURE_2D, m_textureIDs[SB_FRONT]);
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMax.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMin.z);
		glEnd();

		//back face
		glBindTexture(GL_TEXTURE_2D, m_textureIDs[SB_BACK]);
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMin.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMin.z);
		glEnd();

		//right face
		glBindTexture(GL_TEXTURE_2D, m_textureIDs[SB_RIGHT]);
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMin.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMax.z);
		glEnd();

		//left face
		glBindTexture(GL_TEXTURE_2D, m_textureIDs[SB_LEFT]);
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMax.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMin.z);
		glEnd();

		//top face
		glBindTexture(GL_TEXTURE_2D, m_textureIDs[SB_TOP]);
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMax.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMin.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMin.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMax.y, m_vecMax.z);
		glEnd();

		//bottom face
		glBindTexture(GL_TEXTURE_2D, m_textureIDs[SB_BOTTOM]);
		glBegin(GL_TRIANGLE_FAN);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMin.z);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(m_vecMin.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMax.z);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMax.x, m_vecMin.y, m_vecMin.z);
		glEnd();
	glPopMatrix();
}