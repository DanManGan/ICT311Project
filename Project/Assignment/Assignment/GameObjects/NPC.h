#ifndef NPC_H
#define NPC_H

#include "GameObject.h"

class NPC :public GameObject
{
public:
	NPC();

	virtual void Initialise();
	virtual void Update();

	virtual void Render();

protected:
private:
	int m_Health;
};

#endif