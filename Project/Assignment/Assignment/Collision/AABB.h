
#ifndef AABB_H
#define AABB_H
#include "../Extras/Vector3D.h"
#include "../AssetManagement/Mesh.h"
#include "../AssetManagement/md2.h"

class AABB
{

public:
	AABB();
	AABB(Vector3D minVals, Vector3D maxVals);
	void CreateAABB(Vector3D vertices[], int numVertices);
	bool CheckCollisionWithPoint(Vector3D &point,Vector3D worldXYZ);
    bool CheckCollision(Vector3D worldXYZ,AABB &aabb2,Vector3D worldXYZ2);
	bool CheckCollision(Vector3D worldXYZ,AABB* aabb2,Vector3D worldXYZ2);
	const AABB &operator=(const AABB &aabb2);

////////////////////////////////////////////////////////////////

	void CreateAABB(Mesh* model);

	Vector3D GetMin();
	Vector3D GetMax();



private:
	Vector3D m_min;
	Vector3D m_max;
	AABB CreateWorldAABB(AABB aabb,Vector3D worldXYZ);
	bool CheckCollisionWithPoint(Vector3D &point,AABB &aabb);

////////////////////////////////////////////////////////////////
   void CreateAABB(md2* model);

};

#endif