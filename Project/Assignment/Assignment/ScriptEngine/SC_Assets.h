#ifndef SC_ASSETS_H
#define SC_ASSETS_H


#include<vector>
#include"LuaEngine.h"

class SC_Assets
{
public:
	SC_Assets();
	~SC_Assets() {};

	void LoadAssets();

private:
	LuaEngine lua;
};

#endif