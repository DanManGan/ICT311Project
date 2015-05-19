#include "collision.h"
#include <iostream>
using namespace std;

bool sphereCollisionTest(Vector3D obj1Centre, Vector3D obj2Centre, float obj1Radius, float obj2Radius)
{
  float dist;

   dist=(abs(obj1Centre.x-obj2Centre.x)*abs(obj1Centre.x-obj2Centre.x))
				  +(abs(obj1Centre.y-obj2Centre.y)*abs(obj1Centre.y-obj2Centre.y));
     if( ((obj1Radius+obj2Radius)*(obj1Radius+obj2Radius)) >= dist)
	 {
		 return true;
	 }
 return false;
}

void getObjectCentre(Vector3D /* in */ vertices[], int /* in */ numVertices, Vector3D /* out */ &centre)
{
			float largestX=0.0f;
		float largestY=0.0f;
		float smallestX=1000000.0f;
		float smallestY=1000000.0f;

       if(vertices==NULL)
		   return ;
          //loop through all vertices and find largest and smallest x and y values.
	      for(int counter=0;counter<numVertices;counter++)
		  {
			  if(vertices[counter].x>largestX)
			  {
				  largestX=vertices[counter].x;
			  }
			  if(vertices[counter].x<smallestX)
			  {
				  smallestX=vertices[counter].x;
			  }
			  if(vertices[counter].y>largestY)
			  {
				  largestY=vertices[counter].y;
			  }
			  if(vertices[counter].y<smallestY)
			  {
				  smallestY=vertices[counter].y;
			  }
		  }
	  //calculate largest x and y distances
	  float xSize=largestX-smallestX;
	  float ySize=largestY-smallestY;

	        //calculate centre of object
     // centre.Set(smallestX+(xSize/2),smallestY+(ySize/2));////////////////////////////////////////////
}

	/*------------------------------------------------------------------------------
	|
	|Params:
	|vertices - array of vertice points representing the object
	|numVertices - number of vertices for the object
	|centre - the centre of the objects bounding sphere 
	|returns: radius of a bounding sphere surrounding the object
	*-----------------------------------------------------------------------------*/
	float getBoundingSphereRadius(Vector3D /* in */ vertices[], int /* in */ numVertices, Vector3D /* out */ centre)
	{

	  float dist;
	  float maxDist=0;

        //loop through again and calculate largest distance from centre of object
	      for(int counter=0;counter<numVertices;counter++)
		  {
			  dist=((vertices[counter].x-centre.x)*(vertices[counter].x-centre.x))
				  +((vertices[counter].y-centre.y)*(vertices[counter].y-centre.y));
			  //check max distance
			    if(dist>maxDist)				
				{
					maxDist=dist;
				}
		  }
     return sqrt(maxDist);
	}