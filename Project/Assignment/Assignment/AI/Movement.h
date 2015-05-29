#ifndef __MOVEMENT_H
#define __MOVEMENT_H

#include "../Extras/Vector3D.h"
//#include "vector/vector.h"

class Movement
{
private:
Vector3D wanderTarget;
float m_wanderRadius;
float m_wanderDistance;
float m_wanderJitter;

public:

	Movement();
/*********************************************************************************************
* Moves an object located at curpos and travelling at curVelocity towards targetPos. This    *
* function changes the curPos and curVelocity to steer it towards targetPos over time. The   *
* time factor is specified by timeElasped which should be the current time in the game loop  *
* timer. 20ms is a reasonable update time.                                                   *
* Pre: all vars are assigned values.                                                         *
* Post: curPos and curVelocity are updated to incrementally move towards targetPos. curPos   *
*       will be equal to targetPos if the object has reached the target.                     *
* Returns: true if target has reached targetPos, otherwise false.                            *
*********************************************************************************************/
bool MoveTo(Vector3D &curPos,const Vector3D& targetPos,Vector3D& curVelocity, float timeElapsed,float offset=0);
//bool MoveTo(Vector3D* curPos,const Vector3D& targetPos,Vector3D* curVelocity, float timeElapsed,float offset=0);
bool Flee(Vector3D &curPos,  const Vector3D& pursuerPos,Vector3D& curVelocity, float fleeSpeed, float timeElapsed);
void Pursue( Vector3D &evaderPos, Vector3D& pursuerPos, Vector3D& evaderVelocity, Vector3D& pursuerVelocity, float timeElapsed,float offset);
bool Evade(Vector3D &evaderPos, Vector3D& pursuerPos,Vector3D& evaderVelocity, Vector3D& pursuerVelocity, float timeElapsed);
bool SeeTarget( Vector3D &patroller, Vector3D& target,  Vector3D &patrollerVel,float coneDistance, float coneRadius);
void SetWander(float m_wanderRadius,float m_wanderDistance,float m_wanderJitter);
bool Wander( Vector3D &position, Vector3D &velocity, float deltaT);

///////////////////////////////////////////////////////////

float CalcYaw( Vector3D patroller, Vector3D target,  Vector3D patrollerVel);
};
#endif