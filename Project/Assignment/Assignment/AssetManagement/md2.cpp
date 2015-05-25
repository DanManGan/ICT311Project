
#include "md2.h"
#include <cstdio>
//#include "imageLoader/imageFactory.h"
//#include "imageLoader/imageFactory.h"
#include <gl\glut.h>

#include <GL/glfw.h>


int  AnimationValues[21][4] =
{
	{   0,  39,  9, 0 },   // STAND
    {  40,  45, 10, 5 },   // RUN
    {  46,  53, 10, 0 },   // ATTACK
    {  54,  57,  7, 0 },   // PAIN_A
    {  58,  61,  7, 0 },   // PAIN_B
    {  62,  65,  7, 0 },   // PAIN_C
    {  66,  71,  7, 0 },   // JUMP
    {  72,  83,  7, 0 },   // FLIP
    {  84,  94,  7, 0 },   // SALUTE
    {  95, 111, 10, 0 },   // FALLBACK
    { 112, 122,  7, 0 },   // WAVE
    { 123, 134,  6, 0 },   // POINT
    { 135, 153, 10, 0 },   // CROUCH_STAND
    { 154, 159,  7, 2 },   // CROUCH_WALK
    { 160, 168, 10, 0 },   // CROUCH_ATTACK
    { 196, 172,  7, 0 },   // CROUCH_PAIN
    { 173, 177,  5, 0 },   // CROUCH_DEATH
    { 178, 183,  7, 0 },   // DEATH_FALLBACK
    { 184, 189,  7, 0 },   // DEATH_FALLFORWARD
    { 190, 197,  7, 0 },   // DEATH_FALLBACKSLOW
    { 198, 198,  5, 0 },   // BOOM
};

//
//md2::md2() :
//	m_header(nullptr),
//	m_frames(nullptr),
//
//{   //set all variables to zero
//	m_frames=0;
//	m_triangles=0;
//	m_skins=0;
//	m_texCoords=0;
//	skinNumber=0;
//	lastStart=0, 
//    lastEnd=0;	//last start/end parems passed to the function
//    lastFrame=0;	//lastframe rendered
//    lastInterpol=0;		//Last interpolation value
//	m_vertices=NULL;
//	timesAnimated=0;
//	animationSpeed=24;
//	timer.Init();
//}

md2::md2(char* name, md2Header *header, frame* frames,  
	      triangle* triangles, texCoord* texCoords, vertex* vertices) :
	Mesh(name),
	m_header(header),
	m_frames(frames),
	m_triangles(triangles),
	m_texCoords(texCoords),
	m_vertices(vertices),
	m_lastStart(0),
	m_lastEnd(0),
	m_lastFrame(0),
	m_lastInterpol(0.0f),
	m_timesAnimated(0),
	m_animationSpeed(0),
	m_modelSpeed(0),
	m_base(0),
	m_skinID(0),
	m_scale(1.0f, 1.0f, 1.0f)
{
	timer.Init();
}

md2::~md2()
{   
	if(m_header)
		delete m_header;
	if(m_frames)
		delete[] m_frames;
	if(m_triangles)
		delete[] m_triangles;
//	if(m_skins)
//		delete[] m_skins;
	if(m_texCoords)
		delete[] m_texCoords;
	if(m_vertices)
		delete[] m_vertices;
}


void md2::printHeader()
{
 std::cout << m_header;
}


void md2::printModelInfo()
{
	if(!m_frames && !m_triangles && /*!m_skins &&*/ !m_texCoords)
	{
	 cout<<"no model loaded"<<endl;
	}
	else
	{
	 std::cout << m_header;
		for(int i=0;i<m_header->numFrames;i++)
		{
		 std::cout << "frame #: " << i << std::endl;
		 printf("scale x y z:%.2f,%.2f,%.2f\n",m_frames[i].scale[0],m_frames[i].scale[1],m_frames[i].scale[0]); 
		 printf("trans x y z:%.2f,%.2f,%.2f\n",m_frames[i].trans[0],m_frames[i].trans[1],m_frames[i].trans[0]); 
		 std::cout << "name: " << m_frames[i].name << std::endl;
		 for(int j=0;j<m_header->numVertices;j++)
		 {
			 printf("vertices x y z:%.2f,%.2f,%.2f\n",m_frames[i].vertices[j].x,m_frames[i].vertices[j].y,m_frames[i].vertices[j].z);
		 }
		}
		for(int i=0;i<m_header->numTriangles;i++)
		{
		 printf("triangle : %d : x y z:%d,%d,%d\n",i,m_triangles[i].vertIndices[0],m_triangles[i].vertIndices[1],m_triangles[i].vertIndices[2]); 
		}
		for(int i=0;i<m_header->numTexCoords;i++)
		{
		 printf("tex Coords : %d : u v:%.2f,%.2f\n",i,m_texCoords[i].tex[0],m_texCoords[i].tex[1]); 
		}
		//for(int i=0;i<m_header->numSkins;i++)
		//{
	 //    printf("filename : %s\n",m_skins[i].filename); 
		//}
	}
}


void md2::render(unsigned int frameNum)
{
	Vector3D v1,v2,v3;
	  if(m_skinID)
	  {
	   glEnable(GL_TEXTURE_2D);
	   //glBindTexture(GL_TEXTURE_2D,m_skins[m_skinNumber].texID);
	   glBindTexture(GL_TEXTURE_2D,m_skinID);
	  }
	glBegin(GL_TRIANGLES);

	  for(int i = 0; i < m_header->numTriangles; i++)
	  {
		  v1.Set(m_frames[frameNum].vertices[m_triangles[i].vertIndices[0]].x,
		        m_frames[frameNum].vertices[m_triangles[i].vertIndices[0]].y,
				m_frames[frameNum].vertices[m_triangles[i].vertIndices[0]].z);
		  v2.Set(m_frames[frameNum].vertices[m_triangles[i].vertIndices[1]].x,
		        m_frames[frameNum].vertices[m_triangles[i].vertIndices[1]].y,
				m_frames[frameNum].vertices[m_triangles[i].vertIndices[1]].z);
		  v3.Set(m_frames[frameNum].vertices[m_triangles[i].vertIndices[2]].x,
		        m_frames[frameNum].vertices[m_triangles[i].vertIndices[2]].y,
				m_frames[frameNum].vertices[m_triangles[i].vertIndices[2]].z);
		  Vector3D n1=calculateTriangleNormal(v1,v2,v3);

		glNormal3f(n1.x,n1.y,n1.z);

		   if(m_skinID)
				glTexCoord2fv(m_texCoords[m_triangles[i].texIndices[0]].tex);		       
				glVertex3f(v1.x,v1.y,v1.z);

			if(m_skinID)
				glTexCoord2fv(m_texCoords[m_triangles[i].texIndices[1]].tex);		  
				glVertex3f(v2.x,v2.y,v2.z);

			if(m_skinID)
				glTexCoord2fv(m_texCoords[m_triangles[i].texIndices[2]].tex);		  
				glVertex3f(v3.x,v3.y,v3.z);
	   
	  }  
	glEnd();	
	glDisable(GL_TEXTURE_2D);
}


//void md2::Render()
//{
//	render(0);
//}

void md2::renderAnimFrame()
{
  Vector3D v1,v2,v3;

    //Render the new vertices
	 if(m_skinID)
	 {
	   glEnable(GL_TEXTURE_2D);
	   //glBindTexture(GL_TEXTURE_2D,m_skins[m_skinNumber].texID);
	   glBindTexture(GL_TEXTURE_2D,m_skinID);
	 }
	glBegin(GL_TRIANGLES);

	for(int i = 0; i < m_header->numTriangles; i++)
	{
		v1.Set(m_vertices[m_triangles[i].vertIndices[0]].x,
				   m_vertices[m_triangles[i].vertIndices[0]].y,
				   m_vertices[m_triangles[i].vertIndices[0]].z);
		v2.Set(m_vertices[m_triangles[i].vertIndices[1]].x,
		           m_vertices[m_triangles[i].vertIndices[1]].y,
				   m_vertices[m_triangles[i].vertIndices[1]].z);
		v3.Set(m_vertices[m_triangles[i].vertIndices[2]].x,
		           m_vertices[m_triangles[i].vertIndices[2]].y,
   			       m_vertices[m_triangles[i].vertIndices[2]].z);
        Vector3D n1=calculateTriangleNormal(v1,v2,v3);
		glNormal3f(n1.x,n1.y,n1.z);
		 if(m_skinID)
			glTexCoord2fv(m_texCoords[m_triangles[i].texIndices[0]].tex);
		glVertex3f(v1.x,v1.y,v1.z);
		 if(m_skinID)
			glTexCoord2fv(m_texCoords[m_triangles[i].texIndices[1]].tex);
		glVertex3f(v2.x,v2.y,v2.z);	   
	     if(m_skinID)
			glTexCoord2fv(m_texCoords[m_triangles[i].texIndices[2]].tex);
		glVertex3f(v3.x,v3.y,v3.z);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void md2::SetAnimation(AnimationState state)
{
	m_startFrame = AnimationValues[state][START_FRAME];
	m_endFrame = AnimationValues[state][END_FRAME];
	m_animationSpeed = AnimationValues[state][ANIMATION_SPEED];
	m_modelSpeed = AnimationValues[state][MODEL_SPEED];
	//Prevent invalid frame counts
	//if(endFrame >= (unsigned short)m_header->numFrames||endFrame<0) {
	//	m_endFrame = m_header->numFrames-1;
	//}
	//else {
	//	m_endFrame = endFrame;
	//}

	//if(startFrame > (unsigned short)m_header->numFrames||startFrame<0) {
	//	m_startFrame = 0;
	//}
	//else {
	//	m_startFrame = startFrame;
	//}

}

void md2::Update(float deltaT)
{
	unsigned int msPerFrame = 0;			//number of milliseconds per frame
	//alloc a place to put the interpolated vertices
	if(!m_vertices)
		m_vertices = new vertex[m_header->numVertices];


	//avoid calculating everything every frame
	if(m_lastStart != m_startFrame || m_lastEnd != m_endFrame)
	{
		m_lastStart = m_startFrame;
		m_lastEnd = m_endFrame;
		m_timesAnimated=0;
	}

		msPerFrame = (unsigned int)(1000/ m_animationSpeed);
	//Calculate the next frame and the interpolation value
	unsigned int time = timer.GetMS();
		//unsigned int time = deltaT;

	//std::cout << "time: " << time << std::endl;
	float interpolVal = ((float) time / msPerFrame) + m_lastInterpol;
	m_lastInterpol = interpolVal;
	//If the interpolation value is greater than 1, we must increment the frame counter
	while(interpolVal > 1.0f)
	{
		m_lastFrame ++;
		if(m_lastFrame<m_startFrame)
			m_lastFrame=m_startFrame;
		if(m_lastFrame >= m_endFrame)
		{
			m_timesAnimated++;
			m_lastFrame = m_startFrame;
		}
		interpolVal -= 1.0f;
		m_lastInterpol = 0.0f;
	}
	if(m_lastFrame>=m_header->frameSize)
		m_lastFrame=m_startFrame;
	frame* curFrame = &m_frames[m_lastFrame];
	frame* nextFrame = &m_frames[m_lastFrame+1];
  	  if(m_lastFrame >= m_endFrame-1)
		nextFrame = &m_frames[m_startFrame];
	//interpolate the vertices
	for(int i = 0; i < m_header->numVertices; i++)
	{
		m_vertices[i].x = curFrame->vertices[i].x + (nextFrame->vertices[i].x - curFrame->vertices[i].x) * interpolVal;		
		m_vertices[i].y = curFrame->vertices[i].y + (nextFrame->vertices[i].y - curFrame->vertices[i].y) * interpolVal;
		m_vertices[i].z = curFrame->vertices[i].z + (nextFrame->vertices[i].z - curFrame->vertices[i].z) * interpolVal;
	}
    //renderAnimFrame();
interpolVal++;
}

//int md2::animate(unsigned short startFrame, unsigned short endFrame)
int md2::animate()
{	
	unsigned int msPerFrame = 0;			//number of milliseconds per frame
	//alloc a place to put the interpolated vertices
	if(!m_vertices)
		m_vertices = new vertex[m_header->numVertices];


	//avoid calculating everything every frame
	if(m_lastStart != m_startFrame || m_lastEnd != m_endFrame)
	{
		m_lastStart = m_startFrame;
		m_lastEnd = m_endFrame;
		m_timesAnimated=0;
	}

		msPerFrame = (unsigned int)(1000/ m_animationSpeed);
	//Calculate the next frame and the interpolation value
	unsigned int time = timer.GetMS();
		//unsigned int time = deltaT;

	//std::cout << "time: " << time << std::endl;
	float interpolVal = ((float) time / msPerFrame) + m_lastInterpol;
	m_lastInterpol = interpolVal;
	//If the interpolation value is greater than 1, we must increment the frame counter
	while(interpolVal > 1.0f)
	{
		m_lastFrame ++;
		if(m_lastFrame<m_startFrame)
			m_lastFrame=m_startFrame;
		if(m_lastFrame >= m_endFrame)
		{
			m_timesAnimated++;
			m_lastFrame = m_startFrame;
		}
		interpolVal -= 1.0f;
		m_lastInterpol = 0.0f;
	}
	if(m_lastFrame>=m_header->frameSize)
		m_lastFrame=m_startFrame;
	frame* curFrame = &m_frames[m_lastFrame];
	frame* nextFrame = &m_frames[m_lastFrame+1];
  	  if(m_lastFrame >= m_endFrame-1)
		nextFrame = &m_frames[m_startFrame];
	//interpolate the vertices
	for(int i = 0; i < m_header->numVertices; i++)
	{
		m_vertices[i].x = curFrame->vertices[i].x + (nextFrame->vertices[i].x - curFrame->vertices[i].x) * interpolVal;		
		m_vertices[i].y = curFrame->vertices[i].y + (nextFrame->vertices[i].y - curFrame->vertices[i].y) * interpolVal;
		m_vertices[i].z = curFrame->vertices[i].z + (nextFrame->vertices[i].z - curFrame->vertices[i].z) * interpolVal;
	}
    //renderAnimFrame();
interpolVal++;
 return m_timesAnimated;
}

bool md2::SetScale(float xScale, float yScale, float zScale)
{
	if(xScale > 0 && yScale > 0 && zScale > 0) {
		m_scale.Set(xScale, yScale, zScale);

		for(int i=0;i<m_header->numFrames;i++) {
			for(int j=0;j<m_header->numVertices;j++) {
				m_frames[i].vertices[j].x *= m_scale.x;
				m_frames[i].vertices[j].y *= m_scale.y;
				m_frames[i].vertices[j].z *= m_scale.z;
				}
			}
		return true;
	}
	return false;
}

bool md2::SetSkin(unsigned int tex)
{
	if(tex) {
		m_skinID = tex;
		std::cout << "skin " << m_skinID << std::endl;
		return true;
	}
	return false;
}

void md2::CalcBase()
{
	float min = 0.0f, max = 0.0f;

	//for(int i=0;i<m_header->numFrames;i++) {
		for(int j=0;j<m_header->numVertices;j++) {
			if(m_frames[0].vertices[j].y < min) {
				min = m_frames[0].vertices[j].y;
			}
			if(m_frames[0].vertices[j].y > max) {
				max = m_frames[0].vertices[j].y;
			}
		}
	//}

	//m_base = (max-min) * m_scale.y * 0.5f;
	//float ratio = 0.0f;
	//float height = max - min;
	//if(min < 0.0f)
	//	ratio = -min/height;
	//else
	//	ratio = min/height;
	//m_base = (height * ratio) - 1.5f; //(max-min);
		m_base = (max - min) / 2;
	std::cout << "min " << min << " max " << max << " base " << m_base << std::endl;

	//m_base = 8;
}

float md2::GetBase()
{
	CalcBase();
	return m_base;
}

float md2::GetModelSpeed()
{
	return m_modelSpeed;
}

int md2::GetNumFrames()
{
	return m_header->numFrames;
}

int md2::GetNumVertices()
{
	return m_header->numVertices;
}

frame* md2::GetFrames()
{
	return m_frames;
}

Vector3D md2::calculateTriangleNormal(const Vector3D v1, const Vector3D v2, const Vector3D v3)
{
  Vector3D nv1=v2-v1;
  Vector3D nv2=v3-v1;
  Vector3D norm=nv1.CrossProduct(nv2);
  norm.Normalise();

	return norm;
}

/*****************************************************************************
*Purpose: cycles through a single animation sequence between startFrame and  
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
//bool md2::animateOnce(unsigned short startFrame, unsigned short endFrame, unsigned short &curFrame)
//{
//	  if(curFrame>endFrame)
//		  return true;
//	  if(curFrame<startFrame)
//		  curFrame=startFrame;
//	animate(startFrame,endFrame);
//	curFrame++;
// return false;
//}

//void md2::setAnimationSpeed(unsigned short speed)
//{
//	if(speed>0 && speed <=50)
//		m_animationSpeed=speed;
//}

//int md2::GetNumTriangles()
//{
//	return m_numTriangles;
//}

