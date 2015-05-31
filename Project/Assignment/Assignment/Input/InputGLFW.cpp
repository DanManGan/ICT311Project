
#pragma comment(lib,"glfw.lib")

#include "InputGLFW.h"
#include "../Singletons.h"

#include <gl/glfw.h>

//--------------------------------------------------------------------------------------

InputGLFW::InputGLFW() :
	mouseX(0),
	mouseY(0), 
	mouseLeft(false),
	mouseRight(false),
	key(0),
	keyPress(false),
	keyRelease(false)
{
	Init();
}

//--------------------------------------------------------------------------------------

InputGLFW::~InputGLFW()
{
}

//--------------------------------------------------------------------------------------

void InputGLFW::Init()
{
	glfwSetKeyCallback(&InputGLFW::KeyboardCallback);
	glfwSetMousePosCallback(&InputGLFW::MousePosCallback);
	glfwSetMouseButtonCallback(&InputGLFW::MouseButtonCallback);
}

//--------------------------------------------------------------------------------------

void InputGLFW::KeyboardCallback(int key, int action)
{
	input->Keyboard(key, action);
}

//--------------------------------------------------------------------------------------

void InputGLFW::Keyboard(int key1, int action1)
{
	key = key1;

	if(action1 == GLFW_PRESS) {
		keyPress = true;
		keyRelease = false;
	}
	else if(action1 == GLFW_RELEASE) {
		keyPress = false;
		keyRelease = true;
	}
	
}

//--------------------------------------------------------------------------------------

void InputGLFW::MousePos(int x, int y)
{
	mouseX = x;
	mouseY = y;
}

//--------------------------------------------------------------------------------------

void InputGLFW::MousePosCallback(int x, int y)
{
	input->MousePos(x, y);
}

//--------------------------------------------------------------------------------------

void InputGLFW::MouseButton(int button, int action)
{
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
		mouseLeft = true;
	else mouseLeft = false;

	if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		mouseRight = true;
	else mouseRight = false;
}

//--------------------------------------------------------------------------------------

void InputGLFW::MouseButtonCallback(int button, int action)
{
	input->MouseButton(button, action);
}