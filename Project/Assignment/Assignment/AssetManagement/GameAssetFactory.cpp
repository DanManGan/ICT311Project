
#include "GameAssetFactory.h"
//#include "textureHandler/textureManager.h"
#include "pcxLoader.h"
#include "bmpLoader.h"
#include "tgaLoader.h"


#include <algorithm>
#include <iostream>

GameAssetFactory::GameAssetFactory() :
	m_manager(ResourceManager())
{
	//textureManager();
	//ResourceManager();
	//m_gameAssets.clear();

	m_manager.Register(new bmpLoader());
	m_manager.Register(new tgaLoader());
	m_manager.Register(new pcxLoader());
}

GameAssetFactory::~GameAssetFactory()
{
	//m_gameAssets.clear();
}

GameAsset* GameAssetFactory::Load(std::string filePath)
{
	//std::string extension = filePath.substr( filePath.find_last_of(".") ); //Get the extension
	//std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

	//std::cout << extension << std::endl;
	//if(extension == ".bmp" || extension == ".tga") {
	//	image* temp = m_textureManager.loadTextureRaw((char*)filePath.c_str());
	//	//unsigned int temp = m_textureManager.loadTexture((char*)filePath.c_str());
	//	//return new Texture(temp);
	//}

	//return nullptr;

	GameAsset* asset = m_manager.Create(filePath);

	if(!asset)
		return nullptr;

	return asset;
}

GameAsset* GameAssetFactory::LoadModel(std::string filePath, std::string texturePath)
{
	std::string extension = filePath.substr( filePath.find_last_of(".") ); //Get the extension
	std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

	//if(extension == "bmp") {
	//	return new bmpLoader;
	//}
	//else if(extension == "tga") {
	//	return new tgaLoader;
	//}
	std::cout << extension << std::endl;
	if(extension == ".md2") {
		//Texture* temp = new Texture();

		//temp->Load((char*)filePath.c_str());
		//return temp;
		//return new Texture((char*)filePath.c_str());
	}

	return nullptr;
}