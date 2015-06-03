
#include "Movement.h"
#include "../Extras/MathExtra.h"

#include <iomanip>

#include <iostream>

Movement::Movement() :
	m_wanderRadius(0),
	m_wanderDistance(0),
	m_wanderJitter(0)
{

}


/*********************************************************************************************
* Moves an object located at curpos and travelling at curVelocity towards targetPos. This    *
* function changes the curPos and curVelocity to steer it towards targetPos over time. The   *
* time factor is specified by timeElasped which should be the current time in the game loop  *
* timer. 20ms is a reasonable update time.                                                   *
* Pre: all vars are assigned values.                                                         *
* Post: curPos and curVelocity are updated to incrementally move towards targetPos. curPos   *
*       will be equal to targetPos if the object has reached the target.                     *
* Variables: curPos is the position vector of the current agent.                             *
*            targetPos is the vector of the target position.                                 *
*            curVelocity is the current velocity of the agent.                               *
*            timeElaspsed is the time elaspsed since last logic update.                      *
*            offset is the distance to stop prior to reaching the target.                    *
*********************************************************************************************/
bool Movement::MoveTo(Vector3D &curPos, const Vector3D& targetPos,Vector3D& curVelocity, float timeElapsed,float offset)
{ 
	//std::cout << " MOVE TO START" << std::endl;
	//std::cout << "curPos" << std::endl;
	//curPos.Print();
	//std::cout << "curVelocity" << std::endl;
	//curVelocity.Print();
	//std::cout << "time: " << timeElapsed << std::endl;
	// calculate the heading from the character position to target
	Vector3D toTarget = targetPos - curPos;
	
	//std::cout << "toTarget" << std::endl;
	//toTarget.Print();
	//std::cout << "target x: " << toTarget.x << " y: " << toTarget.y << " z: " << toTarget.z << std::endl;
	toTarget.Normalise();

	//std::cout << "toTarget normalised" << std::endl;
	//toTarget.Print();
	if (toTarget.IsZero())
		return true;
	// calculate new velocity and new character position
	curVelocity = toTarget * curVelocity.Length();

	Vector3D displacement = curVelocity*timeElapsed;
	Vector3D newPos = curPos+displacement;
	//std::cout << "newPos x: " << newPos.x << " y: " << newPos.y << " z: " << newPos.z << std::endl;
	// calculate real target position
	Vector3D realTargetPos = targetPos - toTarget * offset;
	// calculate the direction from newPos to realTargetPos
	//std::cout << "toRealTarget" << std::endl;
	Vector3D toRealTarget = realTargetPos - newPos;
	//toRealTarget.Print();
	//std::cout << "toRealTarget x: " << toRealTarget.x << " y: " << toRealTarget.y << " z: " << toRealTarget.z << std::endl;

	//Vector3D test(12, 12, 12);
	//std::cout << "test" << std::endl;
	//test.Print();
	//test.Normalise();
	//std::cout << "test normalised" << std::endl;
	//test.Print();

	//std::cout << "toRealTarget normalise" << std::endl;
	toRealTarget.Normalise();
	if (toRealTarget.IsZero()) {
		curPos = realTargetPos;
		return true;
	}
	// check to see whether newPos has gone passed the realTargetPos
	float dp = toRealTarget.DotProduct(toTarget); // dot product of two vectors
	if (dp<0.0F) { // newPos has passed realTargetPos, as their angle >90 degree
		curPos = realTargetPos; // step back to realTargetPos
		return true;
	}
	// newPos has not yet passed realTargetPos
	curPos = newPos; // update character position
	//std::cout << "new x: " << curPos.x << " y: " << curPos.y << " z: " << curPos.z << std::endl;
	return false;

}

//bool Movement::MoveTo(Vector3D* curPos, const Vector3D& targetPos,Vector3D* curVelocity, float timeElapsed,float offset)
//{ 
//// calculate the heading from the character position to target
//Vector3D toTarget = targetPos - curPos;
//toTarget.Normalise();
//if (toTarget.IsZero())
//return true;
//// calculate new velocity and new character position
//curVelocity = toTarget * curVelocity->Length();
//Vector3D displacement = curVelocity*timeElapsed;
//Vector3D newPos = curPos+displacement;
//// calculate real target position
//Vector3D realTargetPos = targetPos - toTarget * offset;
//// calculate the direction from newPos to realTargetPos
//Vector3D toRealTarget = realTargetPos - newPos;
//toRealTarget.Normalise();
//if (toRealTarget.IsZero()) {
//*curPos = realTargetPos;
//return true;
//}
//// check to see whether newPos has gone passed the realTargetPos
//float dp = toRealTarget.DotProduct(toTarget); // dot product of two vectors
//if (dp<0.0F) { // newPos has passed realTargetPos, as their angle >90 degree
//curPos = realTargetPos; // step back to realTargetPos
//return true;
//}
//// newPos has not yet passed realTargetPos
//curPos = newPos; // update character position
//return false;
//
//}

bool Movement::Flee(Vector3D &curPos, const Vector3D& pursuerPos,Vector3D& curVelocity,  float fleeSpeed, float timeElapsed)
{ 
 Vector3D fromPursuer;
 float panicDistSq=100.0*100.0;

   fromPursuer=curPos-pursuerPos;
   float temp = ((fromPursuer.x * fromPursuer.x) + (fromPursuer.z * fromPursuer.z));

     //if(fromPursuer.LengthSqr()>panicDistSq)
   if(temp>panicDistSq)
		 return false;    //pursuer not in panic range

  fromPursuer.Normalise();                       //get heading
  curVelocity=fromPursuer*fleeSpeed;  //new velocity
  curPos+=curVelocity*timeElapsed;             //pos = vt
  return true;
}

void Movement::Pursue( Vector3D &evaderPos, Vector3D& pursuerPos, Vector3D& evaderVelocity, Vector3D& pursuerVelocity, float timeElapsed,float offset)
{
 float lookAheadTime;
 //distance between evader and pursuer
 Vector3D toEvader=evaderPos-pursuerPos;	
 //compute agent headings
 Vector3D pursuerHeading=pursuerVelocity;
 pursuerHeading.Normalise();
 Vector3D evaderHeading=evaderVelocity;
 evaderHeading.Normalise();
 //compute angle between agents
 float relativeHeading=pursuerHeading.DotProduct(evaderHeading);
    //determine if evader is facing pursuer - note .95 radians =18 degrees
 if(((toEvader.DotProduct(pursuerHeading)>0) && relativeHeading <-0.95) || evaderVelocity.Length()==1)
	{
		MoveTo(pursuerPos,evaderPos,pursuerVelocity,timeElapsed,offset);
	}
	else
	{
	 lookAheadTime=(toEvader.Length())/(evaderVelocity.Length()+pursuerVelocity.Length());
	 MoveTo(pursuerPos,evaderPos+evaderVelocity*lookAheadTime,pursuerVelocity,timeElapsed,offset);
	}
}

bool Movement::Evade(Vector3D &evaderPos, Vector3D& pursuerPos,Vector3D& evaderVelocity, Vector3D& pursuerVelocity, float timeElapsed)
{
 //distance between pursuer and evader
 Vector3D toPursuer=pursuerPos-evaderPos;
 float lookaheadTime=toPursuer.Length()/(evaderVelocity.Length()+pursuerVelocity.Length());
 return(Flee(evaderPos,pursuerPos+pursuerVelocity*lookaheadTime,evaderVelocity,evaderVelocity.Length(),timeElapsed));
}

//fov in degrees not radians
bool Movement::SeeTarget(Vector3D &patroller, Vector3D& target, Vector3D &patrollerVel,float coneDistance, float fov)
{
	//vector between patroller and target
	Vector3D toTarget = target-patroller;
	//distance between patroller and target
	float dist=toTarget.Length();	  
	if(dist>coneDistance)
		  return false;
	//get heading to target
	toTarget.Normalise();
	Vector3D patrollerHeading=patrollerVel;
	//get patrollers current heading
	patrollerHeading.Normalise();
	//compute angle between patroller and target
	float angle=(float)patrollerHeading.DotProduct(toTarget);
	  //getting some precision problem ensure cos angle is in -1.0 to 1.0
	  if(angle>1.0)
		  angle=1.0;
	  else if(angle<-1.0)
	      angle=-1.0;
    angle=RAD_TO_DEG(acos(angle)); //get heading in degrees
	//determine if target is in fov
	if(angle <=(fov/2))
		return true;
 return false;
}


    inline float randFloat()      
	{
		return ((rand())/(RAND_MAX+1.0f));
	}
    
	//returns a random float in the range -1 < n < 1
    inline float randomClamped()    
	{
		return randFloat() - randFloat();
	}


void Movement::SetWander(float m_wanderRadius,float m_wanderDistance,float m_wanderJitter)
{
	this->m_wanderRadius=m_wanderRadius;
	this->m_wanderDistance=m_wanderDistance;
	this->m_wanderJitter=m_wanderJitter;
	float theta = ((rand())/(RAND_MAX+1.0f)) * (2*PI);
	wanderTarget.Set(m_wanderRadius * cos(theta), 0, m_wanderRadius * sin(theta));
}

//--------------------------- Wander -------------------------------------
//
//  This behavior makes the agent wander about randomly
//   does not wander on the z axis
//------------------------------------------------------------------------
bool Movement::Wander( Vector3D &position, Vector3D &velocity,float deltaT)
{ 
  //this behavior is dependent on the update rate, so this line must
  //be included when using time independent framerate.
  float jitterThisTimeSlice = m_wanderJitter * deltaT;
  //first, add a small random vector to the target's position
  wanderTarget += Vector3D(randomClamped() * jitterThisTimeSlice, 0, randomClamped() * jitterThisTimeSlice);
  //reproject this new vector back on to a unit circle
  wanderTarget.Normalise();
  Vector3D heading(velocity);
  heading.Normalise();
  Vector3D wanderCircleWorldCentre=position+(heading* m_wanderDistance);
  Vector3D targetWorld=wanderCircleWorldCentre+( wanderTarget * m_wanderRadius);
  MoveTo(position, targetWorld,velocity, deltaT,0);
return true;
}

float Movement::CalcYaw(Vector3D patroller, Vector3D target, Vector3D patrollerVel)
{

	Vector3D toTarget = target-patroller;

	float angle = patrollerVel.GetHeadingDegrees();

	return angle;
}


