
#include "GameObjectFactory.h"
#include "GameObject.h"
#include "Model.h"
#include "NPC.h"
#include "Player.h"

#include <algorithm>
#include <iostream>

GameObjectFactory::GameObjectFactory()
{
    m_factory.Register(new FactoryMaker<Model, GameObject>);
    m_factory.Register(new FactoryMaker<NPC, GameObject>);
    m_factory.Register(new FactoryMaker<Player, GameObject>);
}

GameObjectFactory::~GameObjectFactory()
{
	m_factory.Unregister(Model::GetClassType());
	m_factory.Unregister(NPC::GetClassType());
	m_factory.Unregister(Player::GetClassType());
}

GameObject* GameObjectFactory::Create(std::string object)
{
	//GameObject* obj = m_factory.Create(object);

	//if(obj) {
	//	m_objects[name] = obj;
	//	return true;
	//}
	//return false;

	std::transform(object.begin(), object.end(), object.begin(), ::toupper);

	std::cout << object << std::endl;

	return m_factory.Create(object);
}