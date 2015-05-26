
#include "AABB.h"



#include <iostream>
#include <algorithm>


AABB::AABB()
{
	m_min.Set(0,0,0);
	m_max.Set(0,0,0);
}

AABB::AABB(Vector3D m_minVals, Vector3D m_maxVals)
{
	m_min=m_minVals;
	m_max=m_maxVals;
}

void AABB::CreateAABB(Vector3D vertices[], int numVertices)
{
	 for(int i=0;i<numVertices;i++)
	 {
		 if(vertices[i].x <m_min.x)
		 {
			 m_min.x = vertices[i].x;
		 }
		 if(vertices[i].x>m_max.x)
		 {
			 m_max.x = vertices[i].x;
		 }
		 if(vertices[i].y<m_min.y)
		 {
			 m_min.y = vertices[i].y;
		 }
		 if(vertices[i].y>m_max.y)
		 {
			 m_max.y = vertices[i].y;
		 }
         if(vertices[i].z<m_min.z)
		 {
			 m_min.z = vertices[i].z;
		 }
		 if(vertices[i].z>m_max.z)
		 {
			 m_max.z = vertices[i].z;
		 }
	 }
}

void AABB::CreateAABB(Mesh* model)
{
	std::string extension = model->GetName().substr(model->GetName().find_last_of(".")); //Get the extension
	std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

	if(extension == ".md2")
		CreateAABB((md2*)model);
}

AABB AABB::CreateWorldAABB(AABB aabb,Vector3D worldXYZ)
{
    AABB worldAABB;
    float temp;

    temp=(float)(aabb.m_max.x-aabb.m_min.x)/2.0f;
	worldAABB.m_min.x = worldXYZ.x-temp;
	worldAABB.m_max.x = worldXYZ.x+temp;

	temp=(float)(aabb.m_max.y-aabb.m_min.y)/2.0f;
	worldAABB.m_min.y = worldXYZ.y-temp;
	worldAABB.m_max.y = worldXYZ.y+temp;

	temp=(float)(aabb.m_max.z-aabb.m_min.z)/2.0f;
	worldAABB.m_min.z = worldXYZ.z-temp;
	worldAABB.m_max.z = worldXYZ.z+temp;

    return worldAABB;
}

bool AABB::CheckCollisionWithPoint(Vector3D &point,Vector3D worldXYZ)
{
     AABB worldAABB=CreateWorldAABB(*this,worldXYZ);
     return((point.x>= worldAABB.m_min.x)&&(point.x<=worldAABB.m_max.x)&&
	   (point.y>= worldAABB.m_min.y)&&(point.y<=worldAABB.m_max.y)&&
	   (point.z>= worldAABB.m_min.z)&&(point.z<=worldAABB.m_max.z));
}


bool AABB::CheckCollisionWithPoint(Vector3D &point,AABB &aabb)
{
     return((point.x>= aabb.m_min.x)&&(point.x<=aabb.m_max.x)&&
	   (point.y>= aabb.m_min.y)&&(point.y<=aabb.m_max.y)&&
	   (point.z>= aabb.m_min.z)&&(point.z<=aabb.m_max.z));
}

bool AABB::CheckCollision(Vector3D worldXYZ,AABB &aabb2,Vector3D worldXYZ2)
{
    AABB obj1=CreateWorldAABB(*this,worldXYZ);
    AABB obj2=CreateWorldAABB(aabb2,worldXYZ2);
    Vector3D p[8];

	p[0].Set(obj1.m_min.x,obj1.m_min.y,obj1.m_min.z);
	p[1].Set(obj1.m_max.x,obj1.m_min.y,obj1.m_min.z);
	p[2].Set(obj1.m_max.x,obj1.m_max.y,obj1.m_min.z);
	p[3].Set(obj1.m_min.x,obj1.m_max.y,obj1.m_min.z);
	p[4].Set(obj1.m_min.x,obj1.m_min.y,obj1.m_max.z);
	p[5].Set(obj1.m_max.x,obj1.m_min.y,obj1.m_max.z);
	p[6].Set(obj1.m_max.x,obj1.m_max.y,obj1.m_max.z);
	p[7].Set(obj1.m_min.x,obj1.m_max.y,obj1.m_max.z);

	for(int i=0;i<8;i++)
    {
		if(CheckCollisionWithPoint(p[i],obj2))
			  return  true;
	}
    return false;
}

const AABB &AABB::operator=(const AABB &aabb2)
{
	m_min=aabb2.m_min;
	m_max=aabb2.m_max;
    return *this;
}

void AABB::CreateAABB(md2* model)
{
	//for(int i=0;i<model->GetNumFrames();i++) {
		for(int j=0;j<model->GetNumVertices();j++) {

			if(model->GetFrames()[0].vertices[j].x < m_min.x) {
				m_min.x = model->GetFrames()[0].vertices[j].x;
			}
			if(model->GetFrames()[0].vertices[j].x > m_max.x) {
				m_max.x = model->GetFrames()[0].vertices[j].x;
			}

			if(model->GetFrames()[0].vertices[j].y < m_min.y) {
				m_min.y = model->GetFrames()[0].vertices[j].y;
			}
			if(model->GetFrames()[0].vertices[j].y > m_max.y) {
				m_max.y = model->GetFrames()[0].vertices[j].y;
			}

			if(model->GetFrames()[0].vertices[j].z < m_min.z) {
				m_min.z = model->GetFrames()[0].vertices[j].z;
			}
			if(model->GetFrames()[0].vertices[j].z > m_max.z) {
				m_max.z = model->GetFrames()[0].vertices[j].z;
			}
		}
	//}
}

Vector3D AABB::GetMin()
{
	return m_min;
}

Vector3D AABB::GetMax()
{
	return m_max;
}