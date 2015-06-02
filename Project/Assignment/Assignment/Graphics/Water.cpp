#include "..\Graphics\ViewOpenGL.h"
#include "..\Singletons.h"

#include "Water.h"

void Water::Init(float worldSize) {
	Vector3D dx, dy;
	int j, k, x, z, *indexPtr;

	m_WorldSize = worldSize;

	m_NumVertices = SQR(WATER_RESOLUTION);
	m_NumIndices = SQR(WATER_RESOLUTION);

	//calculate vertex location
	dx.x = m_WorldSize/(WATER_RESOLUTION-1);
	dx.y = 0.0f;
	dx.z = 0.0f/(WATER_RESOLUTION-1);

	dy.x = 0.0f/(WATER_RESOLUTION-1);
	dy.y = 0.0f;
	dy.z = m_WorldSize/(WATER_RESOLUTION-1);

	for(j=0; j<WATER_RESOLUTION; j++) {
		for(k=0; k<WATER_RESOLUTION; k++) {
			m_VertArray[(j*WATER_RESOLUTION)+k].Set(-1.0f + dx.x*k + dy.x*j,
													 0.0f + dx.y*k + dy.y*j,
													-1.0f + dx.z*k + dy.z*j);
		}
	}

	//calculate polygon indices
	x = 0;
	z = WATER_RESOLUTION;
	indexPtr = m_PolyIndexArray;
	for(j=0; j<WATER_RESOLUTION-1; j++) {
		for(k=0; k<WATER_RESOLUTION-1; k++) {
			indexPtr[0] = x;
			indexPtr[1] = x+1;
			indexPtr[2] = z;
			indexPtr[3] = z;
			indexPtr[4] = x+1;
			indexPtr[5] = z+1;

			indexPtr+= 6;
			x++;
			z++;
		}
		x++;
		z++;
	}

	//Start a water ripple at a random spot in the water field
	m_VertArray[rand()%(SQR(WATER_RESOLUTION))].y = 200.0f;
}

void Water::Update(float delta) {
	float d, temp, vert;
	int x, z;

	//calculate the currect forces acting upon the water
	for(z=1; z<WATER_RESOLUTION-1; z++) {
		for(x=2; x<WATER_RESOLUTION-1; x++) {
			//set the temp variables
			temp = m_ForceArray[(z*WATER_RESOLUTION)+x];
			vert = m_VertArray[(z*WATER_RESOLUTION)+x].y;

			//bottom
			d = vert - m_VertArray[((z-1)*WATER_RESOLUTION)+x].y;
			m_ForceArray[((z-1)*WATER_RESOLUTION)+x] += d;
			temp -= d;

			//left
			d = vert - m_VertArray[(z*WATER_RESOLUTION)+(x-1)].y;
			m_ForceArray[(z*WATER_RESOLUTION)+(x-1)] += d;
			temp -= d;

			//top
			d = (vert - m_VertArray[((z+1)*WATER_RESOLUTION)+x].y);
			m_ForceArray[((z+1)*WATER_RESOLUTION)+x] += d;
			temp -=d;

			//right
			d = (vert-m_VertArray[(z*WATER_RESOLUTION)+(x+1)].y);
			m_ForceArray[(z*WATER_RESOLUTION)+(x+1)] += d;
			temp -=d;

			//upper right
			d = (vert - m_VertArray[((z+1)*WATER_RESOLUTION)+(x+1)].y)*4.94974747f;
			m_ForceArray[((z+1)*WATER_RESOLUTION)+(x-1)] += d;
			temp -=d;

			//lower left
			d = (vert - m_VertArray[((z-1)*WATER_RESOLUTION)+(x-1)].y)*4.94974747f;
			m_ForceArray[((z-1)*WATER_RESOLUTION)+(x-1)] += d;
			temp -=d;

			//upper left
			d =(vert - m_VertArray[((z+1)*WATER_RESOLUTION)+(x-1)].y)*4.94974747f;
			m_ForceArray[((z+1)*WATER_RESOLUTION)+(x-1)] += d;
			temp -= d;

			m_ForceArray[(z*WATER_RESOLUTION)+x] = temp;
		}
	}

	//calculate velocity, and update the poly field
	for(x=0; x<m_NumVertices; x++) {
		m_VelArray[x] += (m_ForceArray[x]*delta);
		m_VertArray[x].y += m_VelArray[x];

		m_ForceArray[x] = 0.0f;
	}
}

void Water::CalcNormals() {
	Vector3D* vert, *normal;
	float temp;
	int i, j;

	for(i=0; i<WATER_RESOLUTION; i++) {
		for(j=0; j<WATER_RESOLUTION; j++) {
			vert = &m_VertArray[(i*WATER_RESOLUTION)+j];
			normal = &m_NormalArray[(i*WATER_RESOLUTION)+j];

			//calculate the normal value for the current normal
			normal->x = 0.0f;
			normal->y = 1.0f;
			normal->z = 0.0f;

			//above
			if(i != 0) {
				if(j != 0) {
					normal->x += -vert[-WATER_RESOLUTION-1].y;
					normal->z += -vert[-WATER_RESOLUTION-1].y;
				}
				else {
					normal->x += -vert[-WATER_RESOLUTION].y;
					normal->z += -vert[-WATER_RESOLUTION].y;
				}

				normal->x += -vert[-WATER_RESOLUTION].y*2.0f;

				if(j != (WATER_RESOLUTION-1)) {
					normal->x += -vert[-WATER_RESOLUTION+1].y;
					normal->z += vert[-WATER_RESOLUTION+1].y;
				}
				else {
					normal->x += -vert[-WATER_RESOLUTION].y;
					normal->z += vert[-WATER_RESOLUTION].y;
				}
			}
			else {
				normal->x += -vert[0].y;
				normal->x += -vert[0].y *2.0f;
				normal->x += -vert[0].y;

				normal->z += -vert[0].y;
				normal->z += vert[0].y;
			}

			//current line
			if(j != 0)
				normal->z += -vert[-1].y*2.0f;
			else
				normal->z += -vert[0].y*2.0f;

			if(j != (WATER_RESOLUTION-1))
				normal->z += vert[1].y*2.0f;
			else
				normal->z += vert[0].y*2.0f;

			//below
			if(i != (WATER_RESOLUTION-1)) {
				if(j != 0) {
					normal->x += vert[WATER_RESOLUTION-1].y;
					normal->z += -vert[WATER_RESOLUTION-1].y;
				}
				else {
					normal->x += vert[WATER_RESOLUTION].y;
					normal->z += -vert[WATER_RESOLUTION].y;
				}

				normal->x += vert[WATER_RESOLUTION].y*2.0f;

				if(j != WATER_RESOLUTION-1) {
					normal->x += vert[WATER_RESOLUTION+1].y;
					normal->z += vert[WATER_RESOLUTION+1].y;
				}
				else {
					normal->x += vert[WATER_RESOLUTION].y;
					normal->z += vert[WATER_RESOLUTION].y;
				}
			}
			else {
				normal->x += vert[0].y;
				normal->x += vert[0].y*2.0f;
				normal->x += vert[0].y;

				normal->z += -vert[0].y;
				normal->z += vert[0].y;
			}

			//normalize the normal
			temp = 1.0f/(float)sqrt(normal->x*normal->x + normal->z*normal->z +1.0f);
			normal->x *= temp;
			normal->y *= temp;
			normal->z *= temp;
		}
	}
}

void Water::Render(bool useCVA) {

	//bind the water's "water map"
	glBindTexture(GL_TEXTURE_2D, m_RefMapID);
	glEnable(GL_TEXTURE_2D);

	//use sphere mapping to auto-gen texture coordinates
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glColor4f(m_VecColour.x, m_VecColour.y, m_VecColour.z, m_Transparency);

	//enable vertex arrays and send OpenGL the vertex buffer pointer
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof(Vector3D), &m_VertArray);

	//enable normal arrays and send OpenGL the normal buffer pointer
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, sizeof(Vector3D), &m_NormalArray);

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);

	//lock the arrays
	//if(useCVA)
		//glLockArraysEXT(0, m_NumVertices);

	//draw the water patch
	glDrawElements(GL_TRIANGLES, m_NumIndices, GL_UNSIGNED_INT, m_PolyIndexArray);

	//unlock the arrays
//	if(useCVA)
	//	glUnlockArraysEXT();

	//disable vertex arrays
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	//disable automatic tex-coordinate genertaion
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
}

bool Water::LoadReflectionMap(char* fileName){
	assetManager->Load(fileName);

	unsigned int tex = graphics->SetupTextureClamp(assetManager->GetAsset(fileName));
	
	if(!tex)
		return false;

	m_RefMapID = tex;

	return true;
}
