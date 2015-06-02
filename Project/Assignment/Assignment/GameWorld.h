
/** 
  * @class GameWorld
  * @brief The 3D game world
  * 
  * Main 3D game world. The terrain exists in this class and
  * normally other models for the environment would be loaded here too.
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

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "Graphics/TerrainModel.h"
#include "AssetManagement/md2.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/GameObjectFactory.h"
#include "Graphics/Skybox.h"

#include <map>
#include <string>

#include <lua/lua.hpp>
#include <luabind/luabind.hpp>

class GameWorld
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
	GameWorld();

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
	~GameWorld();

    /** 
	  * @brief Load world object textures
	  * @warning None
	  * 
	  * Loads the textures to be used for the world objects
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void LoadAssets();

	/** 
	  * @brief Load World objects
	  * @warning None
	  * 
	  * Loads the world objects
	  * 
	  * @return bool value for successfull loading of objects
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool CreateTerrain();

	void CreateObjects();

	void LoadScripts();

	/** 
	  * @brief Call object render functions
	  * @warning None
	  * 
	  * Call the render functions for all world objects to be
	  * rendered to screen
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Render();

	/** 
	  * @brief Test position in world
	  * @warning None
	  * 
	  * Tests the 2 variables passed in for location 
	  * within the game world
	  * 
	  * @param x: float type variable in GameWorld class for x axis
	  * @param z: float type variable in GameWorld class for z axis
	  * @return bool value true if in world , false if outside and relocated back in
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool InWorld(float& x, float& z);

	bool InWorld(GameObject* obj);

	GameObject* GetPlayer();

	/** 
	  * @brief Gets Terrain height at point
	  * @warning None
	  * 
	  * Returns the height of the terrain at the X,Z point passed in
	  * 
	  * @param x: float type variable in GameWorld class for x axis
	  * @param z: float type variable in GameWorld class for z axis
	  * @return float value for height at position
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetWorldXZHeight(float x, float z);

	/** 
	  * @brief Get world size
	  * @warning None
	  * 
	  * Returns the length/width of the terrain. Only returns 1 value
	  * becaause world is square.
	  * 
	  * @return float value for size of side
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetWorldSize();


/////////////////////////////////////////////////////////////////////////

	void Animate(float deltaT);

	void Update();

private:

	/** 
	  * @brief Terrain object
	  * @warning None
	  * 
	  * Object for the terrain class in the game world
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	TerrainModel* m_terrain;

	/**
	  * @brief copy constructor declaration.
	  * @warning None
	  * 
	  * Copy constructor declaration. Declared private so can't be called
	  * 
	  * @param : const GameWorld type variable in GameWorld class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	GameWorld(const GameWorld&);

	/** 
	  * @brief overloaded = operator
	  * @warning None
	  * 
	  * Overloaded = operator. Declared private so can't be called
	  * 
	  * @param : const GameWorld type variable in GameWorld class 
	  * @return GameWorld & value 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	GameWorld& operator=(const GameWorld&);

	//GameObject* ogro;

	//std::map<std::string, GameObject*> m_objects;

	typedef std::map<std::string, GameObject*> objects;
	typedef objects::iterator objIter;

	objects m_objects;

	GameObjectFactory m_objFactory;
	Skybox m_skybox; 

	lua_State* lState;
};


#endif