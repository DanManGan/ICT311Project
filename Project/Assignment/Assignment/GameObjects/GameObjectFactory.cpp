
#include "GameObjectFactory.h"
#include "Model.h"
#include "NPC.h"
#include "Player.h"

GameObjectFactory::GameObjectFactory()
{
    m_factory.Register(new FactoryMaker<Model, GameObject>);
    m_factory.Register(new FactoryMaker<NPC, GameObject>);
    m_factory.Register(new FactoryMaker<Player, GameObject>);
}