#ifndef SC_GRAPHICS_H
#define SC_GRAPHICS_H

#include "LuaEngine.h"


class SC_Graphics
{
public:
	SC_Graphics();
	~SC_Graphics() {};

	bool OpenWindow();
	void SetWindowPosition();
	void SetWindowTitle();

private:
	LuaEngine lua;

};

#endif

