
#ifndef AABB_H
#define AABB_H
#include "../Extras/Vector3D.h"

class AABB
{
private:
   Vector3D min;
   Vector3D max;
   AABB createWorldAABB(AABB aabb,Vector3D worldXYZ);
   bool checkCollisonWithPoint(Vector3D &point,AABB &aabb);

public:
	AABB();
	AABB(Vector3D minVals, Vector3D maxVals);
	void createAABB(Vector3D vertices[], int numVertices);
	bool checkCollisonWithPoint(Vector3D &point,Vector3D worldXYZ);
    bool checkCollison(Vector3D worldXYZ,AABB &aabb2,Vector3D worldXYZ2);
	const AABB &operator=(const AABB &aabb2);
};

#endif