#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "../Graphics/ViewOpenGL.h"
#include "../AI/State.h"
#include "../Graphics/CameraModel.h"

class Player : public GameObject
{
public:
	Player();

	~Player();

	CLASS_TYPE(PLAYER);

	//void SetPlayerCameraPosition(Vector3D pos);
	void SetPlayerCameraLookAt(Vector3D lookAt);
	void SetHealth(int health);
	//void SetPosition(Vector3D newPos);
	//Vector3D GetPlayerCameraPosition();
	Vector3D GetPlayerLookAt();
	int GetHealth();
	void ChangeState(State *newState);

	void Update();

	void Animate(float deltaT);
	void Render();
	void SetAnimation(AnimationState state) {};

	void UpdatePitch(float pitch);

	void UpdateYaw(float yaw);

	//void SetPos(float posX, float posY, float posZ);
	
	//void UpdateVelocity(Vector3D camVelocity);

	void UpdateVelocity(float velX, float velY, float velZ);

	//void SetVelocity(float velX, float velY, float velZ);

	float GetPitch();

	void SetPitch(float pitch);


protected:

	CameraModel m_camera;

	Vector3D m_lookAt;

	float m_cameraHeight;

	float m_pitch;

	//float m_pitch;
	//Vector3D m_PlayerCameraPosition;
	//Vector3D m_PlayerCameraLookAt;
	//Vector3D m_velocity;
	//float m_yaw;

private:


	int m_Health;
	State *m_CurrentState;
};

#endif 