
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

	virtual void Render() = 0;

	virtual void Update(float deltaT) = 0;

	virtual void SetAnimation(unsigned short startFrame, unsigned short endFrame) = 0;

	virtual bool SetSkin(unsigned int skin) = 0;

	virtual bool SetScale(float scaleX, float scaleY, float scaleZ) = 0;

	virtual float GetBase() = 0;

private:

	//unsigned int m_skinID;
};

#endif