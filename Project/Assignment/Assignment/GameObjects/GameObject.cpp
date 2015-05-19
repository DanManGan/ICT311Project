#include "GameObject.h"

GameObject::GameObject() :
	m_model(nullptr),
	m_FileName(""),
	m_Scale(1.0f),
	m_Rotation(0.0f),
	m_ModelSize(0)
{
	m_Position.Set(0.0f, 0.0f, 0.0f);
}

GameObject::GameObject(float xPos, float yPos, float zPos) :
	m_model(nullptr),
	m_FileName(""),
	m_Scale(1.0f),
	m_Rotation(0.0f),
	m_ModelSize(0)
{
	m_Position.Set(xPos, yPos, zPos);
}

GameObject::GameObject(char* fileName, float xPos, float yPos, float zPos)
{
	m_FileName = fileName;
	m_Position.Set(xPos, yPos, zPos);
}

GameObject::~GameObject()
{
}

void GameObject::SetModelSize(int size)
{
	m_ModelSize = size;
}

Vector3D GameObject::GetPosition()
{
	return m_Position;
}

void GameObject::SetPosition(Vector3D newPos)
{
	m_Position = newPos;
}

void GameObject::SetPosition(float xPos, float yPos, float zPos)
{
	m_Position.Set(xPos, yPos, zPos);
}

void GameObject::ChangePosition(float x, float y, float z)
{
	m_Position.x += x;
	m_Position.y += y;
	m_Position.z += z;
}

char* GameObject::GetAssetFile()
{
	return m_FileName;
}

void GameObject::SetAssetFile(char* file)
{
	m_FileName = file;
}

bool GameObject::SetMesh(GameAsset* mesh)
{
	m_model = (Mesh*)mesh;

	return true;
}

bool GameObject::SetSkin(unsigned int skin)
{
	return m_model->SetSkin(skin);
}