#ifndef WATER_H
#define WATER_H

#include "..\Extras\MathExtra.h"


#define WATER_RESOLUTION 60

class Water {
private:
	Vector3D m_VertArray[SQR(WATER_RESOLUTION)];
	Vector3D m_NormalArray[SQR(WATER_RESOLUTION)];
	float m_ForceArray[SQR(WATER_RESOLUTION)];
	float m_VelArray[SQR(WATER_RESOLUTION)];
	int m_PolyIndexArray[SQR((WATER_RESOLUTION-1))*6];

	//Water surface geometry
	int m_NumVertices;
	int m_NumIndices;

	float m_WorldSize;

	Vector3D m_VecColour;
	float m_Transparency;

	unsigned int m_RefMapID;

public:
	void Init(float worldSize);

	void Update(float delta);
	void CalcNormals();
	void Render(bool useCVA);

	bool LoadReflectionMap(char* fileName);


	inline void SetColour(float red, float green, float blue, float alpha) {
		m_VecColour.Set(red, green, blue);
		m_Transparency = alpha;
	}

	inline int GetNumVertices() {
		return m_NumVertices;
	}

	inline int GetNumTriangles() {
		return m_NumVertices*3;
	}

	Water() : m_VecColour(1.0f, 1.0f, 1.0f), m_Transparency(1.0f)
	{ }

	~Water()
	{ }
};

#endif