
#include "camera.h"
#include "MathExtra.h"

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
     if (speed > 10.0f)
          speed = 10.0f;
     if (strafeSpeed > 10.0f)
          strafeSpeed = 10.0f;
     if (speed < -10.0f)
          speed = -10.0f;
     if (strafeSpeed < -10.0f)
          strafeSpeed = -10.0f;

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

/////////////////////////////////////////////////////////////////////////////////////

/*
Camera::Camera(vector3D *look)
{
	position = vector3D(0.0, 0.0, 0.0);
	lookAt = look->UnitVector();

	forward = lookAt;
	up = vector3D(0.0, 1.0, 0.0);
	right = forward.CrossProduct(up); //vector3D(1.0, 0.0, 0.0);

	velocity = vector3D(0.0, 0.0, 0.0);
	acceleration = vector3D(0.0, 0.0, 0.0);	

	yaw = 0.0;
	pitch = 0.0;
}
*/
/*
Camera::Camera(vector3D *pos, vector3D *look)
{
	position = *pos;
	lookAt = look->UnitVector();

	forward = lookAt;
	up = vector3D(0.0, 1.0, 0.0);
	right = vector3D(1.0, 0.0, 0.0);

	velocity = vector3D(0.0, 0.0, 0.0);
	acceleration = vector3D(0.0, 0.0, 0.0);

	yaw = 0.0;
	pitch = 0.0;
}
*/


void Camera::UpdateLookAt()
{
	Vector3D look = Vector3D(finalLookAt.x - lookAt.x,
					   finalLookAt.y - lookAt.y,
					   finalLookAt.z - lookAt.z);

	lookAtVel = look * 0.5;
}

void Camera::UpdateMoveTo()
{
	Vector3D pos = Vector3D(finalPosition.x - position.x,
					  finalPosition.y - position.y,
					  finalPosition.z - position.z);

	velocity = pos * 0.5;
}


void Camera::RotatePitch(float radians)
{
	float sine = sinf(radians);
	float cosine = cosf(radians);

	up.y = cosine * up.Length();
	up.z = sine * up.Length();

	forward.y = -sine * forward.Length();
	forward.z = cosine * forward.Length();
	/*     x   y      z       p
         |  1  0       0       0 |
     M = |  0  cos(A) -sin(A)  0 |
         |  0  sin(A)  cos(A)  0 |
         |  0  0       0       1 |
	*/
}

void Camera::RotateYaw(float radians)
{
	float sine = sinf(radians);
	float cosine = cosf(radians);
	
	right.x = cosine * right.Length();
	right.z = sine * right.Length();

	forward.x = -sine * forward.Length();
	forward.z = cosine * forward.Length();
	
	/*	   x      y    z      p
         |  cos(A)  0  -sin(A)  0 |
     M = |  0       1   0       0 |
         |  sin(A)  0   cos(A)  0 |
         |  0       0   0       1 |
	*/

}

void Camera::RotateRoll(float radians)
{
	float sine = sinf(radians);
	float cosine = cosf(radians);
	
	right.x = cosine * right.Length();
	right.y = sine * right.Length();

	up.x = -sine * forward.Length();
	up.y = cosine * forward.Length();
	/*
         |  cos(A)  -sin(A)   0   0 |
     M = |  sin(A)   cos(A)   0   0 |
         |  0        0        1   0 |
         |  0        0        0   1 |
	*/
}

void Camera::LookAtNow( Vector3D& pos)
{
	lookAt = pos;
}

// look at an object over time
void Camera::LookAt(const Vector3D& pos)
{
	Vector3D v = Vector3D(pos - lookAt);

	initLookAt = lookAt;
	finalLookAt = pos;

	lookAtAccel =  -lookAt * 0.25f;

	UpdateLookAt();
}

// move to an object over time
void Camera::MoveTo(const Vector3D& pos)
{
	Vector3D v = Vector3D(pos - position);

	initPosition = position;
	finalPosition = pos;

	acceleration = -position * 0.25f;

	UpdateMoveTo();
}
