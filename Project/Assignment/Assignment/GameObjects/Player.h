#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "../Graphics/ViewOpenGL.h"
#include "../AI/State.h"

class Player :public GameObject
{
public:
	Player();
	~Player();
	void SetPlayerCameraPosition(Vector3D pos);
	void SetPlayerCameraLookAt(Vector3D lookAt);
	void SetHealth(int health);
	virtual void SetPosition(Vector3D newPos);
	Vector3D GetPlayerCameraPosition();
	Vector3D GetPlayerLookAt();
	int GetHealth();
	void ChangeState(State *newState);

	virtual void Initialise();
	virtual void Update();

protected:
private:
	Vector3D m_PlayerCameraPosition;
	Vector3D m_PlayerCameraLookAt;
	int m_Health;
	State *m_CurrentState;
};

#endif 