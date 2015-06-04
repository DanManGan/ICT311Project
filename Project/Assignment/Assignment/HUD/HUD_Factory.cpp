#include"HUD_Factory.h"
#include"HUD_Picture.h"
#include"HUD_Shape.h"

#include <algorithm>
#include <iostream>

HUD_Factory::HUD_Factory()
{
	m_factory.Register(new FactoryMaker<HUD_Shape, HUD_Element>);
	m_factory.Register(new FactoryMaker<HUD_Picture, HUD_Element>);
}

HUD_Factory::~HUD_Factory()
{
	m_factory.Unregister(HUD_Shape::GetClassType());
	m_factory.Unregister(HUD_Shape::GetClassType());
}

HUD_Element* HUD_Factory::Create(std::string object)
{
	std::transform(object.begin(), object.end(), object.begin(), ::toupper);

	std::cout << object << std::endl;

	return m_factory.Create(object);
}