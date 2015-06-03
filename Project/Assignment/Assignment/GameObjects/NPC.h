
#ifndef NPC_H
#define NPC_H

#include "GameObject.h"
#include "../Extras/Vector3D.h"
#include "../AI/Movement.h"
#include "../AI/Waypoint.h"
#include "../AI/StateMachine.h"


class NPC : public GameObject
{
public:
	NPC();

	NPC(char* objectName, float xPos, 
			float yPos, float zPos);

	~NPC();

	CLASS_TYPE(NPC);

	void Animate(float deltaT);
	void SetAnimation(AnimationState state);
	//void ChangeState(State *newState);
	void Render();
/////////////////////////////////////////////////////////
	StateMachine<NPC>* m_npcFSM;
	StateMachine<NPC>* GetFSM()const;
	void SetCurrentState(const luabind::object &state);

	void AddWaypoints(Waypoint<Vector3D> wp);
	void AddWaypoint(const Vector3D& wayPt);
	void AssignPatroller();
	void UpdateAI(float timeElapsed);
	void WaypointFollow();
    //vector2D getWaypoint(unsigned short wayPointNo);
	int GetNumWaypoints();
	void SetCurWaypoint(int num);
	int GetCurWaypoint();
	bool IdleStateDone();
	void SetAnimationLua(int stateNum);
	void SetWaypointCycles(int num);
	int GetWaypointCycles();

	//bool SeePlayer();
	bool ProcessCollision();

	bool Wander(float wanderTime);

protected:

	Movement* m_move;

private:
	int m_Health;
	//State *m_CurrentState;
	Waypoint<Vector3D> m_waypoints;

	Vector3D m_targetPos;
	int m_curWaypointNo;
	float m_aiTime;
	float m_idleTime;
	float m_idleStart;
	int m_waypointCycles;
	float m_wanderTime;

};

#endif