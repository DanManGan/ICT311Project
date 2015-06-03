#include "Player.h"

#include "../Singletons.h"

Player::Player() :
	m_camera(CameraModel()),
		m_lookAt(10.0f, 10.0f, 10.0f),
	m_cameraHeight(15.0f),
	m_pitch(0.0f)
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

//
//void Player::SetPosition(Vector3D newPos)
//{
//	float lastX, lastY, lastZ;
//	lastX = m_Position.x;
//	lastY = m_Position.y;
//	lastZ = m_Position.z;
//
//	m_Position = newPos;
//	m_lookAt.x += (m_Position.x - lastX);
//	m_lookAt.y += (m_Position.y - lastY);
//	m_lookAt.z += (m_Position.z - lastZ);
//
//	float x, y, z;
//	x = (newPos.x - m_Position.x);
//	y = (newPos.y - m_Position.y);
//	z = (newPos.z - m_Position.z);
//
//	m_Position = newPos;
//}
//
//void Player::SetPos(float posX, float posY, float posZ)
//{
//	m_Position.Set(posX, posY, posZ);
//}

void Player::Update()
{
	float lastX, lastY, lastZ;
	lastX = m_Position.x;
	lastY = m_Position.y;
	lastZ = m_Position.z;

	m_lookAt.x += (m_Position.x - lastX);
	m_lookAt.y += (m_Position.y - lastY);
	m_lookAt.z += (m_Position.z - lastZ);
}

void Player::SetPlayerCameraLookAt(Vector3D lookAt)
{
	m_lookAt = lookAt;
}

//void Player::SetPlayerCameraPosition(Vector3D pos)
//{
//	m_Position = pos;
//}
//
//Vector3D Player::GetPlayerCameraPosition()
//{
//	return m_Position;
//}

Vector3D Player::GetPlayerLookAt()
{
	return m_lookAt;
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
	m_Position.y += m_cameraHeight;
	//std::cout << " Before Animate" << std::endl;
	//m_Position.Print();
	//m_velocity.Print();
	//m_lookAt.Print();

	
	m_camera.position = m_Position;
	m_camera.velocity = m_velocity;
	m_camera.lookAt = m_lookAt;
	m_camera.yaw = m_yaw;
	m_camera.pitch = m_pitch;

	//m_camera.Animate(deltaT);
	m_camera.Animate(deltaT);

	m_Position = m_camera.position;
	m_velocity = m_camera.velocity;
	m_lookAt = m_camera.lookAt;
	m_yaw = m_camera.yaw;
	m_pitch = m_camera.pitch;

	//std::cout << " After Animate" << std::endl;
	m_Position.Print();
	//m_velocity.Print();
	//m_lookAt.Print();

	//m_Position = m_camera.position;
	m_Position.y -= m_cameraHeight;
}

void Player::UpdatePitch(float pitch)
{
	m_pitch += pitch;
}

void Player::UpdateYaw(float yaw)
{
	//m_yaw -= yaw;
	//m_camera.yaw = m_yaw;
	m_yaw -= yaw;
}
//
//void Player::UpdateVelocity(Vector3D camVelocity)
//{
//	m_velocity = camVelocity;
//}

void Player::UpdateVelocity(float velX, float velY, float velZ)
{
	m_velocity += Vector3D(velX, velY, velZ);
}

void Player::Render()
{
	m_camera.Render(m_camera.position, m_camera.lookAt);
}

float Player::GetPitch()
{
	return m_pitch;
}

void Player::SetPitch(float pitch)
{
	m_pitch = pitch;
}