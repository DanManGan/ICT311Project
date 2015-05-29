
#include "obj.h"

obj::obj(char* name, std::vector<tinyobj::shape_t> shapes, 
			std::vector<tinyobj::material_t> mats,
			std::vector<unsigned int> textures) :
	Mesh(name),
	m_shapes(shapes),
	m_mats(mats),
	m_textures(textures)
{

}

obj::~obj()
{
}

bool obj::SetScale(float scaleX, float scaleY, float scaleZ)
{
	if(scaleX > 0 && scaleY > 0 && scaleZ > 0) {
		m_scale.Set(scaleX, scaleY, scaleZ);

		for (size_t i = 0; i < m_shapes.size(); i++) 
		{
				for (size_t f = 0; f < m_shapes[i].mesh.positions.size() / 3; f++) 
				{
						m_shapes[i].mesh.positions[3*f+0] *= m_scale.x;
						m_shapes[i].mesh.positions[3*f+1] *= m_scale.y;
						m_shapes[i].mesh.positions[3*f+2] *= m_scale.z;
				}
		}
		return true;
	}
	return false;
}

bool obj::SetSkin(unsigned int skin)
{
	return true;
}

float obj::GetBase()
{
	return 0.0f;
}

float obj::GetModelSpeed()
{
	return 0.0f;
}

std::vector<tinyobj::shape_t> obj::GetShapes()
{
	return m_shapes;
}