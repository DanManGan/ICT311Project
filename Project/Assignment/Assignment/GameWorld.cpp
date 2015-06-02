
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
#include <iostream>

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
	assetManager->Load("Textures/heightmapa.bmp");

	assetManager->Load("Models/Ogro/Tris.md2");
	assetManager->Load("Models/Ogro/Ogrobase.pcx");

	assetManager->Load("Models/berserk/tris.md2");
	assetManager->Load("Models/berserk/skin.pcx");

	assetManager->Load("Models/soldier/tris.md2");
	assetManager->Load("Models/soldier/skin.pcx");

	assetManager->Load("Models/tank/tris.md2");
	assetManager->Load("Models/tank/skin.pcx");

	assetManager->Load("Models/house1/house1.obj");

	assetManager->Load("Models/bananaTree/bananaTree.obj");

	assetManager->Load("Models/tree1/tree1.obj");
}

//--------------------------------------------------------------------------------------

bool GameWorld::CreateTerrain()
{	
	m_terrain->SetScaleFactor(1.0f,0.5f,1.0f);
	//m_terrain->GenFaultFormation(100, 512,1,125,0.1f,false);
	if(m_terrain->LoadHeightfield((Texture*)assetManager->GetAsset("Textures/heightmapa.bmp"))) {
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
	m_objects["ogro"] = m_objFactory.Create("npc");
	m_objects["ogro"]->SetPos(52,m_terrain->GetHeightAverage(52,92),92);
	m_objects["ogro"]->SetMesh(assetManager->GetAsset("Models/Ogro/Tris.md2"));
	m_objects["ogro"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/Ogro/Ogrobase.pcx")));
	m_objects["ogro"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["ogro"]->SetBase();
	m_objects["ogro"]->SetAABB();
	m_objects["ogro"]->SetAnimation(RUN);

	//m_objects["tank"] = m_objFactory.Create("npc");
	//m_objects["tank"]->SetMesh(assetManager->GetAsset("Models/tank/tris.md2"));
	//m_objects["tank"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/tank/skin.pcx")));
	//m_objects["tank"]->SetPos(15,terrain->GetHeightAverage(15,15),15);
	//m_objects["tank"]->SetScale(0.25f, 0.25f, 0.25f);
	//m_objects["tank"]->SetBase();
	//m_objects["tank"]->SetAABB();
	//m_objects["tank"]->SetAnimation(RUN);
	
	m_objects["berserk"] = m_objFactory.Create("npc");
	m_objects["berserk"]->SetPos(29,m_terrain->GetHeightAverage(29,93),93);
	m_objects["berserk"]->SetMesh(assetManager->GetAsset("Models/berserk/tris.md2"));
	m_objects["berserk"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/berserk/skin.pcx")));
	m_objects["berserk"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["berserk"]->SetBase();
	m_objects["berserk"]->SetAABB();
	m_objects["berserk"]->SetAnimation(RUN);

	m_objects["soldier"] = m_objFactory.Create("npc");
	m_objects["soldier"]->SetPos(20,m_terrain->GetHeightAverage(20,20),20);
	m_objects["soldier"]->SetMesh(assetManager->GetAsset("Models/soldier/tris.md2"));
	m_objects["soldier"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/soldier/skin.pcx")));
	m_objects["soldier"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["soldier"]->SetBase();
	m_objects["soldier"]->SetAABB();
	m_objects["soldier"]->SetAnimation(RUN);

	m_objects["house1"] = m_objFactory.Create("model");
	m_objects["house1"]->SetPos(85, m_terrain->GetHeightAverage(85,15),15);
	m_objects["house1"]->SetMesh(assetManager->GetAsset("Models/house1/house1.obj"));
	m_objects["house1"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["house1"]->SetAABB();

	m_objects["bananaTree"] = m_objFactory.Create("model");
	m_objects["bananaTree"]->SetPos(15, m_terrain->GetHeightAverage(15,85),85);
	m_objects["bananaTree"]->SetMesh(assetManager->GetAsset("Models/bananaTree/bananaTree.obj"));
	m_objects["bananaTree"]->SetScale(0.025f, 0.025f, 0.025f);
	m_objects["bananaTree"]->SetAABB();


	//m_objects["tree1"] = m_objFactory.Create("model");
	//m_objects["tree1"]->SetPos(65, terrain->GetHeightAverage(65,65),65);
	//m_objects["tree1"]->SetMesh(assetManager->GetAsset("Models/tree1/tree1.obj"));
	//m_objects["tree1"]->SetScale(0.025f, 0.025f, 0.025f);
	//m_objects["tree1"]->SetAABB();

	//m_objects["player"] = obj;
	m_objects["player"] = m_objFactory.Create("player");
	m_objects["player"]->SetPos(m_terrain->GetSize()/2,
		m_terrain->GetHeightAverage(m_terrain->GetSize()/2, m_terrain->GetSize()-20),
		m_terrain->GetSize()-20);
	m_objects["player"]->SetAABB();

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
			it->second->DrawAABB();
		}
	}

}

//--------------------------------------------------------------------------------------

void GameWorld::Update()
{
	//Player* temp =	(Player*)m_objects["AAplayer"];
	//m_player->UpdateCamera(camVelocity, camYaw, camPitch);
	//std::cout << "START OF COLLISION TEST" << std::endl;
//	m_objects["player"] = obj;
	for(objIter it1 = m_objects.begin(); it1 != m_objects.end(); it1++) {
		for(objIter it2 = it1; it2 != m_objects.end(); it2++) {
			if(it1 != it2) {
				it1->second->TestCollision(it2->second);
			}
		}
	}
//	m_objects.erase("player");
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