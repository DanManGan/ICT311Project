
#include "RegisterScriptedFSM.h"
//#include "luaheader.h"
#include "../Extras/Vector3D.h"
//#include "messageDispatcher.h"
//#include "telegram.h

//#include <lua/lua.hpp>
//#include <luabind/luabind.hpp>

void RegisterScriptedStateMachine(lua_State* lState)
{
    luabind::module(lState)
    [
		luabind::class_<StateMachine<NPC> >("StateMachine")
		.def("ChangeState", &StateMachine<NPC>::ChangeState)//
        .def("SetCurrentState", &StateMachine<NPC>::SetCurrentState)//
		.def("SetPreviousState",&StateMachine<NPC>::SetPreviousState)//
		.def("SetGlobalState",&StateMachine<NPC>::SetGlobalState)//
        .def("GetCurrentState", &StateMachine<NPC>::GetCurrentState)//
		.def("GetPreviousState",&StateMachine<NPC>::GetPreviousState)//
		.def("GetGlobalState",&StateMachine<NPC>::GetGlobalState)//
		.def("RevertToPreviousState",&StateMachine<NPC>::RevertToPreviousState)//
    ]; 
}

void RegisterGameObject(lua_State* lState)
{
}

void RegisterNPC(lua_State* lState)
{
	luabind::module(lState)
    [
		luabind::class_<NPC>("NPC")
	    .def("GetID", &NPC::GetID)
		.def("GetFSM", &NPC::GetFSM)
		.def("SetID", &NPC::SetID)
		.def("SetAnimationLua", &NPC::SetAnimationLua)
		.def("IdleStateDone", &NPC::IdleStateDone)
		.def("Collision", &NPC::Collision)
		.def("ProcessCollision", &NPC::ProcessCollision)
		//.def("setEnemyTarget", &NPC::setEnemyTarget)
  //      .def("watchForEnemy", &player::watchForEnemy)
		.def("WaypointFollow", &NPC::WaypointFollow)
        .def("SetCurWaypoint", &NPC::SetCurWaypoint)
		.def("GetCurWaypoint", &NPC::GetCurWaypoint)
		.def("GetWaypointCycles", &NPC::GetWaypointCycles)
		.def("SetWaypointCycles", &NPC::SetWaypointCycles)
		.def("Wander", &NPC::Wander)
		//.def("moveToEnemy", &player::moveToEnemy)
		//.def("sendMessage", &player::sendMessage)
		
	]; 
}

//void RegisterPlayer(lua_State* lState)
//{
//	luabind::module(lState)
//    [
//		luabind::class_<player>("player")
//	    .def("getPlayerID", &player::getPlayerID)
//		.def("getFSM", &player::getFSM)
//		.def("setEnemyTarget", &player::setEnemyTarget)
//        .def("watchForEnemy", &player::watchForEnemy)
//	    .def("setPlayerID", &player::setPlayerID)
//		.def("waypointFollow", &player::waypointFollow)
//        .def("setCurwayPointNo", &player::setCurwayPointNo)
//		.def("moveToEnemy", &player::moveToEnemy)
//		.def("sendMessage", &player::sendMessage)
//		
//	]; 
//}

//void RegisterVector3D(lua_State* lState)
//{
//	luabind::module(lState)
//    [
//		luabind::class_<Vector3D>("Vector3D")
//		.def(luabind::constructor<>())
//		.def("Set", &Vector3D::Set)
//		.def("GetX", &Vector3D::x)
//        .def("GetY", &Vector3D::z)
//    ]; 
//}
//
//void RegisterMessage(lua_State* lState)
//{
//	luabind::module(lState)
//    [
//		luabind::class_<messageDispatcher>("messageDispatcher")
//		.def("dispatchMsg", &messageDispatcher::dispatchMsg)		
//    ]; 
//}
//
//void RegisterTelegram(lua_State* lState)
//{
//	luabind::module(lState)
//    [
//		luabind::class_<telegram>("telegram")
//		.def_readwrite("sender", &telegram::sender)
//        .def_readwrite("receiver", &telegram::receiver)
//		.def_readwrite("msg", &telegram::msg)
//		.def_readwrite("dispatchTime", &telegram::dispatchTime)
//		.def_readwrite("extraInfo", &telegram::extraInfo)
//    ]; 
//}