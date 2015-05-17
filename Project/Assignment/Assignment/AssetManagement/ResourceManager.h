
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "GameAsset.h"
#include "ResourceLoader.h"

#include <string>
#include <map>

//class ResourceManager;
//
//
//class IResource {
//public:
//    typedef std::string Type;
//
//    virtual const std::string & GetName() const = 0;
//    virtual Type GetType() const = 0;
//    
//    virtual void Dump(std::ostream & o) const = 0;
//    
//protected:
//    virtual ~IResource() {};
//    
//    friend class ResourceMgr;    // The resource manager is the only place resources can be destroyed
//};
//
//std::ostream & operator<< (std::ostream & o, const IResource & res);
 

//class ResourceLoader
//{
//public:
//    virtual GameAsset * Create (FILE * fin) = 0;
//    virtual const char * GetExtension () = 0;
//};
//
//#endif:




class ResourceManager 
{
public:
    ~ResourceManager();

    void Register (ResourceLoader * loader);
    //void Unregister (const std::string & objectType);
    
    GameAsset * Create(const std::string filename);

private:
    GameAsset * LoadResource(const std::string filename);
    
    typedef std::map<std::string, ResourceLoader *> LoaderMap;
    LoaderMap m_loaders;
    
    typedef std::map<std::string, GameAsset *> ResourceMap;
    ResourceMap m_resources;
};

#endif
