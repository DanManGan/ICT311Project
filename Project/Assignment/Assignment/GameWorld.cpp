
#include "GameWorld.h"
#include "Singletons.h"
//#include "AssetManagement/Texture.h"
//#include "AssetManagement/md2.h"
//#include "AssetManagement/Mesh.h"
//#include "AssetManagement/obj.h"
#include "GameObjects/NPC.h"
#include "GameObjects/Model.h"
#include "GameObjects/Player.h"
#include "GameObjects/Terrain.h"
#include "LuaScripting/RegisterScriptedFSM.h"
#include "AI/Waypoint.h"

#include <iostream>

#include <luabind/adopt_policy.hpp>
#include <lua/lua.hpp>
#include <luabind/luabind.hpp>

//--------------------------------------------------------------------------------------

GameWorld::GameWorld() :
	m_objFactory(GameObjectFactory()),
	m_terrain(new TerrainModel())
{
	m_objects.clear();
	LoadAssets();
	CreateTerrain();
}

//--------------------------------------------------------------------------------------

GameWorld::~GameWorld()
{
	delete m_terrain;
	m_terrain = nullptr;

	for(objIter it = m_objects.begin(); it != m_objects.end(); it++) {
		//if(it->first != "player") {
			delete it->second;
			it->second = nullptr;
		//}
	}
	m_objects.clear();

	//delete m_player;
	//m_player = nullptr;
	lua_close(lState);
}

//--------------------------------------------------------------------------------------

void GameWorld::LoadAssets()
{
	
	//Procedural terrain only works correctly with TGA files currently

	m_skybox.LoadTexture(SB_FRONT, "Texture/SkyboxFront.tga");
	m_skybox.LoadTexture(SB_BACK, "Texture/SkyboxFront.tga");
	m_skybox.LoadTexture(SB_BOTTOM, "Texture/SkyboxFront.tga");
	m_skybox.LoadTexture(SB_TOP, "Texture/SkyboxFront.tga");
	m_skybox.LoadTexture(SB_LEFT, "Texture/SkyboxFront.tga");
	m_skybox.LoadTexture(SB_RIGHT, "Texture/SkyboxFront.tga");

	//assetManager->Load("Textures/grass.bmp");
	assetManager->Load("Textures/lowestTile.tga");
	assetManager->Load("Textures/lowTile.tga");
	assetManager->Load("Textures/highTile.tga");
	assetManager->Load("Textures/highestTile.tga");
	assetManager->Load("Textures/detailmap.tga");
	assetManager->Load("Textures/heightmap.bmp");

	assetManager->Load("Models/Ogro/Tris.md2");
	assetManager->Load("Models/Ogro/Ogrobase.pcx");

	assetManager->Load("Models/berserk/tris.md2");
	assetManager->Load("Models/berserk/skin.pcx");

	assetManager->Load("Models/soldier/tris.md2");
	assetManager->Load("Models/soldier/skin.pcx");

	assetManager->Load("Models/mutant/tris.md2");
	assetManager->Load("Models/mutant/skin.pcx");

	assetManager->Load("Models/house1/house1.obj");

	assetManager->Load("Models/bananaTree/bananaTree.obj");

	assetManager->Load("Models/tree1/tree1.obj");
	assetManager->Load("Models/ruralStall/ruralStall.obj");
	assetManager->Load("Models/chapel/chapel.obj");
	assetManager->Load("Models/church/church.obj");

	assetManager->Load("Models/number_1/number_1.obj");
	assetManager->Load("Models/number_2/number_2.obj");
	assetManager->Load("Models/number_3/number_3.obj");
	assetManager->Load("Models/number_4/number_4.obj");
	assetManager->Load("Models/number_5/number_5.obj");

	assetManager->Load("Textures/menu.bmp");
	assetManager->Load("Textures/exitScreen.bmp");
}

//--------------------------------------------------------------------------------------

bool GameWorld::CreateTerrain()
{	
	m_terrain->SetScaleFactor(1.0f,0.25f,1.0f);
	//m_terrain->GenFaultFormation(100, 512,1,125,0.1f,false);
	if(m_terrain->LoadHeightfield((Texture*)assetManager->GetAsset("Textures/heightmap.bmp"))) {
		m_terrain->SetDetailMap(graphics->SetupTextureBasic((Texture*)assetManager->GetAsset("Textures/detailmap.tga")));
		m_terrain->AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/lowestTile.tga"));
		m_terrain->AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/lowTile.tga"));
		m_terrain->AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/highTile.tga"));
		m_terrain->AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/highestTile.tga"));
		m_terrain->CreateProceduralTexture();
		m_terrain->SetTexture(graphics->CreateNewTexture(m_terrain->GetProTexData(), m_terrain->GetProTexWidth(), m_terrain->GetProTexHeight()));
		m_terrain->SetNumTerrainTexRepeat(1);
		m_terrain->SetNumDetailMapRepeat(12);
		m_terrain->SetLightingColor(1.0f, 1.0f, 1.0f);
		m_terrain->SetSlopeLightingParams( 1, 1, 0.5f, 1.0f, 100.0f );
		m_terrain->CreateSlopeLighting();

		return true;
	}
	return false;
	//return m_terrain->LoadHeightfield("Textures/height128.raw",128);
}

//--------------------------------------------------------------------------------------

void GameWorld::CreateObjects()
{
	Waypoint<Vector3D> waypoints;

	waypoints.ClearAllWaypoints();
	waypoints.AddWaypoint(Vector3D(50.0f ,m_terrain->GetHeightAverage(50.0f,70.0f), 70.0f));
	waypoints.AddWaypoint(Vector3D(110.0f, m_terrain->GetHeightAverage(110.0f,425.0f), 425.0f));
	waypoints.AddWaypoint(Vector3D(210.0f, m_terrain->GetHeightAverage(210.0f,270.0f), 270.0f));
	waypoints.AddWaypoint(Vector3D(360.0f, m_terrain->GetHeightAverage(360.0f,405.0f), 405.0f));
	waypoints.AddWaypoint(Vector3D(405.0f, m_terrain->GetHeightAverage(405.0f,95.0f), 95.0f));
	waypoints.AddWaypoint(Vector3D(210.0f, m_terrain->GetHeightAverage(210.0f,270.0f), 270.0f));

	m_objects["ogro"] = m_objFactory.Create("npc");
	m_objects["ogro"]->SetPos(52,m_terrain->GetHeightAverage(52,92),92);
	m_objects["ogro"]->SetMesh(assetManager->GetAsset("Models/Ogro/Tris.md2"));
	m_objects["ogro"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/Ogro/Ogrobase.pcx")));
	m_objects["ogro"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["ogro"]->SetBase();
	m_objects["ogro"]->SetAABB();
	m_objects["ogro"]->SetAnimation(RUN);
	((NPC*)m_objects["ogro"])->AddWaypoints(waypoints);


	waypoints.ClearAllWaypoints();
	waypoints.AddWaypoint(Vector3D(210.0f, m_terrain->GetHeightAverage(210.0f,270.0f), 270.0f));
	waypoints.AddWaypoint(Vector3D(405.0f, m_terrain->GetHeightAverage(405.0f,95.0f), 95.0f));
	waypoints.AddWaypoint(Vector3D(110.0f, m_terrain->GetHeightAverage(110.0f,425.0f), 425.0f));
	waypoints.AddWaypoint(Vector3D(360.0f, m_terrain->GetHeightAverage(360.0f,405.0f), 405.0f));
	waypoints.AddWaypoint(Vector3D(210.0f, m_terrain->GetHeightAverage(210.0f,270.0f), 270.0f));
	waypoints.AddWaypoint(Vector3D(50.0f ,m_terrain->GetHeightAverage(50.0f,70.0f), 70.0f));

	m_objects["mutant"] = m_objFactory.Create("npc");
	m_objects["mutant"]->SetMesh(assetManager->GetAsset("Models/mutant/tris.md2"));
	m_objects["mutant"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/mutant/skin.pcx")));
	m_objects["mutant"]->SetPos(215,m_terrain->GetHeightAverage(215,215),215);
	m_objects["mutant"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["mutant"]->SetBase();
	m_objects["mutant"]->SetAABB();
	m_objects["mutant"]->SetAnimation(RUN);
	((NPC*)m_objects["mutant"])->AddWaypoints(waypoints);

	waypoints.ClearAllWaypoints();
	waypoints.AddWaypoint(Vector3D(110.0f, m_terrain->GetHeightAverage(110.0f,425.0f), 425.0f));
	waypoints.AddWaypoint(Vector3D(210.0f, m_terrain->GetHeightAverage(210.0f,270.0f), 270.0f));
	waypoints.AddWaypoint(Vector3D(405.0f, m_terrain->GetHeightAverage(405.0f,95.0f), 95.0f));
	waypoints.AddWaypoint(Vector3D(360.0f, m_terrain->GetHeightAverage(360.0f,405.0f), 405.0f));
	waypoints.AddWaypoint(Vector3D(210.0f, m_terrain->GetHeightAverage(210.0f,270.0f), 270.0f));
	waypoints.AddWaypoint(Vector3D(50.0f ,m_terrain->GetHeightAverage(50.0f,70.0f), 70.0f));
	
	m_objects["berserk"] = m_objFactory.Create("npc");
	m_objects["berserk"]->SetPos(400,m_terrain->GetHeightAverage(400,400),400);
	m_objects["berserk"]->SetMesh(assetManager->GetAsset("Models/berserk/tris.md2"));
	m_objects["berserk"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/berserk/skin.pcx")));
	m_objects["berserk"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["berserk"]->SetBase();
	m_objects["berserk"]->SetAABB();
	m_objects["berserk"]->SetAnimation(RUN);
	((NPC*)m_objects["berserk"])->AddWaypoints(waypoints);


	waypoints.ClearAllWaypoints();
	waypoints.AddWaypoint(Vector3D(360.0f, m_terrain->GetHeightAverage(360.0f,405.0f), 405.0f));
	waypoints.AddWaypoint(Vector3D(405.0f, m_terrain->GetHeightAverage(405.0f,95.0f), 95.0f));
	waypoints.AddWaypoint(Vector3D(210.0f, m_terrain->GetHeightAverage(210.0f,270.0f), 270.0f));
	waypoints.AddWaypoint(Vector3D(50.0f ,m_terrain->GetHeightAverage(50.0f,70.0f), 70.0f));
	waypoints.AddWaypoint(Vector3D(110.0f, m_terrain->GetHeightAverage(110.0f,425.0f), 425.0f));
	waypoints.AddWaypoint(Vector3D(210.0f, m_terrain->GetHeightAverage(210.0f,270.0f), 270.0f));

	m_objects["soldier"] = m_objFactory.Create("npc");
	m_objects["soldier"]->SetPos(20,m_terrain->GetHeightAverage(20,20),20);
	m_objects["soldier"]->SetMesh(assetManager->GetAsset("Models/soldier/tris.md2"));
	m_objects["soldier"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/soldier/skin.pcx")));
	m_objects["soldier"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["soldier"]->SetBase();
	m_objects["soldier"]->SetAABB();
	m_objects["soldier"]->SetAnimation(RUN);
	((NPC*)m_objects["soldier"])->AddWaypoints(waypoints);

	m_objects["house1"] = m_objFactory.Create("model");
	m_objects["house1"]->SetPos(200, m_terrain->GetHeightAverage(200,150),150);
	m_objects["house1"]->SetMesh(assetManager->GetAsset("Models/house1/house1.obj"));
	m_objects["house1"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["house1"]->SetAABB();

	m_objects["bananaTree"] = m_objFactory.Create("model");
	m_objects["bananaTree"]->SetPos(210, m_terrain->GetHeightAverage(210,180),180);
	m_objects["bananaTree"]->SetMesh(assetManager->GetAsset("Models/bananaTree/bananaTree.obj"));
	m_objects["bananaTree"]->SetScale(0.025f, 0.025f, 0.025f);
	m_objects["bananaTree"]->SetAABB();

	m_objects["number1"] = m_objFactory.Create("model");
	m_objects["number1"]->SetPos(200, m_terrain->GetHeightAverage(200, 400), 400);
	m_objects["number1"]->SetMesh(assetManager->GetAsset("Models/number_1/number_1.obj"));
	m_objects["number1"]->SetAABB();

	m_objects["number2"] = m_objFactory.Create("model");
	m_objects["number2"]->SetPos(50, m_terrain->GetHeightAverage(50, 100), 100);
	m_objects["number2"]->SetMesh(assetManager->GetAsset("Models/number_2/number_2.obj"));
	m_objects["number2"]->SetAABB();

	m_objects["number3"] = m_objFactory.Create("model");
	m_objects["number3"]->SetPos(350, m_terrain->GetHeightAverage(350, 200), 200);
	m_objects["number3"]->SetMesh(assetManager->GetAsset("Models/number_3/number_3.obj"));
	m_objects["number3"]->SetAABB();

	m_objects["number4"] = m_objFactory.Create("model");
	m_objects["number4"]->SetPos(10, m_terrain->GetHeightAverage(10, 490), 490);
	m_objects["number4"]->SetMesh(assetManager->GetAsset("Models/number_4/number_4.obj"));
	m_objects["number4"]->SetAABB();

	m_objects["number5"] = m_objFactory.Create("model");
	m_objects["number5"]->SetPos(225, m_terrain->GetHeightAverage(225, 175), 175);
	m_objects["number5"]->SetMesh(assetManager->GetAsset("Models/number_5/number_5.obj"));
	m_objects["number5"]->SetAABB();

	m_objects["chapel"] = m_objFactory.Create("model");
	m_objects["chapel"]->SetPos(250, m_terrain->GetHeightAverage(250, 200)+10, 200);
	m_objects["chapel"]->SetMesh(assetManager->GetAsset("Models/chapel/chapel.obj"));
	m_objects["chapel"]->SetScale(0.025f, 0.025f, 0.025f);
	m_objects["chapel"]->SetAABB();

	m_objects["player"] = m_objFactory.Create("player");
	m_objects["player"]->SetPos(m_terrain->GetSize()/2,
		m_terrain->GetHeightAverage(m_terrain->GetSize()/2, m_terrain->GetSize()/2),
		m_terrain->GetSize()/2);
	m_objects["player"]->SetAABB();

}

//--------------------------------------------------------------------------------------

void GameWorld::LoadScripts()
{


 lState = lua_open();
//  //open the libraries
 luaL_openlibs(lState);

  luabind::open(lState);
  RegisterScriptedStateMachine(lState);
  RegisterNPC(lState);
////  registerPlayer(lState);
////  registerVector2D(lState);
////  registerMessage(lState);
////registerTelegram(lState);
//  //load and run the script
  luaL_dofile(lState, "Scripts/statemachine.lua");

//  try{
//	//luabind::globals(lState)["dude"] = dude;
//  
// // lua_dostring(lState,"dude:getFSM():setCurrentState(state_idle)\n");
//  //dude->updateAI(5);
//  }catch(luabind::error)
//{
//	std::cout << "error trying to call lua function" << std::endl;
//}
//  catch(const std::exception &TheError) {
//    std::cout << TheError.what() << std::endl;
//  }
  ////////luabind::object   stat = luabind::get_globals(lState);
 luabind::object   state = luabind::globals(lState);
 // getchar();
 	for(objIter it = m_objects.begin(); it != m_objects.end(); it++) {
		if(it->second->GetObjectType() == "NPC") {
			((NPC*)it->second)->GetFSM()->
				SetCurrentState(luabind::object_cast<luabind::object>(state["state_patrol"]));
			((NPC*)it->second)->GetFSM()->
				SetGlobalState(luabind::object_cast<luabind::object>(state["state_global"]));
			//temp = nullptr;
		}
	}

	//((NPC*)m_objects["ogro"])->GetFSM()->SetCurrentState(luabind::object_cast<luabind::object>(state["state_patrol"]));
	//((NPC*)m_objects["berserk"])->GetFSM()->SetCurrentState(luabind::object_cast<luabind::object>(state["state_patrol"]));
	//((NPC*)m_objects["soldier"])->GetFSM()->SetCurrentState(luabind::object_cast<luabind::object>(state["state_patrol"]));
 // dude->getFSM()->setGlobalState(luabind::object_cast<luabind::object>(stat["state_global"]));

 // patroller->getFSM()->setCurrentState(luabind::object_cast<luabind::object>(stat["state_patrol"]));
 // patroller->getFSM()->setGlobalState(luabind::object_cast<luabind::object>(stat["state_global"]));

 //sentry->getFSM()->setCurrentState(luabind::object_cast<luabind::object>(stat["state_patrol"]));
 // sentry->getFSM()->setGlobalState(luabind::object_cast<luabind::object>(stat["state_global"]));

// return true;
//	getchar();
  
}

//--------------------------------------------------------------------------------------

GameObject* GameWorld::GetPlayer()
{
	return m_objects["player"];
}

//--------------------------------------------------------------------------------------

void GameWorld::Render()
{
	m_objects["player"]->Render();
	m_objects["player"]->DrawAABB();
	graphics->ClearColour(0.75f,0.75f,1.0f,1.0f);

	m_terrain->Render();

	m_skybox.Set(0.0f, 0.0f, 0.0f, 1024.0f);
	m_skybox.Render();

	for(objIter it = m_objects.begin(); it != m_objects.end(); it++) {
		if(it->second->GetObjectType() != "PLAYER") {
			it->second->SetY(m_terrain->GetHeightAverage(it->second->GetX(), it->second->GetZ()));
			it->second->Render();
			//it->second->DrawAABB();
		}
	}

}

//--------------------------------------------------------------------------------------

void GameWorld::Update()
{
	for(objIter it1 = m_objects.begin(); it1 != m_objects.end(); it1++) {
		for(objIter it2 = it1; it2 != m_objects.end(); it2++) {
			if(it1 != it2) {
				if(it1->second->TestCollision(it2->second))
					it1->second->SetX(it2->second->GetX()+10);
			}
		}
	}

}

//--------------------------------------------------------------------------------------

void GameWorld::Animate(float deltaT)
{
	for(objIter it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->Animate(deltaT);
	}


}

//--------------------------------------------------------------------------------------

bool GameWorld::InWorld(float& x, float& z)
{
	if(x<0) {
		x=0;
		return false;
	}
	else if(x>m_terrain->GetSize()) {
		x=(float)m_terrain->GetSize();
		return false;
	}

	if(z<0) {
		z=0;
		return false;
	}
	else if(z>m_terrain->GetSize()) {
		z=(float)m_terrain->GetSize();
		return false;
	}

 return true;
}

//--------------------------------------------------------------------------------------

bool GameWorld::InWorld(GameObject* obj)
{
	if(obj->GetX() < 5.0f) {
		obj->SetX(5.0f);
		return false;
	}
	else if(obj->GetX() > m_terrain->GetSize()-5.0f) {
		obj->SetX((float)m_terrain->GetSize()-5.0f);
		return false;
	}

	if(obj->GetZ() < 5.0f) {
		obj->SetZ(5.0f);
		return false;
	}
	else if(obj->GetZ() > m_terrain->GetSize()-5.0f) {
		obj->SetZ((float)m_terrain->GetSize()-5.0f);
		return false;
	}

 return true;
}

//--------------------------------------------------------------------------------------

float GameWorld::GetWorldXZHeight(float x, float z)
{
	return m_terrain->GetHeightAverage(x,z);
}

//--------------------------------------------------------------------------------------

float GameWorld::GetWorldSize()
{
	return (float)m_terrain->GetSize();
}