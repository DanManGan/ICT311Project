
#include "Model.h"

Model::Model() :
	GameObject()
{
}

Model::Model(char* objectName, float xPos, 
			float yPos, float zPos) :
	GameObject(objectName, xPos, yPos, zPos)
{
}

Model::~Model()
{
}

void Model::Render()
{
	m_model->Render(m_Position, m_yaw);
}