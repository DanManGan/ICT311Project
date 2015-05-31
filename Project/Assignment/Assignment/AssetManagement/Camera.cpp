
#include "camera.h"
#include "../Extras/MathExtra.h"

#include <iostream>

//--------------------------------------------------------------------------------------

Camera::Camera()
{
	position = Vector3D(0.0f, 0.0f, 0.0f);
	lookAt = Vector3D(0.0f, 0.0f, 1.0f);

	velocity = Vector3D(0.0f, 0.0f, 0.0f);

	yaw = 0.0f;
	pitch = 0.0f;
}

//--------------------------------------------------------------------------------------

Camera::~Camera()
{
}

//--------------------------------------------------------------------------------------

void Camera::MoveToNow(float x, float y, float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

//--------------------------------------------------------------------------------------

void Camera::MoveToNow(const Vector3D& pos)
{
	position = pos;
}

//--------------------------------------------------------------------------------------

void Camera::Animate(float deltaTime)
{
     if ((yaw >= 360.0f) || (yaw <= -360.0f))
          yaw = 0.0f;

     if (pitch > 60.0f)
          pitch = 60.0f;
     if (pitch < -60.0f)
          pitch = -60.0f;
     
	// calculate trig functions
     float cosYaw = (float)cos(DEG_TO_RAD(yaw));
     float sinYaw = (float)sin(DEG_TO_RAD(yaw));
     float sinPitch = (float)sin(DEG_TO_RAD(pitch));
	 
	// speed is velocity z-component
     float speed = velocity.z * deltaTime;

	// strafe speed is velocity x-component
     float strafeSpeed = velocity.x * deltaTime;

	// speed limit
     if (speed > 1.0f)
          speed = 1.0f;
     if (strafeSpeed > 1.0f)
          strafeSpeed = 1.0f;
     if (speed < -1.0f)
          speed = -1.0f;
     if (strafeSpeed < -1.0f)
          strafeSpeed = -1.0f;

	 //std::cout << "Speed: " << speed << std::endl;
	 //std::cout << "StrafeSpeed: " << strafeSpeed << std::endl;

	// calculate new position of camera
     position.x += float(cos(DEG_TO_RAD(yaw + 90.0f)))*strafeSpeed;
     position.z += float(sin(DEG_TO_RAD(yaw + 90.0f)))*strafeSpeed;
     position.x += float(cosYaw)*speed;
     position.z += float(sinYaw)*speed;

	// calculate lookAt based on new position
     lookAt.x = float(position.x + cosYaw);
     lookAt.y = float(position.y + sinPitch);
     lookAt.z = float(position.z + sinYaw);
}
