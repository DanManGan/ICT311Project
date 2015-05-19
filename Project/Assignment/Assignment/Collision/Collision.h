#ifndef COLLISION_H
#define COLLISION_H

#include "../Extras/Vector3D.h"
#include <math.h>

bool sphereCollisionTest(Vector3D obj1Centre, Vector3D obj2Centre, float obj1Radius, float obj2Radius);
void getObjectCentre(Vector3D /* in */ vertices[], int /* in */ numVertices, Vector3D /* out */ &centre);
float getBoundingSphereRadius(Vector3D /* in */ vertices[], int /* in */ numVertices, Vector3D /* out */ centre);

#endif