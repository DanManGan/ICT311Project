#include"SC_Terrain.h"
#include"../Singletons.h"

SC_Terrain::SC_Terrain()
{
	lua.runScript("ScriptEngine/Scripts/TerrainProperties.lua");
}

bool SC_Terrain::LoadHeightfile()
{
	char* hm = lua.getGlobalc_str("Heightmap");
	const int size = lua.getGlobalInt("HeightmapSize");

	return(Terrain::LoadHeightfield(hm, size));
}

bool SC_Terrain::LoadHeightfield()
{
	char* hm = lua.getGlobalc_str("Heightmap");

	return(Terrain::LoadHeightfield((Texture*)assetManager->GetAsset(hm)));
}

void SC_Terrain::SetScaleFactor()
{
	float x = lua.getGlobalFloat("xScale");
	float y = lua.getGlobalFloat("yScale");
	float z = lua.getGlobalFloat("zScale");

	Terrain::SetScaleFactor(x, y, z);
}

bool SC_Terrain::genFaultFormation()
{
	int itr = lua.getGlobalInt("Iterations");
	int size = lua.getGlobalInt("Size");
	int min = lua.getGlobalInt("MinHeight");
	int max = lua.getGlobalInt("MaxHeight");
	float weight = lua.getGlobalFloat("Weight");
	bool random = lua.getGlobalBool("RandomGen");

	return(Terrain::GenFaultFormation(itr, size, min, max, weight, random));
}

bool SC_Terrain::SetTexture()
{
	return(Terrain::SetTexture(graphics->CreateNewTexture(GetProTexData(), 
														  GetProTexWidth(), 
														  GetProTexHeight())));
}

bool SC_Terrain::SetDetailMap()
{
	char* file = lua.getGlobalc_str("DetailMap");
	return(Terrain::SetDetailMap(graphics->SetupTextureBasic((Texture*)assetManager->GetAsset(file))));
}

void SC_Terrain::SetNumTerrainTexRepeat()
{
	int i = lua.getGlobalInt("TerrainTextureRepeat");
	Terrain::SetNumTerrainTexRepeat(i);
}

void SC_Terrain::SetNumDetailMapRepeat()
{
	int i = lua.getGlobalInt("DetailTextureRepeat");
	Terrain::SetNumDetailMapRepeat(i);
}

void SC_Terrain::AddProceduralTextures()
{
	std::string str = lua.getGlobalString("TextureLowest");
	if(str != "")
		Terrain::AddProceduralTexture((Texture*)assetManager->GetAsset(str));
	str = lua.getGlobalString("TextureLow");
	if(str != "")
		Terrain::AddProceduralTexture((Texture*)assetManager->GetAsset(str));
	str = lua.getGlobalString("TextureHigh");
	if(str != "")
		Terrain::AddProceduralTexture((Texture*)assetManager->GetAsset(str));
	str = lua.getGlobalString("TextureHighest");
	if(str != "")
		Terrain::AddProceduralTexture((Texture*)assetManager->GetAsset(str));
}

void SC_Terrain::SetLightingColor()
{
	float red = lua.getGlobalFloat("Red");
	float green = lua.getGlobalFloat("Green");
	float blue = lua.getGlobalFloat("Blue");

	Terrain::SetLightingColor(red, green, blue);
}

void SC_Terrain::SetSlopeLightingParams()
{
	int dirx = lua.getGlobalInt("DirectionX");
	int dirz = lua.getGlobalInt("DirectionZ");
	float minB = lua.getGlobalFloat("MinBrightness");
	float maxB = lua.getGlobalFloat("MaxBrightness");
	float soft = lua.getGlobalFloat("Softness");

	Terrain::SetSlopeLightingParams(dirx, dirz, minB, maxB, soft);
}







