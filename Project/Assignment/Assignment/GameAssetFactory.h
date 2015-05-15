
#ifndef GAMEASSETFACTORY_H
#define GAMEASSETFACTORY_H

#include "GameAsset.h"

#include "textureHandler/textureManager.h"
#include "Texture.h"

#include <string>
#include <map>


class GameAssetFactory
{
public:

	GameAssetFactory();

	~GameAssetFactory();

	GameAsset* LoadTexture(std::string filePath);

	GameAsset* LoadModel(std::string filePath, std::string texturePath);

	//GameAsset* Load(std::string filePath, int size);

private:
	//typedef std::map<std::string, GameAsset*> gameAssets;
	//typedef gameAssets::iterator gaIter;

	//gameAssets m_gameAssets;



	textureManager m_textureManager;	
};

#endif