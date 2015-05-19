#ifndef NPC_H
#define NPC_H

#include "GameObject.h"

class NPC :public GameObject
{
public:
	NPC();

	virtual void Initialise();
	virtual void Update();
protected:
private:
	int m_Health;
};

#endif