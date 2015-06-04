#include"SC_Skybox.h"




SC_Skybox::SC_Skybox()
{
	lua.runScript("ScriptEngine/Scripts/SkyboxProperties.lua");
}

void SC_Skybox::LoadTextures()
{
	std::string str = lua.getGlobalString("SkyboxFront");
	Skybox::LoadTexture(SB_FRONT, strdup(str.c_str()));
	str = lua.getGlobalString("SkyboxBack");
	Skybox::LoadTexture(SB_FRONT, strdup(str.c_str()));
	str = lua.getGlobalString("SkyboxBottom");
	Skybox::LoadTexture(SB_FRONT, strdup(str.c_str()));
	str = lua.getGlobalString("SkyboxTop");
	Skybox::LoadTexture(SB_FRONT, strdup(str.c_str()));
	str = lua.getGlobalString("SkyboxLeft");
	Skybox::LoadTexture(SB_FRONT, strdup(str.c_str()));
	str = lua.getGlobalString("SkyboxRight");
	Skybox::LoadTexture(SB_FRONT, strdup(str.c_str()));
}