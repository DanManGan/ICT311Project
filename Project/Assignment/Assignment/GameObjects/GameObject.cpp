#include "GameObject.h"


#include "../Extras/MathExtra.h"

GameObject::GameObject() :
	m_model(nullptr),
	m_name(""),
	m_Scale(1.0f),
	m_Rotation(0.0f),
	m_ModelSize(0),
	m_yaw(0.0f)
{
	m_Position.Set(0.0f, 0.0f, 0.0f);
	m_velocity.Set(0.0f, 0.0f, 0.0f);
}

GameObject::GameObject(float xPos, float yPos, float zPos) :
	m_model(nullptr),
	m_name(""),
	m_Scale(1.0f),
	m_Rotation(0.0f),
	m_ModelSize(0),
	m_yaw(0.0f)
{
	m_Position.Set(xPos, yPos, zPos);
	m_velocity.Set(0.0f, 0.0f, 0.0f);
}

GameObject::GameObject(char* name, float xPos, float yPos, float zPos) :
	m_model(nullptr),
	m_Scale(1.0f),
	m_Rotation(0.0f),
	m_ModelSize(0),
	m_yaw(0.0f)
{
	m_name = name;
	m_Position.Set(xPos, yPos, zPos);
	m_velocity.Set(0.0f, 0.0f, 0.0f);
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
	return m_name;
}

void GameObject::SetAssetFile(char* name)
{
	m_name = name;
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

bool GameObject::SetScale(float scaleX, float scaleY, float scaleZ)
{
	return m_model->SetScale(scaleX, scaleY, scaleZ);
}

void GameObject::SetBase()
{
	/*m_Position.y = m_model->GetBase();*/
	m_Position.y = m_model->GetBase();
}

float GameObject::GetX()
{
	return m_Position.x;
}

float GameObject::GetY()
{
	return m_Position.y;
}
float GameObject::GetZ()
{
	return m_Position.z;
}

Vector3D GameObject::GetPos()
{
	return m_Position;
}
void GameObject::UpdatePosition(float deltaT)
{
     if ((m_yaw >= 360.0f) || (m_yaw <= -360.0f))
          m_yaw = 0.0f;

     //if (pitch > 60.0f)
     //     pitch = 60.0f;
     //if (pitch < -60.0f)
     //     pitch = -60.0f;
     
	// calculate trig functions
     float cosYaw = (float)cos(DEG_TO_RAD(m_yaw));
     float sinYaw = (float)sin(DEG_TO_RAD(m_yaw));
    // float sinPitch = (float)sin(DEG_TO_RAD(pitch));
	 
	// speed is velocity z-component
     float speed = m_velocity.z * deltaT;

	// strafe speed is velocity x-component
     float strafeSpeed = m_velocity.x * deltaT;

	// speed limit
     if (speed > 5.0f)
          speed = 5.0f;
     if (strafeSpeed > 5.0f)
          strafeSpeed = 5.0f;
     if (speed < -5.0f)
          speed = -5.0f;
     if (strafeSpeed < -5.0f)
          strafeSpeed = -5.0f;

	// calculate new position of camera
     m_Position.x += float(cos(DEG_TO_RAD(m_yaw + 90.0f)))*strafeSpeed;
     m_Position.z += float(sin(DEG_TO_RAD(m_yaw + 90.0f)))*strafeSpeed;
     m_Position.x += float(cosYaw)*speed;
     m_Position.z += float(sinYaw)*speed;

	//// calculate lookAt based on new position
 //    lookAt.x = float(position.x + cosYaw);
 //    lookAt.y = float(position.y + sinPitch);
 //    lookAt.z = float(position.z + sinYaw);
}