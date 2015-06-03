#ifndef STATEMACHINE_H
#define STATEMACHINE_H

//#include <lua.hpp>
//#include <luabind\luabind.hpp>

#include <lua\lua.hpp>
#include <luabind\luabind.hpp>

template <class T>
class StateMachine
{
public:
	StateMachine(T* obj)
	{
		std::cout << "StateMachine constructor" << std::endl;
	//getchar();
		m_Object = obj;
	};

	StateMachine()
	{
		m_Object = NULL;
	}

	//use the following methods to intialise the FSM
	void SetPreviousState(const luabind::object& state){m_PreviousState=state;} 
	void SetCurrentState(const luabind::object& state) { m_CurrentState = state; }
	void SetGlobalState(const luabind::object& state) { m_GlobalState = state; /*m_GlobalState["Enter"](m_Object);*/ }
	
	void Update()
	{
		std::cout << "Update Called" << std::endl;
		if(m_GlobalState.is_valid()) {
			m_GlobalState["Execute"](m_Object);
			//std::cout << "Global State Called" << std::endl;
		}
		
		if(m_CurrentState.is_valid()) {
			m_CurrentState["Execute"](m_Object);
			//std::cout << "State Valid" << std::endl;
		}

	}

	void ChangeState(const luabind::object& newState)
	{
		std::cout << "in change State" << std::endl;
		
		//if(m_CurrentState.is_valid())
		//{
		//	m_PreviousState = m_CurrentState;
		//	m_CurrentState["Exit"](m_Object);
		//}

		//m_CurrentState = newState;
		//m_CurrentState["Enter"](m_Object);

		// if new state valid
		if(newState.is_valid()) {
			//save current state as previous state
			m_PreviousState = m_CurrentState;
			//call the exit function of the current state
			m_CurrentState["Exit"](m_Object);
			//change current state to newState
			m_CurrentState=newState;
			//call the Enter function of the new currentState
			m_CurrentState["Enter"](m_Object);
		}
	}

	void RevertToPreviousState()
	{
		//call the exit function of the current state
		m_CurrentState["Exit"](m_Object);
		//change current state to previous state
		m_CurrentState = m_PreviousState;
		//call the Enter function of the new currentState
		m_CurrentState["Enter"](m_Object);

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