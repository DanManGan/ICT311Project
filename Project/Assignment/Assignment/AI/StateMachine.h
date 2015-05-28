#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <lua.h>
#include <luabind\luabind.hpp>

template <class T>
class StateMachine
{
public:
	StateMachine(T* obj)
	{
		m_Object = obj;
	};

	StateMachine()
	{
		m_Object = NULL;
	}

	void SetCurrentState(const luabind::object* state { m_CurrentState = state; }
	void SetGlobalState(const luabind::object* state { m_GlobalState = state; m_GlobalState["Enter"](m_Object); }
	
	void Update()
	{
		if(m_GlobalState.is_valid())
			m_GlobalState["Execute"](m_Object);
		if(m_CurrentState.is_valid())
			m_CurrentState["Execute"](m_Object);
	}

	void ChangeState(const luabind::object& newState)
	{
		if(m_CurrentState.is_valid())
		{
			m_PreviousState = m_CurrentState;
			m_CurrentState["Exit"](m_Object);
		}

		m_CurrentState = newState;
		m_CurrentState["Enter"](m_Object);
	}

	void RevertToPreviousState()
	{
		m_CurrentState = m_PreviousState;
	}

	luabind::object& GetPreviousState() { return m_PreviousState; }
	luabind::object& GetCurrentState() { return m_CurrentState; }
	luabind::object& GetGlobalState() { return m_GlobalState; }


	virtual ~StateMachine() {};

private:
	T* m_Object;
	luabind::object m_PreviousState;
	luabind::object m_CurrentState;
	luabind::object m_GlobalState;
};

#endif