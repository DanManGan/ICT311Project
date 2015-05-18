#include "Player.h"

Player::Player()
{
	m_PlayerCameraPosition.x = 0;
	m_PlayerCameraPosition.y = 0;
	m_PlayerCameraPosition.z = 0;
	m_PlayerCameraLookAt.x = 0;
	m_PlayerCameraLookAt.y = 0;
	m_PlayerCameraLookAt.z = 0;
}

void Player::Initialise()
{

}

void Player::SetPosition(Vector3D newPos)
{
	float lastX, lastY, lastZ;
	lastX = m_PlayerCameraPosition.x;
	lastY = m_PlayerCameraPosition.y;
	lastZ = m_PlayerCameraPosition.z;

	m_PlayerCameraPosition = newPos;
	m_PlayerCameraLookAt.x += (m_PlayerCameraPosition.x - lastX);
	m_PlayerCameraLookAt.y += (m_PlayerCameraPosition.y - lastY);
	m_PlayerCameraLookAt.z += (m_PlayerCameraPosition.z - lastZ);

	float x, y, z;
	x = (newPos.x - m_Position.x);
	y = (newPos.y - m_Position.y);
	z = (newPos.z - m_Position.z);

	m_Position = newPos;
}

void Player::Update()
{
	float lastX, lastY, lastZ;
	lastX = m_PlayerCameraPosition.x;
	lastY = m_PlayerCameraPosition.y;
	lastZ = m_PlayerCameraPosition.z;

	m_PlayerCameraLookAt.x += (m_PlayerCameraPosition.x - lastX);
	m_PlayerCameraLookAt.y += (m_PlayerCameraPosition.y - lastY);
	m_PlayerCameraLookAt.z += (m_PlayerCameraPosition.z - lastZ);
}

void Player::SetPlayerCameraLookAt(Vector3D lookAt)
{
	m_PlayerCameraLookAt = lookAt;
}

void Player::SetPlayerCameraPosition(Vector3D pos)
{
	m_PlayerCameraPosition = pos;
}

Vector3D Player::GetPlayerCameraPosition()
{
	return m_PlayerCameraPosition;
}

Vector3D Player::GetPlayerLookAt()
{
	return m_PlayerCameraLookAt;
}

void Player::SetHealth(int health)
{
	m_Health = health;
}

int Player::GetHealth()
{
	return m_Health;
}