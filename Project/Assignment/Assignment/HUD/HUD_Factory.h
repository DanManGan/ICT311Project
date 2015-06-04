#ifndef HUD_FACTORY_H
#define HUD_FACTORY_H

#include"../Extras/ExtensibleFactory.h"
#include"HUD_Element.h"
#include<string>

class HUD_Factory
{
public:
	HUD_Factory();
	~HUD_Factory();

	HUD_Element* Create(std::string object);
private:
	ExtensibleFactory<HUD_Element> m_factory;
};

#endif