
/** 
  * @class Singletons
  * @brief Singleton class definitions
  * 
  * Singleton class to define and manage Singleton class instances
  * 
  * 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 20.04.15
  * @status under construction
  * 
  * @author 
  * @version 
  * @date 
  * @status 
  * 
  * @todo 
  * 
  * @bugs 
  */

#ifndef SINGLETONS_H
#define SINGLETONS_H

#include "Singleton.h"
#include "textureHandler/textureManager.h"
#include "GameWorld.h"
#include "ViewOpenGL.h"
#include "InputGLFW.h"
#include "AudioEngine.h"

typedef Singleton<textureManager> textureMan;
#define texManager textureMan::GetInstance()

typedef Singleton<GameWorld> theWorld;
#define gameWorld theWorld::GetInstance()

typedef Singleton<ViewOpenGL> openGL;
#define graphics openGL::GetInstance()

typedef Singleton<InputGLFW> inputGLFW;
#define input inputGLFW::GetInstance()

typedef Singleton<AudioEngine> audioEngine;
#define audio audioEngine::GetInstance()

#endif