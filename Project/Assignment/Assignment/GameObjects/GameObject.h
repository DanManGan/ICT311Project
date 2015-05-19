#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../Graphics/ViewOpenGL.h"
#include "../Extras/Vector3D.h"
#include "../AssetManagement/Mesh.h"

class GameObject
{
public:
	GameObject();
	GameObject(float xPos, float yPos, float zPos);
	GameObject(char* fileName, float xPos, 
				float yPos, float zPos);

	virtual ~GameObject();

	virtual void Initialise() { };
	virtual void Update() { };
	virtual void Render()=0;

	const float* GetModel();
	const int GetModelSize();
	char* GetAssetFile();
	void SetModelSize(int size);
	virtual void SetPosition(Vector3D newPos);
	void SetPosition(float x, float y, float z);
	void SetAssetFile(char* file);
	Vector3D GetPosition();

	void ChangePosition(float x, float y, float z);

	bool SetMesh(GameAsset* mesh);
	bool SetSkin(unsigned int skin);
	
protected:
	Vector3D m_Position;
	Mesh* m_model;
private:
	
	int m_ModelSize;
	float m_Scale;
	float m_Rotation;
	char* m_FileName;
};


#endif
