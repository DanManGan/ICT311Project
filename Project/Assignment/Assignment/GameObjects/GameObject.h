#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include "../Extras/Vector3D.h"
#include "../AssetManagement/Mesh.h"
#include "../Collision/AABB.h"

class GameObject
{
public:
	GameObject();
	GameObject(float xPos, float yPos, float zPos);
	GameObject(char* name, float xPos, 
				float yPos, float zPos);

	virtual ~GameObject();

	virtual void Initialise() { };
	virtual void Animate(float deltaT) = 0;
	virtual void Render()=0;
	

	const float* GetModel();
	const int GetModelSize();
	char* GetAssetFile();
	void SetModelSize(int size);
	void SetAssetFile(char* file);

	void ChangePosition(float x, float y, float z);
////////////////////////////////////////////////////////////
	bool SetMesh(GameAsset* mesh);
	bool SetSkin(unsigned int skin);
	void SetAnimation(AnimationState state);

	bool SetScale(float scaleX, float scaleY, float scaleZ);
	void SetBase();

	void SetAABB();

	float GetX();
	float GetY();
	float GetZ();
	Vector3D GetPos();

	void SetX(float x);
	void SetY(float y);
	void SetZ(float z);
	void SetPos(Vector3D newPos);
	void SetPos(float x, float y, float z);

	void UpdatePosition(float deltaT);

	void Left();
	void Right();

	float GetYaw();

	void DrawAABB();

	void TestCollision(GameObject* obj);
	
protected:
	Vector3D m_Position;
	Vector3D m_velocity;
	float m_yaw;
	Mesh* m_model;
	float m_base;
	AABB m_boundingBox;

private:
	
	int m_ModelSize;
	float m_Scale;
	float m_Rotation;
	char* m_name;
};


#endif
