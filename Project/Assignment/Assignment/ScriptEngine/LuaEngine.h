/** 
  * @class LuaEngine
  * @brief Scripting engine using Lua
  * 
  * Class that wraps lua states and script loading 
  * as an object.
  * 
  * @author Sam Lindsay
  * @version 01
  * @date 20.05.15
  * @status under construction
  * 
  */
#ifndef LUAENGINE_H
#define LUAENGINE_H
#include<vector>
#include<iostream>
#include<string>
#include<lua/lua.hpp>

class LuaEngine
{
public:
	LuaEngine();

	bool runScript(char* file);

	int getGlobalInt(char* luaVar);
	float getGlobalFloat(char* luaVar);
	bool getGlobalBool(char* luaVar);
	std::string getGlobalString(char* luaVar);
	char* getGlobalc_str(char* luaVar);

	std::vector<std::string> getGlobalLuaTable(char* luaVar);

	~LuaEngine();
private:
	lua_State * Lua;
};

#endif//LUAENGINE_H

