
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
	//return true;
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
	assetManager->Load("Textures/heightmap.bmp");
	//assetManager->Load(MESH, "Textures/detailmap.tga");
	//std::cout << "asset" << assetManager->GetAsset("Textures/grass.tga") << std::endl;
	//m_terrain.LoadTexture("Textures/grass.bmp");
	//Texture* tex = (Texture*)assetManager->GetAsset("Textures/detailmap.tga");
	//std::cout << "detail " << tex->GetName() << std::endl;
	//tex->SetTexID(graphics->BindTexture((Texture*)assetManager->GetAsset("Textures/grass.bmp")));
	//m_terrain.SetTexture(graphics->BindTexture((Texture*)assetManager->GetAsset("Textures/grass.bmp")));
	//m_terrain.LoadHeightfield((Texture*)assetManager->GetAsset("Textures/heightmap.bmp"));
	m_terrain.SetDetailMap(graphics->BindTexture((Texture*)assetManager->GetAsset("Textures/detailmap.tga")));
	m_terrain.AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/lowestTile.tga"));
	m_terrain.AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/lowTile.tga"));
	m_terrain.AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/highTile.tga"));
	m_terrain.AddProceduralTexture((Texture*)assetManager->GetAsset("Textures/highestTile.tga"));
	m_terrain.CreateProceduralTexture();
	//assetManager->Load(m_terrain.GetProceduralTexture("ProceduralTexture"));
	m_terrain.SetTexture(graphics->CreateNewTexture(m_terrain.GetProTexData(), m_terrain.GetProTexWidth(), m_terrain.GetProTexHeight()));
	m_terrain.SetNumTerrainTexRepeat(1);
	//m_terrain.LoadDetailMap("Textures/detailmap.tga");
	m_terrain.SetNumDetailMapRepeat(8);
	//m_terrain.SetTexture(graphics->BindTexture((Texture*)assetManager->GetAsset("ProceduralTexture")));
	m_terrain.SetLightingColor(1.0f, 1.0f, 1.0f);
	m_terrain.SetSlopeLightingParams( 1, 1, 0.2f, 0.9f, 10.0f );
	m_terrain.CreateSlopeLighting();

	assetManager->Load("Models/Ogro/Tris.md2");
	assetManager->Load("Models/Ogro/Ogrobase.pcx");

	m_objects["ogro"] = new NPC();
	m_objects["ogro"]->SetMesh(assetManager->GetAsset("Models/Ogro/Tris.md2"));
	m_objects["ogro"]->SetSkin(graphics->BindTexture(assetManager->GetAsset("Models/Ogro/Ogrobase.pcx")));

}

//--------------------------------------------------------------------------------------

void GameWorld::Render()
{
	m_terrain.Render();

	graphics->PushMatrix();
	graphics->LightOn(GL_LIGHT0);
	//m_terrain.GetHeightAverage();
	//std::cout << "height scaled: " << m_terrain.GetHeightScaled(70, 93) << std::endl;
	//float modelHeight = ((float)m_model.GetHeight() * 0.25f) * 0.25f;
	//graphics->Translate(52,m_terrain.GetHeightAverage(52,92) + modelHeight,92);
	graphics->Translate(52,m_terrain.GetHeightAverage(52,92),92);
	//glRotatef(45,0,1,0);
	graphics->Scale(0.25f,0.25f,0.25f);
	//if(m_animate)
	//{		 
		//m_model.animate(m_animateStartFrame,m_animateEndFrame);
	//}
	//else
	//{
		m_objects["ogro"]->Render();
	//}

	graphics->LightOff(GL_LIGHT0);
	graphics->PopMatrix();
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