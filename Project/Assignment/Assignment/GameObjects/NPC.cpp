#include "NPC.h"

#include "../AssetManagement/md2.h"
#include "../Singletons.h"

NPC::NPC() :
	GameObject(),
	m_Health(0)/*,
	m_move(Movement())*/
{
	m_velocity.Set(0.0f, 0.5f, 0.0f);
}

NPC::NPC(char* objectName, float xPos, 
			float yPos, float zPos) :
	GameObject(objectName, xPos, yPos, zPos),
	m_Health(0)
{
	m_velocity.Set(0.0f, 0.5f, 0.0f);
}

void NPC::Initialise()
{

}

void NPC::SetAnimation(AnimationState state)
{
	m_model->SetAnimation(state);
	//m_velocity.z = m_model->GetModelSpeed(); ///////////////////////// Set speed
	
}

void NPC::Animate(float deltaT)
{

	Vector3D temp(50, 50, 50);
	//Vector3D temp(111, 111, 111);

	m_model->Animate(deltaT);
	//m_yaw = 0.0f;
	//
	move->MoveTo(m_Position, temp, m_velocity, deltaT);

	Vector3D pos = temp - m_Position;
	//m_velocity.Print();
		m_yaw = move->CalcYaw(m_Position, temp, m_velocity);
		
		std::cout << "yaw: " << m_yaw << std::endl;
	//getchar();

	//m_velocity.z = 0.5f;
	//m_velocity.x = 0.5f;
	//m_velocity.Print();
	//m_velocity.z = m_model->GetModelSpeed(); ///////////////////////// Set speed
	//m_yaw -= 0.5f; /////////////////////////////// Set rotation
	//UpdatePosition(deltaT);
}

void NPC::Render()
{
	m_model->Render(m_Position, m_yaw);
}

void NPC::ChangeState(State *newState)
{
	m_CurrentState->Exit(this);
	m_CurrentState = newState;
	m_CurrentState->Enter(this);
}