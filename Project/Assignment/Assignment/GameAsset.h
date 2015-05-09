
/** 
  * @class Asset
  * @brief Asset class
  * 
  * Used to represent assets.
  * 
  * 
  * 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 08.05.15
  * @status under construction
  * 
  * @author 
  * @version 
  * @date 
  * @status 
  * 
  * @todo 
  * 
  * @bugs 
  */

#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <string>

enum GameAssetType 
{
	NONE = 0,
	TEXTURE,
	MESH,
	TERRAIN 
};
 
class GameAsset
{
public:

	GameAsset();

	~GameAsset();

	//void SetAssetType(GameAssetType type);

	//bool SetAssetName(std::string assetName);

	//bool SetFilePath(std::string filePath);

	//GameAssetType GetAssetType();

	//std::string GetAssetName();

	//std::string GetFilePath();

protected:

	//GameAssetType m_assetType;

	//std::string m_assetName;

	//std::string m_filePath;

private:

};

#endif