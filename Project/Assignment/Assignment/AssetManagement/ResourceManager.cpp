
#include "ResourceManager.h"

#include <algorithm>

ResourceManager::~ResourceManager()
{
    ResourceMap::iterator it = m_resources.begin();
    while (it != m_resources.end()) 
    {
        GameAsset * pRes = (*it).second;
        delete pRes;
        ++it;
    }
}


void ResourceManager::Register(ResourceLoader * loader)
{
	if(loader)
		m_loaders[std::string(loader->GetExtension())] = loader;
}


GameAsset * ResourceManager::Create(const std::string filename)
{
    //filesystem::path full_path (filename);
      
    ResourceMap::iterator it = m_resources.find(filename);
    if (it != m_resources.end()) 
        return (*it).second;
        
    GameAsset * pRes = LoadResource(filename);    
    if (pRes == NULL)
        return NULL;
    
    m_resources[filename] = pRes;     
    return pRes;
}


GameAsset * ResourceManager::LoadResource(const std::string filename)
{
    //filesystem::path path (filename);
    //std::string ext = filesystem::extension(path);

	std::string extension = filename.substr( filename.find_last_of(".") ); //Get the extension
	std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    
    LoaderMap::iterator it = m_loaders.find(extension);
    if (it == m_loaders.end())
        return nullptr;

    ResourceLoader * loader = (*it).second;
    //assert (pMaker != NULL);

    FILE * fin = fopen(filename.c_str(), "rt");

    if (loader && fin) {    
   // GameAsset * pRes = loader->Create(fin);
		GameAsset * pRes = loader->Create((char*)filename.c_str());
    fclose(fin);
        
    return pRes;
	}

	return nullptr;
}


//std::ostream & operator<< (std::ostream & o, const GameAsset & res)
//{
//   res.Dump(o);
//   return o;
//}



