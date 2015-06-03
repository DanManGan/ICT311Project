
#include "Mesh.h"

Mesh::Mesh() :
	m_scale(1.0f, 1.0f, 1.0f)
{

}

Mesh::Mesh(char* name) :
	GameAsset(name),
	m_scale(1.0f, 1.0f, 1.0f)
{
}

Mesh::~Mesh()
{
}

int Mesh::GetAnimationSpeed()
{
	return 0;
}
//bool Mesh::SetScale(float scaleX, float scaleY, float scaleZ);
//{
//	if(scaleX && scaleY && scaleZ) {
//		m_scale.Set(scaleX, scaleY, scaleZ);
//		return true;
//	}
//	return false;
//}