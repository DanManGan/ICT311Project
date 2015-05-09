
#ifndef GAMEASSETFACTORY_H
#define GAMEASSETFACTORY_H

#include "GameAsset.h"

#include <string>


class GameAssetFactory
{
public:

	GameAssetFactory();

	~GameAssetFactory();

	GameAsset* Load(std::string filePath);

private:

};

#endif