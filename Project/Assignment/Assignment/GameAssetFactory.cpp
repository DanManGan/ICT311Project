
#include "GameAssetFactory.h"
#include "textureHandler/bmpLoader.h"
#include "textureHandler/tgaLoader.h"

#include <algorithm>

GameAssetFactory::GameAssetFactory()
{

}

GameAssetFactory::~GameAssetFactory()
{

}

GameAsset* GameAssetFactory::Load(std::string filePath)
{
	std::string extension = filePath.substr( filePath.find_last_of(".") ); //Get the extension
	std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

	if(extension == "bmp") {
		return new bmpLoader;
	}
	else if(extension == "tga") {
		return new tgaLoader;
	}

	return nullptr;
}