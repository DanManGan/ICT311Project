
#include "BruteForce.h"
#include "Singletons.h"

//--------------------------------------------------------------------------------------

BruteForce::BruteForce()
{
}

//--------------------------------------------------------------------------------------

BruteForce::~BruteForce()
{
}

//--------------------------------------------------------------------------------------

void BruteForce::Render()
{
	if(m_texMapNormal) {
	graphics->RenderTriangleStrips(m_terrainData, m_size, m_texMapNormalID, m_numTerrainTexRepeat,
								m_detailMapTexID, m_numDetailMapRepeat, m_scale, GetLightMapColour(),  GetLightMap());
	}

	if(m_texMapProcedural) {
	graphics->RenderTriangleStrips(m_terrainData, m_size, m_texMapProceduralID, m_numTerrainTexRepeat,
								m_detailMapTexID, m_numDetailMapRepeat, m_scale, GetLightMapColour(),  GetLightMap());
	}
}