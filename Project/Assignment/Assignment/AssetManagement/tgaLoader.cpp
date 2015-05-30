
#pragma comment(lib,"glfw.lib")

#include "tgaLoader.h"
#include "tga.h"

#include <iostream>
#include <gl/glfw.h>

GameAsset* tgaLoader::Create(char *filePath)
{
	if(!ValidFile(filePath))
		return nullptr;

	GLFWimage* iData=new GLFWimage();

  	if(glfwReadImage(filePath, iData, /*GL_RGB ||*/ GLFW_ORIGIN_UL_BIT )==GL_FALSE) {
		std::cout << "glfwReadImage Failed: " << filePath << std::endl;
		iData = nullptr;
		return nullptr;
	}   

	return new tga(filePath, iData->Data, iData->Width, iData->Height, iData->BytesPerPixel);
}

const char* tgaLoader::GetExtension() 
{ 
	return ".tga"; 
}