
#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H


#include "../Extras/ExtensibleFactory.h"
#include "GameObject.h"

class GameObjectFactory
{
public:
	GameObjectFactory();

	~GameObjectFactory();

private:

	ExtensibleFactory<GameObject> m_factory;

};

#endif