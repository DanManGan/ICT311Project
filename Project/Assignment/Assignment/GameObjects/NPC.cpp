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

void NPC::SetAnimation(unsigned short startFrame, unsigned short endFrame)
{
	m_model->SetAnimation(startFrame, endFrame);
}

void NPC::Update(float deltaT)
{
	m_velocity.z = 1.0f;
	m_model->Update(deltaT);
	UpdatePosition(deltaT);
}

void NPC::Render()
{
	m_model->Render();
}

