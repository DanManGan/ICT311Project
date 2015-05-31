#ifndef SKYBOX_H
#define SKYBOX_H

#include "..\Extras\MathExtra.h"
#include "..\Extras\Vector3D.h"
#include "..\AssetManagement\GameAsset.h"
#include "..\AssetManagement\Texture.h"
#include "..\Graphics\ViewOpenGL.h"

#define SB_NUMSIDES 6

#define SB_FRONT	0
#define SB_BACK		1
#define SB_RIGHT	2
#define SB_LEFT		3
#define SB_TOP		4
#define SB_BOTTOM	5

class Skybox {
private:
	Vector3D m_vecMin, m_vecMax, m_vecCenter;
	
	unsigned int m_textureIDs[SB_NUMSIDES];
	
public:
	bool LoadTexture(int side, char* filename);
	void Render();

	void Set(float cx, float cy, float cz, float size) {
		float halfSize = size/2;

		m_vecCenter.Set(cx, cy, cz);

		m_vecMin.Set(-halfSize, -halfSize, -halfSize);
		m_vecMax.Set(halfSize, halfSize, halfSize);
	}

	Skybox()
	{	}
	~Skybox()
	{	}
};

#endif
