

/** 
  * @class StateMachine
  * @brief template to create playe states
  * 
  * Detailed
  * 
  * 
  * @param T: T type variable used for template values in StateMachine class
  *			for object tro be templated 
  * 
  * 
  * @author Justin Pettit & Daniel Manganaro
  * @version 01
  * @date 03.06.15
  * @status complete
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

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <lua\lua.hpp>
#include <luabind\luabind.hpp>

template <class T>
class StateMachine
{
public:

	/** 
	  * @brief Default templated constructor
	  * @warning None
	  * 
	  * Default class constructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	StateMachine(T* obj)
	{
		std::cout << "StateMachine constructor" << std::endl;
		m_Object = obj;
	};
	/** 
	  * @brief Default constructor
	  * @warning None
	  * 
	  * Default class constructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	StateMachine()
	{
		m_Object = NULL;
	}

	/** 
	  * @brief Default destructor
	  * @warning None
	  * 
	  * Default class destructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	virtual ~StateMachine() {};

	/** 
	  * @brief Set fsm previous state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param state: const luabind::object type variable in StateMachine class for previous state
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetPreviousState(const luabind::object& state){m_PreviousState=state;} 

	/** 
	  * @brief Set current fsm state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param state: const luabind::object type variable in StateMachine class for current state
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetCurrentState(const luabind::object& state) { m_CurrentState = state; }

	/** 
	  * @brief ste global fsm state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param state: const luabind::object type variable in StateMachine class for global state
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetGlobalState(const luabind::object& state) { m_GlobalState = state; /*m_GlobalState["Enter"](m_Object);*/ }
	
	/** 
	  * @brief fsm update method
	  * @warning None
	  * 
	  * Calls the execute function for the current and global state
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Update()
	{
		if(m_GlobalState.is_valid()) {
			//m_GlobalState["Execute"](m_Object);
		}
		
		if(m_CurrentState.is_valid()) {
			//m_CurrentState["Execute"](m_Object);
		}
	}

	/** 
	  * @brief changes fsm states
	  * @warning None
	  * 
	  * stes new and previous states based on new state passed in
	  * 
	  * @param newState: const luabind::object type variable in StateMachine class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void ChangeState(const luabind::object& newState)
	{
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

	/** 
	  * @brief Revert fsm to previous state
	  * @warning None
	  * 
	  * Revert to previous fsm state
	  * Note calls enter and exit function which may not be necessary
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void RevertToPreviousState()
	{
		//call the exit function of the current state
		m_CurrentState["Exit"](m_Object);
		//change current state to previous state
		m_CurrentState = m_PreviousState;
		//call the Enter function of the new currentState
		m_CurrentState["Enter"](m_Object);

	}

	/** 
	  * @brief Gets previous fsm state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @return luabind::object & value for state
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	luabind::object& GetPreviousState() { return m_PreviousState; }

	/** 
	  * @brief Gets current fsm state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @return luabind::object & value for state
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	luabind::object& GetCurrentState() { return m_CurrentState; }

	/** 
	  * @brief gets global fsm state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @return luabind::object & value for state
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	luabind::object& GetGlobalState() { return m_GlobalState; }

private:

	/** 
	  * @brief templated object
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	T* m_Object;

	/** 
	  * @brief previous state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	luabind::object m_PreviousState;

	/** 
	  * @brief current state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	luabind::object m_CurrentState;

	/** 
	  * @brief global state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	luabind::object m_GlobalState;
};

#endif