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
	GameObject(char* name, float xPos, 
				float yPos, float zPos);

	virtual ~GameObject();

	virtual void Initialise() { };
	virtual void Update(float deltaT) = 0;
	virtual void Render()=0;
	virtual void SetAnimation(unsigned short startFrame, unsigned short endFrame) = 0;

	const float* GetModel();
	const int GetModelSize();
	char* GetAssetFile();
	void SetModelSize(int size);
	virtual void SetPosition(Vector3D newPos);
	void SetPosition(float x, float y, float z);
	void SetAssetFile(char* file);
	Vector3D GetPosition();

	void ChangePosition(float x, float y, float z);
////////////////////////////////////////////////////////////
	bool SetMesh(GameAsset* mesh);
	bool SetSkin(unsigned int skin);

	bool SetScale(float scaleX, float scaleY, float scaleZ);
	void SetBase();

	float GetX();
	float GetY();
	float GetZ();
	Vector3D GetPos();

	void UpdatePosition(float deltaT);
	
protected:
	Vector3D m_Position;
	Vector3D m_velocity;
	float m_yaw;
	Mesh* m_model;
private:
	
	int m_ModelSize;
	float m_Scale;
	float m_Rotation;
	char* m_name;
};


#endif
