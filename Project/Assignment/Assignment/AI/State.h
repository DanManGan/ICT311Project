#ifndef STATE_H
#define STATE_H

#include "../GameObjects/GameObject.h"

class State
{
public:
	virtual ~State() {}

	virtual void Enter(GameObject *obj) = 0;

	virtual void Execute(GameObject *obj) = 0;

	virtual void Exit(GameObject *obj) = 0;
};

#endif
