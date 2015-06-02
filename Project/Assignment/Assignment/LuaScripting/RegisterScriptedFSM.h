#ifndef REGISTERSCRIPTEDFSM_H
#define REGISTERSCRIPTEDFSM_H

//#include "luaheader.h"

#include "../AI/StateMachine.h"
#include "../GameObjects/GameObject.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/NPC.h"

//#include <lua/lua.hpp>
#include <lua/lua.hpp>
//#include <luabind/luabind.hpp>
#include <luabind/luabind.hpp>



void RegisterScriptedStateMachine(lua_State* lState);
void RegisterGameObject(lua_State* lState);
//void RegisterPlayer(lua_State* lState);
void RegisterNPC(lua_State* lState);
//void RegisterVector3D(lua_State* lState);
//void registerMessage(lua_State* lState);
//void registerTelegram(lua_State* lState);

#endif