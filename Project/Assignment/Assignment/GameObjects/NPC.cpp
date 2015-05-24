#include "NPC.h"

#include "../AssetManagement/md2.h"

NPC::NPC() :
	GameObject(),
	m_Health(0)
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

void NPC::Update(float deltaT)
{
	m_velocity.z = m_model->GetModelSpeed(); ///////////////////////// Set speed
	m_yaw -= 0.5f; /////////////////////////////// Set rotation
	m_model->Update(deltaT);
	UpdatePosition(deltaT);
}

void NPC::Render()
{
	m_model->Render(m_Position, m_yaw);
}

