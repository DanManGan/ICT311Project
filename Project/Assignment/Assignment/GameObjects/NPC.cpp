#include "NPC.h"

#include "../AssetManagement/md2.h"

NPC::NPC() :
	GameObject(),
	m_Health(0),
	m_move(Movement())
{
}

NPC::NPC(char* objectName, float xPos, 
			float yPos, float zPos) :
	GameObject(objectName, xPos, yPos, zPos),
	m_Health(0)
{
}

void NPC::Initialise()
{

}

void NPC::SetAnimation(AnimationState state)
{
	m_model->SetAnimation(state);
}

void NPC::Animate(float deltaT)
{
	//m_velocity.z = m_model->GetModelSpeed(); ///////////////////////// Set speed
	//m_yaw -= 0.5f; /////////////////////////////// Set rotation

	Vector3D temp(0, 0, 0);
	m_model->Animate(deltaT);
	m_move.MoveTo(m_Position, temp, m_velocity, deltaT);
	//UpdatePosition(deltaT);
}

void NPC::Render()
{
	m_model->Render(m_Position, m_yaw);
}

