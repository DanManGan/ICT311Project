
/** 
  * @class Movement
  * @brief class to handle 3D movement
  * 
  * Handles 3D movement
  * 
  * 
  * 
  * 
  * @author Hong Xie??
  * @version 00
  * @date 
  * @status 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 03.06.15
  * @status complete
  * 
  * @todo 
  * 
  * @bugs 
  */ 


#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "../Extras/Vector3D.h"

class Movement
{
public:

	/** 
	  * @brief Default constructor
	  * @warning None
	  * 
	  * Default class constructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	Movement();

	/** 
	  * @brief Default destructor
	  * @warning None
	  * 
	  * Default class destructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	~Movement();

	/** 
	  * @brief move object in 3D world
	  * @warning None
	  * 
	  * Moves an object located at curpos and travelling at curVelocity towards targetPos.
	  * 
	  * @param curPos: Vector3D type variable in Movement class for object current position
	  * @param targetPos: const Vector3D type variable in Movement class for target position 
	  * @param curVelocity: Vector3D type variable in Movement class for object velocity
	  * @param timeElapsed: float type variable in Movement class for time
	  * @param offset: float type variable in Movement class for offset from target
	  * @return bool value true when at target
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool MoveTo(Vector3D &curPos,const Vector3D& targetPos,Vector3D& curVelocity, float timeElapsed,float offset=0);
	
	/** 
	  * @brief moves object away from target
	  * @warning None
	  * 
	  * moves a 3D object away from a pursuer
	  * 
	  * @param curPos: Vector3D type variable in Movement class for object position
	  * @param pursuerPos: const Vector3D type variable in Movement class for pursure position
	  * @param curVelocity: Vector3D type variable in Movement class for obvject velocity
	  * @param fleeSpeed: float type variable in Movement class for object flee speed
	  * @param timeElapsed: float type variable in Movement class for time
	  * @return bool value true while pursuer still in ranage
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool Flee(Vector3D &curPos,  const Vector3D& pursuerPos,Vector3D& curVelocity, float fleeSpeed, float timeElapsed);
	
	/** 
	  * @brief chase a target
	  * @warning None
	  * 
	  * moves a 3D object to chase a target
	  * 
	  * @param evaderPos: Vector3D type variable in Movement class for targetr pos
	  * @param pursuerPos: Vector3D type variable in Movement class for pursuer position
	  * @param evaderVelocity: Vector3D type variable in Movement class for target velocity
	  * @param pursuerVelocity: Vector3D type variable in Movement class for pursuer velocoity
	  * @param timeElapsed: float type variable in Movement class for time
	  * @param offset: float type variable in Movement class for offset from target
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Pursue( Vector3D &evaderPos, Vector3D& pursuerPos, Vector3D& evaderVelocity, Vector3D& pursuerVelocity, float timeElapsed,float offset);
	
	/** 
	  * @brief evade a pursuer
	  * @warning None
	  * 
	  * moves a 3D object to avoid a pursuer
	  * 
	  * @param evaderPos: Vector3D type variable in Movement class for targetr pos
	  * @param pursuerPos: Vector3D type variable in Movement class for pursuer position
	  * @param evaderVelocity: Vector3D type variable in Movement class for target velocity
	  * @param pursuerVelocity: Vector3D type variable in Movement class for pursuer velocoity
	  * @param timeElapsed: float type variable in Movement class for time
	  * @return bool value for still being chased
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool Evade(Vector3D &evaderPos, Vector3D& pursuerPos,Vector3D& evaderVelocity, Vector3D& pursuerVelocity, float timeElapsed);
	
	/** 
	  * @brief t6st to see if a target is visible
	  * @warning None
	  * 
	  * tests to see if an object is visible
	  * 
	  * @param patroller: Vector3D type variable in Movement class for positin
	  * @param target: Vector3D type variable in Movement class for target position
	  * @param patrollerVel: Vector3D type variable in Movement class for object velosity
	  * @param coneDistance: float type variable in Movement class 
	  * @param coneRadius: float type variable in Movement class 
	  * @return bool value if in sight
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool SeeTarget( Vector3D &patroller, Vector3D& target,  Vector3D &patrollerVel,float coneDistance, float coneRadius);
	
	/** 
	  * @brief set wander variables
	  * @warning None
	  * 
	  * set wander variables
	  * 
	  * @param m_wanderRadius: float type variable in Movement class for wander radius
	  * @param m_wanderDistance: float type variable in Movement class for wander distance
	  * @param m_wanderJitter: float type variable in Movement class for jitterness
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetWander(float m_wanderRadius,float m_wanderDistance,float m_wanderJitter);

	/** 
	  * @brief wander randomly
	  * @warning None
	  * 
	  * makes object wandetr randomly
	  * 
	  * @param position: Vector3D type variable in Movement class for object position
	  * @param velocity: Vector3D type variable in Movement class for object velocity
	  * @param deltaT: float type variable in Movement class for time
	  * @return bool value true value always
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool Wander( Vector3D &position, Vector3D &velocity, float deltaT);

	/** 
	  * @brief 
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param patroller: Vector type variable in Movement class 
	  * @param target: Vector type variable in Movement class 
	  * @param patrollerVel: Vector type variable in Movement class 
	  * @return float value 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float CalcYaw( Vector3D patroller, Vector3D target,  Vector3D patrollerVel);

private:

	/** 
	  * @brief target for wander 
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vector3D wanderTarget;

	/** 
	  * @brief radius for wander
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float m_wanderRadius;

	/** 
	  * @brief distance for wander
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float m_wanderDistance;

	/** 
	  * @brief jitter value for wander
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float m_wanderJitter;
};
#endif