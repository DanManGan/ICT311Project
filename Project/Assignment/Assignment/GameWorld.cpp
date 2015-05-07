
#include "GameWorld.h"

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

	return m_terrain.LoadHeightfield("graphics/height128.raw",128);
}

//--------------------------------------------------------------------------------------

void GameWorld::LoadWorldTexture()
{
	//Procedural terrain only works correctly with TGA files currently
	m_terrain.LoadTexture("graphics/grass.bmp");
	m_terrain.LoadProceduralTexture("graphics/lowestTile.tga");
	m_terrain.LoadProceduralTexture("graphics/lowTile.tga");
	m_terrain.LoadProceduralTexture("graphics/highTile.tga");
	m_terrain.LoadProceduralTexture("graphics/highestTile.tga");
	m_terrain.CreateProceduralTexture();
	m_terrain.SetNumTerrainTexRepeat(1);
	m_terrain.LoadDetailMap("graphics/detailmap.tga");
	m_terrain.SetNumDetailMapRepeat(8);
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

bool GameWorld::TextureMapNormal()
{
	return m_terrain.TextureMapNormal();
}

//--------------------------------------------------------------------------------------

bool GameWorld::TextureMapProcedural()
{
	return m_terrain.TextureMapProcedural();
}

//--------------------------------------------------------------------------------------

bool GameWorld::GenFaultFormTerrain()
{
	return m_terrain.GenFaultFormation(100, 128,1,125,0.1f,false) &&
		m_terrain.CreateProceduralTexture() && m_terrain.CreateSlopeLighting();
}

//--------------------------------------------------------------------------------------

bool GameWorld::LoadHeightMapTerrain()
{
	return m_terrain.LoadHeightfield("graphics/height128.raw",128) &&
			m_terrain.CreateProceduralTexture() && m_terrain.CreateSlopeLighting();
}

//--------------------------------------------------------------------------------------