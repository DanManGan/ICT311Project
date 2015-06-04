
/** 
  * @class State
  * @brief class for fsm states
  * 
  * Detailed
  * 
  * 
  * 
  * 
  * @author Dan Manganaro
  * @version 01
  * @date 03.06.15
  * @status 
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
