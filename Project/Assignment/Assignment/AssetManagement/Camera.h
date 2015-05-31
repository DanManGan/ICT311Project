
/** 
  * @class Camera
  * @brief Camera class to handle camera position & view
  * 
  * Camera class to handle camera postion and look at vectors
  * 
  * 
  * 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 20.04.15
  * @status under construction
  * 
  * @author 
  * @version 
  * @date 
  * @status 
  * 
  * @todo 
  * 
  * @bugs 
  */ 

#ifndef CAMERA_H
#define CAMERA_H

#include "../Extras/Vector3D.h"

class Camera
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
	Camera();

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
	~Camera();

	/** 
	  * @brief Move camera to position
	  * @warning None
	  * 
	  * Moves camera to the postion specified in the vector
	  * 
	  * @param pos: const Vec3 type variable in Camera class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void MoveToNow(const Vector3D& pos);

	/** 
	  * @brief Move camera to position
	  * @warning None
	  * 
	  * Moves camera to the postion specified by the x,y,z coordinates
	  * 
	  * @param x: float type variable in Camera class for x position
	  * @param y: float type variable in Camera class for y position
	  * @param z: float type variable in Camera class for z position
	  * 
	  * @pre 
	  * @post 
	  */ 
	void MoveToNow(float x, float y, float z);

	/** 
	  * @brief Moves and rotates camera
	  * @warning None
	  * 
	  * Moves and rotates camera according to the position and lookat vecotrs
	  * 
	  * @param deltaTime: float type variable in Camera class for time
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Animate(float deltaTime);

	/** 
	  * @brief Camera Position
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vector3D position;

	/** 
	  * @brief Camera move velocity
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vector3D velocity;

	/** 
	  * @brief Camera lookat vector
	  * @warning None
	  * 
	  *  
	  * @pre 
	  * @post 
	  */ 
	Vector3D lookAt;

	/** 
	  * @brief Camera Yaw angle
	  * @warning None
	  * 
	  *  
	  * @pre 
	  * @post 
	  */ 
	float yaw;

	/** 
	  * @brief Camera Pitch angle
	  * @warning None
	  * 
	  *  
	  * @pre 
	  * @post 
	  */ 
	float pitch;

private:

};

#endif