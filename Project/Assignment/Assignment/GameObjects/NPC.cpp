
#include "NPC.h"

#include "../Singletons.h"

NPC::NPC() :
	GameObject(),
	m_Health(0),
	m_move(new Movement()),
	m_curWaypointNo(0),
	m_aiTime(0.0f),
	m_idleTime(0.0f),
	m_idleStart(0.0f),
	m_waypointCycles(0),
	m_wanderTime(0),
	m_targetPos(0.0f, 0.0f, 0.0f)
{
	m_npcFSM=new StateMachine<NPC>(this);
	m_velocity.Set(0.0f, 0.5f, 0.0f);
	m_waypoints.ClearAllWaypoints();
	m_move->SetWander(5.0f, 5.0f, 2.0f);
}

NPC::NPC(char* objectName, float xPos, 
			float yPos, float zPos) :
	GameObject(objectName, xPos, yPos, zPos),
	m_Health(0),
	m_move(new Movement()),
	m_curWaypointNo(0),
	m_aiTime(0.0f),
	m_idleTime(0.0f),
	m_idleStart(0.0f),
	m_waypointCycles(0),
	m_wanderTime(0),
	m_targetPos(0.0f, 0.0f, 0.0f)
{
	m_velocity.Set(0.0f, 0.5f, 0.0f);
	m_move->SetWander(5.0f, 5.0f, 2.0f);
}

NPC::~NPC()
{
	delete m_move;
	m_move = nullptr;
}


void NPC::SetAnimation(AnimationState state)
{
	m_model->SetAnimation(state);


	//if(state != STAND && state != SALUTE && state != WAVE && state != BOOM) {
	//	m_velocity.z = m_model->GetModelSpeed(); ///////////////////////// Set speed
	//}
	if(m_model->GetModelSpeed()) {
		m_velocity.z = m_model->GetModelSpeed();
	}
	else {
		m_velocity.Set(0.0f, 0.0f, 0.0f);
		m_idleTime = m_model->GetAnimationSpeed();
		//m_idleStart = m_aiTime;
	}
}

void NPC::Animate(float deltaT)
{

	//Vector3D temp(50, 50, 50);
	//Vector3D temp(111, 111, 111);
	m_aiTime = deltaT;
	m_model->Animate(deltaT);
	//m_yaw = 0.0f;
	//
	//m_move->MoveTo(m_Position, temp, m_velocity, deltaT);


	m_npcFSM->Update();

	//Vector3D pos = temp - m_Position;
	//m_velocity.Print();
	if(!m_velocity.IsZero()) {
		m_yaw = m_move->CalcYaw(m_Position, m_targetPos, m_velocity);
	}
		
		//std::cout << "yaw: " << m_yaw << std::endl;
	//getchar();

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
	//std::cout << "NPC Position: ";
	//m_Position.Print();
	//std::cout << "NPC Waypoint: ";
	//m_waypoints.GetWaypoint(m_curWaypointNo).Print();

	if(m_move->MoveTo(m_Position, m_waypoints.GetWaypoint(m_curWaypointNo), m_velocity, m_aiTime, 0))
	{ 
		m_targetPos = m_waypoints.GetWaypoint(m_curWaypointNo);
		if(m_curWaypointNo == m_waypoints.GetNumWaypoints()-1) {
			m_curWaypointNo = 0;
		}
		else {
		    m_curWaypointNo++;   
		}
		m_waypointCycles++;
	}
}

int NPC::GetNumWaypoints()
{
	return m_waypoints.GetNumWaypoints();
}

void NPC::SetCurWaypoint(int num)
{
	m_curWaypointNo = num;
}

int NPC::GetCurWaypoint()
{
	return m_curWaypointNo;
}

void NPC::SetWaypointCycles(int num)
{
	m_waypointCycles = num;
}

int NPC::GetWaypointCycles()
{
	return m_waypointCycles;
}

bool NPC::IdleStateDone()
{
		std::cout << "in Idle state" << std::endl;
		std::cout << "ai: " << m_aiTime << " start: " << m_idleStart << " idle time: " << m_idleTime << std::endl;
	//getchar();
	if(m_idleStart >= m_idleTime) {
		m_idleStart = 0.0f;
		return true;
	}
	m_idleStart += m_aiTime;
	return false;
}


bool NPC::ProcessCollision()
{
		std::cout << "in ProcessCollision state" << std::endl;
		std::cout << "ai: " << m_aiTime << " start: " << m_idleStart << " idle time: " << m_idleTime << std::endl;
	//getchar();
	if(m_idleStart >= m_idleTime) {
		m_idleStart = 0.0f;
		//m_yaw +=180.0f;
		//m_curWaypointNo++;
		m_Position.x += 5.0f;
		m_Position.z += 5.0f;
		m_velocity.z += 0.02f;
		return true;
	}
	m_idleStart += m_aiTime;
	return false;
}

bool NPC::Wander(float wanderTime)
{
	m_wanderTime += m_aiTime;

	if(m_wanderTime >= wanderTime) {
		m_wanderTime = 0.0f;
		return true;
	}
	m_move->Wander(m_Position, m_velocity, m_aiTime);
	
		std::cout << "m_wanderTime: " << m_wanderTime << " m_aiTime: " << m_aiTime << std::endl;
	return false;
}

void NPC::SetAnimationLua(int stateNum)
{
	AnimationState state;

	switch(stateNum)
	{
		case 0:
		   state = STAND;
		break;
		case 1:
			state = RUN;
		break;
		case 2:
			state = ATTACK;
		break;
		case 3:
			state = PAIN_A;
		break;
		case 4:
			state = PAIN_B;
		break;
		case 5:
			state = PAIN_C;
		break;
		case 6:
			state = JUMP;
		break;
		case 7:
			state = FLIP;
		break;
		case 8:
			state = SALUTE;
		break;
		case 9:
			state = FALLBACK;
		break;
		case 10:
			state = WAVE;
		break;
		case 11:
			state = POINT_AT;
		break;
		case 12:
			state = CROUCH_STAND;
		break;
		case 13:
			state = CROUCH_WALK;
		break;
		case 14:
			state = CROUCH_ATTACK;
		break;
		case 15:
			state = CROUCH_PAIN;
		break;
		case 16:
			state = CROUCH_DEATH;
		break;
		case 17:
			state = DEATH_FALLBACK;
		break;
		case 18:
			state = DEATH_FALLFORWARD;
		break;
		case 19:
			state = DEATH_FALLBACKSLOW;
		break;
		case 20:
			state = BOOM;
		break;
		default:
			state = STAND;
	}
	SetAnimation(state);
}