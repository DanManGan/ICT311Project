#include "Skybox.h"
#include "ViewOpenGL.h"
#include <gl/glut.h>
#include "..\Singletons.h"

#define GL_CLAMP_TO_EDGE 0x812F

bool Skybox::LoadTexture(int size, char* filename) {
	// This is done in graphics->SetupTextureClamp
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// need to add image to game assets
	assetManager->Load(filename);

	// this will load set the texture twice in OpenGL
	//if(!graphics->SetupTextureClamp(assetManager->GetAsset(filename)))
	//	return false;

	//m_textureIDs[size] = graphics->SetupTextureClamp(assetManager->GetAsset(filename));


	// I think this is a better way to do it
	// setup the texture in OpenGL with clamped edges and set to temp var for testing
	unsigned int tex = graphics->SetupTextureClamp(assetManager->GetAsset(filename));
	
	if(!tex)
		return false;

	// then add it to the texture array NOTE: should 'size' be 'side'???
	m_textureIDs[size] = tex;

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
			glTexCoord2f(0.0f, 1.0f); glVertex3f(m_vecMin.x, m_vecMax.y, m_vecMax.z);
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