
#include "GameWorld.h"
#include "Singletons.h"
#include "AssetManagement/Texture.h"
#include "AssetManagement/md2.h"
#include "AssetManagement/Mesh.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/NPC.h"
#include <iostream>

//--------------------------------------------------------------------------------------

GameWorld::GameWorld() 
{
	m_objects.clear();
	m_terrain = new BruteForce();
	LoadWorld();
}

//--------------------------------------------------------------------------------------

GameWorld::~GameWorld()
{
	delete m_terrain;
	m_terrain = nullptr;
}

//--------------------------------------------------------------------------------------

bool GameWorld::LoadWorld()
{	
	m_terrain->SetScaleFactor(1.0f,0.2f,1.0f);
	//return true;
	return m_terrain->LoadHeightfield("Textures/height128.raw",128);
}

//--------------------------------------------------------------------------------------

void GameWorld::LoadWorldTexture()
{
	//Procedural terrain only works correctly with TGA files currently

	assetManager->Load("Textures/grass.bmp");
	assetManager->Load("Textures/lowestTile.tga");
	assetManager->Load("Textures/lowTile.tga");
	assetManager->Load("Textures/highTile.tga");
	assetManager->Load("Textures/highestTile.tga");
	assetManager->Load("Textures/detailmap.tga");
	assetManager->Load("Textures/heightmap.bmp");
	//assetManager->Load(MESH, "Textures/detailmap.tga");
	//std::cout << "asset" << assetManager->GetAsset("Textures/grass.tga") << std::endl;
	//m_terrain.LoadTexture("Textures/grass.bmp");
	//Texture* tex = (Texture*)assetManager->GetAsset("Textures/detailmap.tga");
	//std::cout << "detail " << tex->GetName() << std::endl;
	//tex->SetTexID(graphics->BindTexture((Texture*)assetManager->GetAsset("Textures/grass.bmp")));
	//m_terrain.SetTexture(graphics->SetupTextureClamp((Texture*)assetManager->GetAsset("Textures/grass.bmp")));
	//m_terrain.LoadHeightfield((Texture*)assetManager->GetAsset("Textures/heightmap.bmp"));
	m_terrain->SetDetailMap(graphics->SetupTextureBasic((Texture*)assetManager->GetAsset("Textures/detailmap.tga")));
	m_terrain->AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/lowestTile.tga"));
	m_terrain->AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/lowTile.tga"));
	m_terrain->AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/highTile.tga"));
	m_terrain->AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/highestTile.tga"));
	m_terrain->CreateProceduralTexture();
	//assetManager->Load(m_terrain.GetProceduralTexture("ProceduralTexture"));
	m_terrain->SetTexture(graphics->CreateNewTexture(m_terrain->GetProTexData(), m_terrain->GetProTexWidth(), m_terrain->GetProTexHeight()));
	m_terrain->SetNumTerrainTexRepeat(1);
	//m_terrain.LoadDetailMap("Textures/detailmap.tga");
	m_terrain->SetNumDetailMapRepeat(8);
	//m_terrain.SetTexture(graphics->SetupTextureClamp((Texture*)assetManager->GetAsset("ProceduralTexture")));
	m_terrain->SetLightingColor(1.0f, 1.0f, 1.0f);
	m_terrain->SetSlopeLightingParams( 1, 1, 0.2f, 0.9f, 10.0f );
	m_terrain->CreateSlopeLighting();

	assetManager->Load("Models/Ogro/Tris.md2");
	assetManager->Load("Models/Ogro/Ogrobase.pcx");

	assetManager->Load("Models/berserk/tris.md2");
	assetManager->Load("Models/berserk/skin.pcx");

	m_objects["ogro"] = new NPC("ogro",52,m_terrain->GetHeightAverage(52,92),92);
	m_objects["ogro"]->SetMesh(assetManager->GetAsset("Models/Ogro/Tris.md2"));
	m_objects["ogro"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/Ogro/Ogrobase.pcx")));
	m_objects["ogro"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["ogro"]->SetBase();
	m_objects["ogro"]->SetAABB();
	m_objects["ogro"]->SetAnimation(RUN);
	
	m_objects["berserk"] = new NPC("berserk",29,m_terrain->GetHeightAverage(29,93),93);
	m_objects["berserk"]->SetMesh(assetManager->GetAsset("Models/berserk/tris.md2"));
	m_objects["berserk"]->SetSkin(graphics->SetupTextureClamp(assetManager->GetAsset("Models/berserk/skin.pcx")));
	m_objects["berserk"]->SetScale(0.25f, 0.25f, 0.25f);
	m_objects["berserk"]->SetBase();
	m_objects["berserk"]->SetAABB();
	m_objects["berserk"]->SetAnimation(RUN);
}

//--------------------------------------------------------------------------------------

void GameWorld::Render()
{
	m_terrain->Render();

	for(objIter it = m_objects.begin(); it != m_objects.end(); it++) {
		it->second->SetY(m_terrain->GetHeightAverage(it->second->GetX(), it->second->GetZ()));
		it->second->Render();
		it->second->DrawAABB();
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

void GameWorld::Left()
{
	m_objects["ogro"]->Left();
}

void GameWorld::Right()
{
	m_objects["ogro"]->Right();
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

float GameWorld::GetWorldXZHeight(float x, float z)
{
	return m_terrain->GetHeightAverage(x,z);
}

//--------------------------------------------------------------------------------------

float GameWorld::GetWorldSize()
{
	return (float)m_terrain->GetSize();
}

//--------------------------------------------------------------------------------------
//
//bool GameWorld::GenFaultFormTerrain()
//{
//	return m_terrain.GenFaultFormation(100, 128,1,125,0.1f,false) &&
//		m_terrain.CreateProceduralTexture("faultformTex") && m_terrain.CreateSlopeLighting();
//}
//
////--------------------------------------------------------------------------------------
//
//bool GameWorld::LoadHeightMapTerrain()
//{
//	return m_terrain.LoadHeightfield("Textures/height128.raw",128) &&
//			m_terrain.CreateProceduralTexture("heightmapTex") && m_terrain.CreateSlopeLighting();
//}
//
////--------------------------------------------------------------------------------------