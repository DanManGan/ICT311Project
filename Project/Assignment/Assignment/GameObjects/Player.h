#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "../Graphics/ViewOpenGL.h"
#include "../AI/State.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	CLASS_TYPE(Player);

	void SetPlayerCameraPosition(Vector3D pos);
	void SetPlayerCameraLookAt(Vector3D lookAt);
	void SetHealth(int health);
	void SetPosition(Vector3D newPos);
	Vector3D GetPlayerCameraPosition();
	Vector3D GetPlayerLookAt();
	int GetHealth();
	void ChangeState(State *newState);

	void Initialise();
	void Update();

	void Animate(float deltaT) {};
	void Render() {};
	void SetAnimation(AnimationState state) {};
	

protected:
private:
	Vector3D m_PlayerCameraPosition;
	Vector3D m_PlayerCameraLookAt;
	int m_Health;
	State *m_CurrentState;
};

#endif 