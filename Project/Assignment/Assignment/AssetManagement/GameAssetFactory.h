
#ifndef GAMEASSETFACTORY_H
#define GAMEASSETFACTORY_H

#include "GameAsset.h"
#include "ResourceManager.h"

//#include "textureHandler/textureManager.h"
//#include "textureHandler/imageFactory.h"

#include "Texture.h"

#include <string>
#include <map>


class GameAssetFactory
{
public:

	GameAssetFactory();

	~GameAssetFactory();

	GameAsset* Load(std::string filePath);

	GameAsset* LoadModel(std::string filePath, std::string texturePath);

	//GameAsset* Load(std::string filePath, int size);

private:
	typedef std::map<std::string, GameAsset*> gameAssets;
	typedef gameAssets::iterator gaIter;

	//gameAssets m_gameAssets;
	
	ResourceManager m_manager;

};

#endif