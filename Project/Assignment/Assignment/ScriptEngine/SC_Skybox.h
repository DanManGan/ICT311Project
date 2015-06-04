#ifndef SC_SKYBOX_H
#define SC_SKYBOX_H

#include"LuaEngine.h"
#include"../Graphics/Skybox.h"
#include<string>

class SC_Skybox : public Skybox
{
public:
	SC_Skybox();
	~SC_Skybox() {};

	void LoadTextures();

private:
	LuaEngine lua;
};

#endif