
#include "TerrainModel.h"
#include "../Singletons.h"

//--------------------------------------------------------------------------------------

TerrainModel::TerrainModel()
{
}

//--------------------------------------------------------------------------------------

TerrainModel::~TerrainModel()
{
}

//--------------------------------------------------------------------------------------

void TerrainModel::Render()
{
	//if(m_texMap) {
	graphics->RenderTriangleStrips(m_terrainData, m_size, m_texMapID, m_numTerrainTexRepeat,
								m_detailMapTexID, m_numDetailMapRepeat, m_scale, GetLightMapColour(),  GetLightMap());
	//}

}