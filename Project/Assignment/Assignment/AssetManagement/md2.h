/******************************************************************************
* fileName: md2Loader.h
* Author  : David Bennett
* Legal   : use it, dont, whatever. Just dont bitch at me.
* Date    : 17/03/2005
* Purpose : class for reading in a quake md2 model
*         : contains opengl code. Replace with functions from your own graphics
*           engine.
******************************************************************************/
#ifndef MD2_H
#define MD2_H

//#include <iostream>
//#include <fstream>
//using namespace std;
#include "md2Header.h"

//#include "md2Loader.h"
#include "../Extras/timer.h"
//#include <GL/glu.h>
#include "../Extras/Vector3D.h"
//#include "ResourceLoader.h"
#include "Mesh.h"

//#include "md2Animation.h"
//a single vertex
struct vertex
{
	float x,y,z;
	unsigned char normIndex;  //unused
};

// single MD2 triangle
struct triangle
{
	unsigned short vertIndices[3];
	unsigned short texIndices[3];
};


// Texture coord information for the MD2
struct texCoord
{
	float tex[2];
};

//Name of a single skin in the md2 file
struct skin
{
	char filename[64];	//filename
	unsigned int texID;		//Image file ready for texturing
};

struct frame
{
	//header
    float scale[3];    //x,y,z scaling factors for the frame vertices
	float trans[3];    //x,y,z translation factors for the frame vertices
	char name[16];     //ASCI filename for the model
    vertex* vertices;
    
	frame(){vertices=0;}
	~frame()
	{
		if(vertices)
			delete[] vertices;
	}
};


/* GL command packet */
struct md2_glcmd_t
{
  float s;                    /* s texture coord. */
  float t;                    /* t texture coord. */
  int index;                  /* vertex index */
};

class md2 : public Mesh
 {

public:


   /*****************************************************************************
   *Purpose: default constructor
   *****************************************************************************/
   //md2();

   md2(char* name, md2Header *header, frame* frames,  
	      triangle* triangles, texCoord* texCoords, vertex* vertices);

   /*****************************************************************************
   *Purpose: destructor
   *****************************************************************************/
   ~md2();
   /*****************************************************************************
   *Purpose: Prints out the header values
   *Pre : none
   *Post: header values displayed
   *****************************************************************************/
   void printHeader();
   /*****************************************************************************
   *Purpose: Loads an MD2 model from file
   *Pre : filename is an assigned value
   *Post: model is loaded
   *returns: true if model loaded, otherwise false
   *Vars: filename - the filename containing the MD2 model
   *****************************************************************************/  
   //bool loadModel(char* filename,char* skinName);
   void printModelInfo();
   //bool addCustomSkin(char* filename);
   //int setTex(char* filename);
   bool SetSkin(unsigned int tex);
   void render(unsigned int frameNum);
   virtual void Render(Vector3D position, float yaw)=0;
   //int animate(unsigned short startFrame, unsigned short endFrame);
   int animate();
   /*****************************************************************************
   *Purpose: cycles through a single animation sequence between startFrame and  *
   *         endFrame.
   *Pre : all vars are assigned values >= 0
   *Post: animates a single cycle.
   *returns: true if animation cycle complete, otherwise false
   *Vars: fps - frames per second
   *      startFrame - starting frame of the animation
   *      endFrame - ending frame of the animation
   *      curFrame - the current frame to be rendered. The function updates its 
   *                 value. Should be set to the same value as startFrame on first
   *                 call to the function.
   *****************************************************************************/ 
  // bool animateOnce(unsigned short startFrame, unsigned short endFrame, unsigned short &curFrame);
   //unsigned short getSkinNumber(){return m_skins[0].texID;}
  // void setAnimationSpeed(unsigned short speed);

   void SetAnimation(AnimationState state);

   bool SetScale(float xScale, float yScale, float zScale);

   void Update(float deltaT);

   void CalcBase();

   float GetBase();

   float GetModelSpeed();

   int GetNumFrames();

   int GetNumVertices();

   frame* GetFrames();

   Vector3D calculateTriangleNormal(const Vector3D v1, const Vector3D v2, const Vector3D v3);


//private:
 protected:


   md2Header* m_header;
   frame* m_frames;
   triangle* m_triangles;
   //skin* m_skins;
   texCoord* m_texCoords;
   vertex* m_vertices;
   int m_base;

   Vector3D m_scale;

   //int m_numTriangles;
   unsigned int m_startFrame;
   unsigned int m_endFrame;
   unsigned int m_lastStart;
   unsigned int	m_lastEnd;	//last start/end params passed to the function
   unsigned int m_lastFrame;	//lastframe rendered
   float m_lastInterpol;		//Last interpolation value
  // bool validFile();
  // bool readTriangles(char*);
  // bool readSkins(char*);
  // bool readTextures(char* buf);
  // bool readFrames(char*);
   void renderAnimFrame();
   int m_timesAnimated;
   unsigned short m_animationSpeed;
   float m_modelSpeed;
   
   //unsigned short m_skinNumber;   //current skin number
   unsigned int m_skinID;
   //Interpolated vertices
	
	CTimer timer;

	
  };

#endif

