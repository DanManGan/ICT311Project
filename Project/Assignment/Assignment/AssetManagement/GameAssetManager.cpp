
#include "GameAssetManager.h"

#include <iostream>

GameAssetManager::GameAssetManager()
{
	m_gameAssets.clear();
}

GameAssetManager::~GameAssetManager()
{
	m_gameAssets.clear();
}

bool GameAssetManager::Load(std::string filePath)
{
	gaIter it = m_gameAssets.find(filePath);
	std::cout << filePath << std::endl;
	if(it == m_gameAssets.end()) {
		//GameAsset* temp = m_gameAssetFactory.Load(filePath.c_str());
		m_gameAssets[filePath] = m_gameAssetFactory.Load(filePath.c_str());
	}
	if(m_gameAssets[filePath] == nullptr)
		return false;

	return true;
}

bool GameAssetManager::LoadModel(std::string filePath, std::string texturePath)
{
	gaIter it = m_gameAssets.find(filePath);
	std::cout << filePath << std::endl;
	if(it == m_gameAssets.end()) {
		//GameAsset* temp = m_gameAssetFactory.Load(filePath.c_str());
		m_gameAssets[filePath] = m_gameAssetFactory.LoadModel(filePath.c_str(), texturePath.c_str());
	}
	if(m_gameAssets[filePath] == nullptr)
		return false;

	return true;
}
GameAsset* GameAssetManager::GetAsset(std::string filePath)
{
	return m_gameAssets[filePath];
}