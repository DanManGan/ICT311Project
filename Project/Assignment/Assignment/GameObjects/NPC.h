#ifndef NPC_H
#define NPC_H

#include "GameObject.h"
//#include "../AI/Movement.h"
#include "../AI/State.h"

class NPC :public GameObject
{
public:
	NPC();

	NPC(char* objectName, float xPos, 
			float yPos, float zPos);

	void Initialise();
	void Animate(float deltaT);
	void SetAnimation(AnimationState state);
	void ChangeState(State *newState);
	void Render();



protected:

	//Movement m_move;

private:
	int m_Health;
	State *m_CurrentState;
};

#endif