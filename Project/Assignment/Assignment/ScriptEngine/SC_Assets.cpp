#include "SC_Assets.h"
#include"../Singletons.h"

SC_Assets::SC_Assets()
{
	lua.runScript("ScriptEngine/Scripts/Assets.lua");
}

void SC_Assets::LoadAssets()
{
	std::vector<std::string> str(lua.getGlobalLuaTable("Assets"));

	for(int i = 0; i < str.size(); i++)
	{
		std:string temp = str[i];
		assetManager->Load(temp);
	}
}