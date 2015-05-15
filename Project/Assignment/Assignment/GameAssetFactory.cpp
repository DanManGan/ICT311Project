
#include "GameAssetFactory.h"
#include "textureHandler/textureManager.h"


#include <algorithm>

GameAssetFactory::GameAssetFactory()
{
	textureManager();
	//m_gameAssets.clear();
}

GameAssetFactory::~GameAssetFactory()
{
	//m_gameAssets.clear();
}

GameAsset* GameAssetFactory::LoadTexture(std::string filePath)
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
	if(extension == ".bmp" || extension == ".tga") {
		//Texture* temp = new Texture();

		//temp->Load((char*)filePath.c_str());
		//return temp;
		image* temp = m_textureManager.loadTextureRaw((char*)filePath.c_str());

		//unsigned int temp = m_textureManager.loadTexture((char*)filePath.c_str());

		return new Texture(temp);
	}

	return nullptr;
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