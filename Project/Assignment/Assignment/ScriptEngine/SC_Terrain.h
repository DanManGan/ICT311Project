#ifndef SC_TERRAIN_H
#define SC_TERRAIN_H


#include"../Graphics/TerrainModel.h"
#include "LuaEngine.h"
#include <string>

class SC_Terrain : public TerrainModel
{
public:
	SC_Terrain();

	~SC_Terrain() {};

	bool LoadHeightfile();
	bool LoadHeightfield();

	void SetScaleFactor();

	bool genFaultFormation();
	bool SetTexture();
	bool SetDetailMap();
	void SetNumTerrainTexRepeat();
	void SetNumDetailMapRepeat();

	void AddProceduralTextures();

	void SetLightingColor();
	void SetSlopeLightingParams();

private:
	LuaEngine lua;
};


#endif