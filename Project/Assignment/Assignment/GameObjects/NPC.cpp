
#include "NPC.h"

#include "../Singletons.h"

NPC::NPC() :
	GameObject(),
	m_Health(0),
	m_move(new Movement()),
	m_curwayPointNo(0),
	m_aiTime(0.0f)
{
	m_npcFSM=new StateMachine<NPC>(this);
	m_velocity.Set(0.0f, 0.5f, 0.0f);
	m_waypoints.ClearAllWaypoints();
}

NPC::NPC(char* objectName, float xPos, 
			float yPos, float zPos) :
	GameObject(objectName, xPos, yPos, zPos),
	m_Health(0),
	m_move(new Movement()),
	m_curwayPointNo(0),
	m_aiTime(0.0f)
{
	m_velocity.Set(0.0f, 0.5f, 0.0f);
}

NPC::~NPC()
{
	delete m_move;
	m_move = nullptr;
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
	m_move->MoveTo(m_Position, temp, m_velocity, deltaT);

	Vector3D pos = temp - m_Position;
	//m_velocity.Print();
		m_yaw = m_move->CalcYaw(m_Position, temp, m_velocity);
		
		//std::cout << "yaw: " << m_yaw << std::endl;
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

//void NPC::ChangeState(State *newState)
//{
//	m_CurrentState->Exit(this);
//	m_CurrentState = newState;
//	m_CurrentState->Enter(this);
//}

StateMachine<NPC>* NPC::GetFSM()const
{
	return m_npcFSM;
}

void NPC::SetCurrentState(const luabind::object &state)
{
	m_npcFSM->SetCurrentState(state);
}

void NPC::AddWaypoints(Waypoint<Vector3D> wp)
{
	m_waypoints = wp;
	std::cout << "Waypoints Added" << std::endl;
	std::cout << m_waypoints << std::endl;
}

void NPC::AddWaypoint(const Vector3D& wayPt)
{
	m_waypoints.AddWaypoint(wayPt);
	
}

void NPC::AssignPatroller()
{

}

void NPC::UpdateAI(float timeElapsed)
{
	m_aiTime = timeElapsed;
	//m_npcFSM->Update();
}

void NPC::WaypointFollow()
{
	if(m_move->MoveTo(m_Position, m_waypoints.GetWaypoint(m_curwayPointNo), m_velocity, m_aiTime, 0))
	{ 
		if(m_curwayPointNo== m_waypoints.GetNumWaypoints()-1)
			m_curwayPointNo = 0;
		else
		    m_curwayPointNo++;    
	}
}

int NPC::GetNumWaypoints()
{
	return m_waypoints.GetNumWaypoints();
}

void NPC::SetCurwayPointNo(int num)
{
	m_curwayPointNo = num;
}
