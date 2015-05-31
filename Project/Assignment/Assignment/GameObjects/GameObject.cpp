
#include "GameObject.h"

#include "../Extras/MathExtra.h"

#include "../Singletons.h"

#include <iostream>
#include <algorithm>


GameObject::GameObject() :
	m_model(nullptr),
	m_name(""),
	m_Scale(1.0f),
	m_Rotation(0.0f),
	m_ModelSize(0),
	m_yaw(0.0f),
	m_base(0),
	m_Position(0.0f, 0.0f, 0.0f),
	m_velocity(0.0f, 0.0f, 0.0f),
	m_boundingBox(AABB())
{
}

GameObject::GameObject(float xPos, float yPos, float zPos) :
	m_model(nullptr),
	m_name(""),
	m_Scale(1.0f),
	m_Rotation(0.0f),
	m_ModelSize(0),
	m_yaw(0.0f),
	m_base(0),
	m_Position(xPos, yPos, zPos),
	m_velocity(0.0f, 0.0f, 0.0f),
	m_boundingBox(AABB())
{
}

GameObject::GameObject(char* name, float xPos, float yPos, float zPos) :
	m_model(nullptr),
	m_name(name),
	m_Scale(1.0f),
	m_Rotation(0.0f),
	m_ModelSize(0),
	m_yaw(0.0f),
	m_base(0),
	m_Position(xPos, yPos, zPos),
	m_velocity(0.0f, 0.0f, 0.0f),
	m_boundingBox(AABB())
{
}

GameObject::~GameObject()
{
	delete m_model;
	m_model = nullptr;
}

void GameObject::SetModelSize(int size)
{
	m_ModelSize = size;
}

void GameObject::SetX(float x)
{
	m_Position.x = x;
}

void GameObject::SetY(float y)
{
	m_Position.y = y + m_base;
}

void GameObject::SetZ(float z)
{
	m_Position.z = z;
}

void GameObject::SetPos(Vector3D newPos)
{
	m_Position = newPos;
	m_Position.y += m_base;
}

void GameObject::SetPos(float xPos, float yPos, float zPos)
{
	m_Position.Set(xPos, yPos + m_base, zPos);
}

void GameObject::SetVelocity(float velX, float velY, float velZ)
{
	m_velocity = Vector3D(velX, velY, velZ);
}

void GameObject::SetPosition(float x, float y, float z)
{
	m_Position.x += x;
	m_Position.y += (y + m_base);
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

//void GameObject::SetAnimation(AnimationState state)
//{
//	m_model->SetAnimation(state);
//}

bool GameObject::SetScale(float scaleX, float scaleY, float scaleZ)
{
	return m_model->SetScale(scaleX, scaleY, scaleZ);
}

void GameObject::SetBase()
{
	/*m_Position.y = m_model->GetBase();*/
	m_base = m_model->GetBase();
}

void GameObject::SetAABB()
{
	m_boundingBox.CreateAABB(m_model);
}

void GameObject::DrawAABB()
{
	Vector3D min = m_boundingBox.GetMin();
	Vector3D max = m_boundingBox.GetMax();

	//if(GetObjectType() == "PLAYER") {
	//	std::cout << "DrawAABB" << std::endl;
	//	min.Print();
	//	max.Print();
	//}

	graphics->PushMatrix();
		graphics->Translate(m_Position.x, m_Position.y, m_Position.z);
		graphics->Rotate(-m_yaw, 0.0f, 1.0f, 0.0f);
		glEnable(GL_COLOR);
		glLineWidth(2.5);
		glColor3f(1.0, 0.0, 0.0);
		graphics->Begin(LINES);
		glVertex3f(min.x, max.y, min.z);
		glVertex3f(min.x, min.y, min.z);

		glVertex3f(max.x, max.y, min.z);
		glVertex3f(max.x, min.y,min.z);

		glVertex3f(min.x,max.y, max.z);
		glVertex3f(min.x, min.y, max.z);

		glVertex3f(max.x, max.y, max.z);
		glVertex3f(max.x, min.y, max.z);
		graphics->End();
	graphics->PopMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
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

	// calculate new position of model
     //m_Position.x += float(cos(DEG_TO_RAD(m_yaw + 90.0f)))*strafeSpeed;
     //m_Position.z += float(sin(DEG_TO_RAD(m_yaw + 90.0f)))*strafeSpeed;
     //m_Position.x += float(cosYaw)*speed;
     //m_Position.z += float(sinYaw)*speed;

	// calculate new position of model

//	 std::cout << "yaw " << float(cos(DEG_TO_RAD(m_yaw + 90.0f)))*strafeSpeed << std::endl;
//	 std::cout << "NO yaw " << float(cos(DEG_TO_RAD(90.0f)))*strafeSpeed << std::endl;

     m_Position.x += float(cos(DEG_TO_RAD(m_yaw)))*strafeSpeed;
     m_Position.z += float(sin(DEG_TO_RAD(m_yaw)))*strafeSpeed;
     m_Position.x += float(cosYaw)*speed;
     m_Position.z += float(sinYaw)*speed;	

	//// calculate lookAt based on new position
 //    lookAt.x = float(position.x + cosYaw);
 //    lookAt.y = float(position.y + sinPitch);
 //    lookAt.z = float(position.z + sinYaw);
}

float GameObject::GetYaw()
{
	return m_yaw;
}

void GameObject::SetYaw(float yaw)
{
	m_yaw = yaw;
}

void GameObject::TestCollision(GameObject* obj)
{
	//std::cout << "Collision Test: " << this->m_name << " " << obj->m_name << std::endl;
	//this->m_Position.Print();
	//obj->m_Position.Print();
	if(m_boundingBox.CheckCollision(m_Position, obj->m_boundingBox, obj->m_Position)) {
		//std::cout << "Fuck Yeah" << std::endl;
		this->m_Position.Set(100.0f, 0.0f, 100.0f);
		obj->m_Position.Set(20.0f, 0.0f, 20.0f);
	}

}