
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

#include "Extras/Singleton.h"
//#include "textureHandler/textureManager.h"
#include "GameWorld.h"
#include "Graphics/ViewOpenGL.h"
#include "Input/InputGLFW.h"
#include "AudioEngine.h"
#include "AssetManagement/GameAssetManager.h"
#include "HUD/HUD_Factory.h"
#include "HUD/HUD.h"

//typedef Singleton<textureManager> textureMan;
//#define texManager textureMan::GetInstance()

typedef Singleton<GameWorld> theWorld;
#define gameWorld theWorld::GetInstance()

typedef Singleton<ViewOpenGL> openGL;
#define graphics openGL::GetInstance()

typedef Singleton<InputGLFW> inputGLFW;
#define input inputGLFW::GetInstance()

typedef Singleton<AudioEngine> audioEngine;
#define audio audioEngine::GetInstance()

typedef Singleton<GameAssetManager> gameAssetManager;
#define assetManager gameAssetManager::GetInstance()

typedef Singleton<HUD_Factory> HUDF;
#define HUDFactory HUDF::GetInstance()

typedef Singleton<HUD> HUDInstance;
#define gameHUD HUDInstance::GetInstance()


#endif