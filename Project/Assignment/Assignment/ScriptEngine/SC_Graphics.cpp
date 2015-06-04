#include "SC_Graphics.h"
#include"../Singletons.h"

SC_Graphics::SC_Graphics()
{
	lua.runScript("ScriptEngine/Scripts/GraphicsProperties.lua");
}

bool SC_Graphics::OpenWindow()
{
	int width = lua.getGlobalInt("WindowWidth");
	int height = lua.getGlobalInt("WindowHeight");

	return graphics->OpenWindow(width, height);
}

void SC_Graphics::SetWindowPosition()
{
	int x = lua.getGlobalInt("WindowXPosition");
	int y = lua.getGlobalInt("WindowYPosition");

	graphics->SetWindowPosition(x, y);
}

void SC_Graphics::SetWindowTitle()
{
	char* title = lua.getGlobalc_str("WindowTitle");

	graphics->SetWindowTitle(title);
}