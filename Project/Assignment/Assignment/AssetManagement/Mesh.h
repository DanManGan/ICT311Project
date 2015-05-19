
#ifndef MESH_H
#define MESH_H

#include "GameAsset.h"

enum MeshType 
{
	MD2 = 0,
	OBJ
};

class Mesh : public GameAsset
{
public:

	Mesh();

	Mesh(char* name);

	~Mesh();

	virtual void Render()=0;

	virtual bool SetSkin(unsigned int skin)=0;

private:
};

#endif