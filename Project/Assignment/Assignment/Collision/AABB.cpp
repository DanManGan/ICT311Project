#include "AABB.h"
#include <iostream>
using namespace std;

AABB::AABB()
{
	min.Set(0,0,0);
	max.Set(0,0,0);
}

AABB::AABB(Vector3D minVals, Vector3D maxVals)
{
	min=minVals;
	max=maxVals;
}

void AABB::createAABB(Vector3D vertices[], int numVertices)
{
	 for(int i=0;i<numVertices;i++)
	 {
		 if(vertices[i].x <min.x)
		 {
			 min.x = vertices[i].x;
		 }
		 if(vertices[i].x>max.x)
		 {
			 max.x = vertices[i].x;
		 }
		 if(vertices[i].y<min.y)
		 {
			 min.y = vertices[i].y;
		 }
		 if(vertices[i].y>max.y)
		 {
			 max.y = vertices[i].y;
		 }
         if(vertices[i].z<min.z)
		 {
			 min.z = vertices[i].z;
		 }
		 if(vertices[i].z>max.z)
		 {
			 max.z = vertices[i].z;
		 }
	 }
}

AABB AABB::createWorldAABB(AABB aabb,Vector3D worldXYZ)
{
    AABB worldAABB;
    float temp;

    temp=(float)(aabb.max.x-aabb.min.x)/2.0;
	worldAABB.min.x = worldXYZ.x-temp;
	worldAABB.max.x = worldXYZ.x+temp;

	temp=(float)(aabb.max.y-aabb.min.y)/2.0;
	worldAABB.min.y = worldXYZ.y-temp;
	worldAABB.max.y = worldXYZ.y+temp;

	temp=(float)(aabb.max.z-aabb.min.z)/2.0;
	worldAABB.min.z = worldXYZ.z-temp;
	worldAABB.max.z = worldXYZ.z+temp;

    return worldAABB;
}

bool AABB::checkCollisonWithPoint(Vector3D &point,Vector3D worldXYZ)
{
     AABB worldAABB=createWorldAABB(*this,worldXYZ);
     return((point.x>= worldAABB.min.x)&&(point.x<=worldAABB.max.x)&&
	   (point.y>= worldAABB.min.y)&&(point.y<=worldAABB.max.y)&&
	   (point.z>= worldAABB.min.z)&&(point.z<=worldAABB.max.z));
}


bool AABB::checkCollisonWithPoint(Vector3D &point,AABB &aabb)
{
     return((point.x>= aabb.min.x)&&(point.x<=aabb.max.x)&&
	   (point.y>= aabb.min.y)&&(point.y<=aabb.max.y)&&
	   (point.z>= aabb.min.z)&&(point.z<=aabb.max.z));
}

bool AABB::checkCollison(Vector3D worldXYZ,AABB &aabb2,Vector3D worldXYZ2)
{
    AABB obj1=createWorldAABB(*this,worldXYZ);
    AABB obj2=createWorldAABB(aabb2,worldXYZ2);
    Vector3D p[8];

	p[0].Set(obj1.min.x,obj1.min.y,obj1.min.z);
	p[1].Set(obj1.max.x,obj1.min.y,obj1.min.z);
	p[2].Set(obj1.max.x,obj1.max.y,obj1.min.z);
	p[3].Set(obj1.min.x,obj1.max.y,obj1.min.z);
	p[4].Set(obj1.min.x,obj1.min.y,obj1.max.z);
	p[5].Set(obj1.max.x,obj1.min.y,obj1.max.z);
	p[6].Set(obj1.max.x,obj1.max.y,obj1.max.z);
	p[7].Set(obj1.min.x,obj1.max.y,obj1.max.z);
	for(int i=0;i<8;i++)
    {
		if(checkCollisonWithPoint(p[i],obj2))
			  return  true;
	}
    return false;
}

const AABB &AABB::operator=(const AABB &aabb2)
{
	min=aabb2.min;
	max=aabb2.max;
    return *this;
}