
#ifndef GAMEASSETMANAGER_H
#define GAMEASSETMANAGER_H

#include "GameAsset.h"
#include "GameAssetFactory.h"

#include <map>
#include <string>

class GameAssetManager
{
public:

	GameAssetManager();

	~GameAssetManager();

	bool Load(std::string filePath);

	bool LoadModel(std::string filePath, std::string texturePath);

	GameAsset* GetAsset(std::string filePath);

private:

	typedef std::map<std::string, GameAsset*> gameAssets;
	typedef gameAssets::iterator gaIter;

	gameAssets m_gameAssets;

	GameAssetFactory m_gameAssetFactory;
};

#endif