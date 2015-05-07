
/** 
  * @class BruteForce
  * @brief Class to implement Terrain class
  * 
  * Class provides a Render method to render terrain class
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

#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "Terrain.h"

class BruteForce : public Terrain
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
	BruteForce();

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
	~BruteForce();

	/** 
	  * @brief Render method
	  * @warning None
	  * 
	  * Passes terrain data to graphics API for rendering
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Render();
};

#endif