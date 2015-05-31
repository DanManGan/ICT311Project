
#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H


#include "../Extras/ExtensibleFactory.h"
#include "GameObject.h"

#include <map>
#include <string>

class GameObjectFactory
{
public:
	GameObjectFactory();

	~GameObjectFactory();

	GameObject* Create(std::string object); 

private:

	ExtensibleFactory<GameObject> m_factory;

	//std::map<std::string, GameObject*> m_objects;
};

#endif