#include "LuaEngine.h"


LuaEngine::LuaEngine()
{
	Lua = lua_open();
	luaL_openlibs(Lua);
}

bool LuaEngine::runScript(char* file)
{
	std::cout << "Executing " << file << std::endl;
	luaL_dofile(Lua, file);
	return true;
}

int LuaEngine::getGlobalInt(char* luaVar)
{
	lua_getglobal(Lua, luaVar);
	
	int temp = lua_tointeger(Lua, -1);
	lua_pop(Lua, 1);
	return temp;
}

float LuaEngine::getGlobalFloat(char* luaVar)
{
	lua_getglobal(Lua, luaVar);
	float temp;
	temp = (float)lua_tonumber(Lua, -1);
	lua_pop(Lua, 1);
	return temp;
}

bool LuaEngine::getGlobalBool(char* luaVar)
{
	lua_getglobal(Lua, luaVar);
	bool temp = lua_toboolean(Lua, -1);
	lua_pop(Lua, 1);
	return temp;
}

std::string LuaEngine::getGlobalString(char* luaVar)
{
	lua_getglobal(Lua, luaVar);
	std::string temp = "";
	if(lua_isstring(Lua, -1))
		temp = lua_tostring(Lua, -1);
	lua_pop(Lua, 1);
	return temp;
}

char* LuaEngine::getGlobalc_str(char* luaVar)
{
	lua_getglobal(Lua, luaVar);
	std::string temp = "";
	if(lua_isstring(Lua, -1))
		temp = lua_tostring(Lua, -1);
	lua_pop(Lua, 1);
	return strdup(temp.c_str());
}

std::vector<std::string> LuaEngine::getGlobalLuaTable(char* LuaVar)
{
	int i = 0;

	lua_getglobal(Lua, LuaVar);
	lua_pushnil(Lua);

	std::vector<std::string> str;

	if(lua_istable(Lua, -2))
	while(lua_next(Lua, -2))
	{
		if(lua_isnumber(Lua, -1))
		{
			double x = lua_tonumber(Lua, -1);
			str.push_back(strdup(std::to_string((long double)x).c_str()));
			i++;
		}
		else
			if(lua_isstring(Lua, -1))
			{
				str.push_back(strdup(lua_tostring(Lua, -1)));
				i++;
			}
		lua_pop(Lua, 1);
	};

	return str;
}

LuaEngine::~LuaEngine()
{
	lua_close(Lua);
}
