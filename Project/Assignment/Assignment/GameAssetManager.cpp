
#include "GameAssetManager.h"

GameAssetManager::GameAssetManager()
{
	m_gameAssets.clear();
}

GameAssetManager::~GameAssetManager()
{
	m_gameAssets.clear();
}

bool GameAssetManager::Load(const std::string filePath)
{
	gaIter it = m_gameAssets.find(filePath);

	if(it == m_gameAssets.end()) {
		m_gameAssets[filePath] = m_gameAssetFactory.Load(filePath);
	}
	if(m_gameAssets[filePath] == nullptr)
		return false;

	return true;
}