
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

#ifndef TERRAINMODEL_H
#define TERRAINMODEL_H

#include "../GameObjects/Terrain.h"

class TerrainModel : public Terrain
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
	TerrainModel();

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
	~TerrainModel();

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