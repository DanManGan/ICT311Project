
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
	//if(m_texMap) {
	graphics->RenderTriangleStrips(m_terrainData, m_size, m_texMapID, m_numTerrainTexRepeat,
								m_detailMapTexID, m_numDetailMapRepeat, m_scale, GetLightMapColour(),  GetLightMap());
	//}

}