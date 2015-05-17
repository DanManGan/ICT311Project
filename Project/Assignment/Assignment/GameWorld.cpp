
#include "GameWorld.h"
#include "Singletons.h"

#include "AssetManagement/Texture.h"

//--------------------------------------------------------------------------------------

GameWorld::GameWorld()
{
	BruteForce();
	LoadWorld();
}

//--------------------------------------------------------------------------------------

GameWorld::~GameWorld()
{
}

//--------------------------------------------------------------------------------------

bool GameWorld::LoadWorld()
{	
	m_terrain.SetScaleFactor(1.0f,0.2f,1.0f);

	return m_terrain.LoadHeightfield("Textures/height128.raw",128);
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
	//assetManager->Load(MESH, "Textures/detailmap.tga");
	//std::cout << "asset" << assetManager->GetAsset("Textures/grass.tga") << std::endl;
	//m_terrain.LoadTexture("Textures/grass.bmp");
	//Texture* tex = (Texture*)assetManager->GetAsset("Textures/grass.bmp");
	
	//tex->SetTexID(graphics->BindTexture((Texture*)assetManager->GetAsset("Textures/grass.bmp")));
	//m_terrain.SetTexture(graphics->BindTexture((Texture*)assetManager->GetAsset("Textures/grass.bmp")));
	m_terrain.SetDetailMap(graphics->BindTexture((Texture*)assetManager->GetAsset("Textures/detailmap.tga")));
	m_terrain.AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/lowestTile.tga"));
	m_terrain.AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/lowTile.tga"));
	m_terrain.AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/highTile.tga"));
	m_terrain.AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/highestTile.tga"));
	m_terrain.CreateProceduralTexture("ProceduralTexture");
	assetManager->Load(m_terrain.GetProceduralTexture("ProceduralTexture"));
	//m_terrain.SetTexture(graphics->BindTexture(m_terrain.GetProceduralTexture()));
	m_terrain.SetTexture(graphics->CreateNewTexture(m_terrain.GetProceduralTexture("ProceduralTexture")));
	m_terrain.SetNumTerrainTexRepeat(1);
	//m_terrain.LoadDetailMap("Textures/detailmap.tga");
	m_terrain.SetNumDetailMapRepeat(8);
	//m_terrain.SetTexture(graphics->BindTexture((Texture*)assetManager->GetAsset("ProceduralTexture")));
	m_terrain.SetLightingColor(1.0f, 1.0f, 1.0f);
	m_terrain.SetSlopeLightingParams( 1, 1, 0.2f, 0.9f, 10.0f );
	m_terrain.CreateSlopeLighting();
}

//--------------------------------------------------------------------------------------

void GameWorld::Render()
{
	m_terrain.Render();
}

//--------------------------------------------------------------------------------------

bool GameWorld::InWorld(float& x, float& z)
{
	if(x<0) {
		x=0;
		return false;
	}
	else if(x>m_terrain.GetSize()) {
		x=(float)m_terrain.GetSize();
		return false;
	}

	if(z<0) {
		z=0;
		return false;
	}
	else if(z>m_terrain.GetSize()) {
		z=(float)m_terrain.GetSize();
		return false;
	}

 return true;
}

//--------------------------------------------------------------------------------------

float GameWorld::GetWorldXZHeight(float x, float z)
{
	return m_terrain.GetHeightAverage(x,z);
}

//--------------------------------------------------------------------------------------

float GameWorld::GetWorldSize()
{
	return (float)m_terrain.GetSize();
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