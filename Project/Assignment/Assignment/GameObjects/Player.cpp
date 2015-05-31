#include "Player.h"

#include "../Singletons.h"

Player::Player() :
	m_camera(CameraModel()),
	m_cameraHeight(15.0f)
{
	//m_PlayerCameraPosition.x = 0.0f;
	//m_PlayerCameraPosition.y = 0.0f;
	//m_PlayerCameraPosition.z = 0.0f;
	//m_PlayerCameraLookAt.x = 0.0f;
	//m_PlayerCameraLookAt.y = 0.0f;
	//m_PlayerCameraLookAt.z = 0.0f;
	//m_camera.pitch = -75.0f;
}

Player::~Player()
{

}

void Player::Initialise()
{

}

void Player::SetPosition(Vector3D newPos)
{
	float lastX, lastY, lastZ;
	lastX = m_camera.position.x;
	lastY = m_camera.position.y;
	lastZ = m_camera.position.z;

	m_camera.position = newPos;
	m_camera.lookAt.x += (m_camera.position.x - lastX);
	m_camera.lookAt.y += (m_camera.position.y - lastY);
	m_camera.lookAt.z += (m_camera.position.z - lastZ);

	float x, y, z;
	x = (newPos.x - m_Position.x);
	y = (newPos.y - m_Position.y);
	z = (newPos.z - m_Position.z);

	m_Position = newPos;
}

void Player::SetPos(float posX, float posY, float posZ)
{
	m_Position.Set(posX, posY, posZ);

	m_camera.position = m_Position;
}

void Player::Update()
{
	float lastX, lastY, lastZ;
	lastX = m_camera.position.x;
	lastY = m_camera.position.y;
	lastZ = m_camera.position.z;

	m_camera.lookAt.x += (m_camera.position.x - lastX);
	m_camera.lookAt.y += (m_camera.position.y - lastY);
	m_camera.lookAt.z += (m_camera.position.z - lastZ);
}

void Player::SetPlayerCameraLookAt(Vector3D lookAt)
{
	m_camera.lookAt = lookAt;
}

void Player::SetPlayerCameraPosition(Vector3D pos)
{
	m_camera.position = pos;
}

Vector3D Player::GetPlayerCameraPosition()
{
	return m_camera.position;
}

Vector3D Player::GetPlayerLookAt()
{
	return m_camera.lookAt;
}

void Player::SetHealth(int health)
{
	m_Health = health;
}

int Player::GetHealth()
{
	return m_Health;
}

void Player::ChangeState(State *newState) 
{
	m_CurrentState->Exit(this);
	m_CurrentState = newState;
	m_CurrentState->Enter(this);
}

void Player::Animate(float deltaT)
{
	//m_camera.position.y  += m_cameraHeight;
	m_camera.position.y = m_Position.y + m_cameraHeight;

	m_camera.Animate(deltaT);

	m_Position = m_camera.position;
}

void Player::UpdatePitch(float pitch)
{
	m_camera.pitch += pitch;
}

void Player::UpdateYaw(float yaw)
{
	//m_yaw -= yaw;
	m_camera.yaw -= yaw;
}

void Player::UpdateVelocity(Vector3D camVelocity)
{
	m_camera.velocity = camVelocity;

}

void Player::UpdateVelocity(float velX, float velY, float velZ)
{
	m_camera.velocity += Vector3D(velX, velY, velZ);

}

void Player::SetVelocity(float velX, float velY, float velZ)
{
	m_camera.velocity = Vector3D(velX, velY, velZ);

}

void Player::Render()
{
	m_camera.Render();
}