#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../ViewOpenGL.h"
#include "../Extras/Vector3D.h"

class GameObject
{
public:
	GameObject();
	GameObject(float xPos, float yPos, float zPos);
	GameObject(char* fileName, float xPos, float yPos, float zPos);

	virtual void Initialise() { };
	virtual void Update() { };
	const float* GetModel();
	const int GetModelSize();
	char* GetAssetFile();
	void SetModelSize(int size);
	virtual void SetPosition(Vector3D newPos);
	void SetPosition(float x, float y, float z);
	void SetAssetFile(char* file);
	Vector3D GetPosition();

	void ChangePosition(float x, float y, float z);

protected:
	Vector3D m_Position;

private:
	int m_ModelSize;
	float m_Scale;
	float m_Rotation;
	char* m_FileName;
};


#endif
