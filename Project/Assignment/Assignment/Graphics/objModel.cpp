
#include"objModel.h"

#include "../Singletons.h"

#include <gl/glut.h>

objModel::objModel(char* name, std::vector<tinyobj::shape_t> shapes, 
			std::vector<tinyobj::material_t> mats,
			std::vector<unsigned int> textures) :
	obj(name, shapes, mats, textures)
{
}

objModel::~objModel()
{
}

void objModel::Render(Vector3D position, float yaw)
{
	// Render model
	int current = -1, newtex = 0;

	for (size_t i = 0; i < m_shapes.size(); i++) {
		newtex = m_shapes[i].mesh.material_ids[0];
			
		graphics->SetColour(1.0f,1.0f,1.0f);
		if(current != newtex) {
			//current = newtex;
			//glBindTexture(GL_TEXTURE_2D,m_textures[current]);
			current = newtex;
			graphics->Tex2DOn(m_textures[current]);
		}

		float *vertices = &m_shapes[i].mesh.positions[0];
		float *textures = &m_shapes[i].mesh.texcoords[0];
		unsigned int *indices = &m_shapes[i].mesh.indices[0];
			
		graphics->EnableClientState(VERTEX_ARRAY);
		graphics->EnableClientState(TEXTURE_COORD_ARRAY);
		
		graphics->VAvertex(vertices);
		graphics->VAtexCoord(textures);
	
		graphics->PushMatrix();
			graphics->Translate(position.x, position.y, position.z);
			//graphics->Scale(m_scale.x, m_scale.y, m_scale.z);
			graphics->VAdrawTriangles(m_shapes[i].mesh.indices.size(), indices);
		graphics->PopMatrix();
	}	
	graphics->Tex2DOff();
	graphics->DisableClientState(VERTEX_ARRAY);
	graphics->DisableClientState(TEXTURE_COORD_ARRAY);
}
