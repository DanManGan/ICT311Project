
#include "GameAsset.h"

GameAsset::GameAsset() :
	m_name("")
	//m_assetType(NONE)
{
}

GameAsset::GameAsset(std::string name)
{
	if(!SetName(name)) {
		m_name = "";
	}
}

GameAsset::~GameAsset()
{
}

//void GameAsset::SetAssetType(GameAssetType type)
//{
//	m_assetType = type;
//}
//
bool GameAsset::SetName(std::string name)
{
	if(name.length() > 0) {
		m_name = name;
		return true;
	}
	return false;
}
//
//GameAssetType GameAsset::GetAssetType()
//{
//	return m_assetType;
//}

std::string GameAsset::GetName()
{
	return m_name;
}