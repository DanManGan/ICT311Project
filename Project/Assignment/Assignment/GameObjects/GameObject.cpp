#include "GameObject.h"

GameObject::GameObject()
{
	m_FileName = "";
	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.z = 0;
}

GameObject::GameObject(float xPos, float yPos, float zPos)
{
	m_Position.x = xPos;
	m_Position.y = yPos;
	m_Position.z = zPos;
}

GameObject::GameObject(char* fileName, float xPos, float yPos, float zPos)
{
	m_Position.x = xPos;
	m_Position.y = yPos;
	m_Position.z = zPos;
	m_FileName = fileName;
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

void GameObject::SetPosition(float x, float y, float z)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Position.z = z;
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