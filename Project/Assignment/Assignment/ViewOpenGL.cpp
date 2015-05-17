

#pragma comment(lib,"glfw.lib")
#define GL_CLAMP_TO_EDGE 0x812F
#include "Singletons.h"
#include "ViewOpenGL.h"
#include "AssetManagement/multitexture.h"

#include <gl/glfw.h>
#include <gl/glut.h>

//--------------------------------------------------------------------------------------

ViewOpenGL::ViewOpenGL() :
  	 m_winWidth(0),
	 m_winHeight(0),
	 m_numTextures(0)
{
	Init();
}

//--------------------------------------------------------------------------------------

ViewOpenGL::~ViewOpenGL()
{
}

//--------------------------------------------------------------------------------------

bool ViewOpenGL::Init()
{
	if(!glfwInit())
		return false;										// if glfwInit fails return false

    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glDisable( GL_TEXTURE_2D );								//disable two dimensional texture mapping
	glDisable( GL_LIGHTING );								//disable lighting
	glDisable( GL_BLEND );									//disable blending
	glEnable( GL_DEPTH_TEST );								//Enable depth testing
	glShadeModel( GL_SMOOTH );								//enable smooth shading
	glClearDepth( 1.0 );									//depth buffer setup
	glDepthFunc( GL_LEQUAL );								//set the type of depth test
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );	//the nicest perspective look
	glEnable( GL_CULL_FACE );								// enable culling back faces


   //GLfloat  mat_specular[]  =  {1.0, 1.0, 1.0, 1.0 };
   //// How shiny material is
   //GLfloat  mat_shininess[] =  {90.0};
   //GLfloat  light_position[] =  {0.0, 0.0, 5.0, 0.0 };
   //GLfloat  lmodel_ambient[] =  {10.0, 10.0, 10.0, 10.0};
   //// Define position of light source
   //glLightfv (GL_LIGHT0, GL_POSITION, light_position);
   //// Define lighting model
   //glLightModelfv (GL_LIGHT_MODEL_AMBIENT,  lmodel_ambient);
   //// Define material properties
   //glMaterialfv (GL_FRONT, GL_SPECULAR,   mat_specular);
   //glMaterialfv (GL_FRONT, GL_SHININESS,  mat_shininess);
   ////Enable lighting
   //glEnable (GL_LIGHTING); // as in turn on power for all lights
   //glEnable (GL_LIGHT0); // as in flip on the light switch

   return true;
}

//--------------------------------------------------------------------------------------

bool ViewOpenGL::OpenWindow(int width, int height)
{
	// if fail to create window terminate program.
	 if(!glfwOpenWindow( width, height, 0,0,0,0, 32,0, GLFW_WINDOW)) {
        glfwTerminate();
        return false;
     }
	 // set window size details to memebers
	 m_winWidth = width;
	 m_winHeight = height;
	 // set window reshape callback function
	 glfwSetWindowSizeCallback(&ViewOpenGL::ReshapeCallback);

	 return true;
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::SetWindowPosition(int x, int y)
{
	  glfwSetWindowPos(x, y); // set window position on screen
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::SetWindowTitle(char* name)
{
	glfwSetWindowTitle(name); // set window ttile
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::Reshape(int width,  int  height)
{
	float ratio = 0.0f;

	m_winWidth=(float)width;
	m_winHeight=(float)height;

	// Prevent a divide by zero, when window is too short
	if(m_winHeight == 0.0f) m_winHeight = 1.0f;
	if(m_winWidth == 0.0f) m_winWidth = 1.0f;
	// Calculate The Aspect Ratio Of The Window
	ratio = width / height;

	// setup new window size
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	glViewport(0,0,m_winWidth,m_winHeight);				// Reset The Current Viewport
	gluPerspective(45.0f,ratio,0.1f,4000.0f);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();

}

//--------------------------------------------------------------------------------------

void ViewOpenGL::ReshapeCallback(int width, int height)
{
	graphics->Reshape(width, height); // set singleton instance as reshape implementation method
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::BeginRendering()
{
	// set all states and values to start rendering
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::EndRendering()
{
	// force execution of buffered commands and swap buffers
	glFlush();
	glfwSwapBuffers();
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::ClearColour(float r, float g, float b, float alpha)
{
	glClearColor( r, g, b, alpha);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::SetColour(unsigned char r, unsigned char g, unsigned char b)
{
	glColor3ub(r, g, b);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::SetWireframeView()
{
	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // set to wireframe
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::SetSolidView()
{
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL ); // set to solid
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::UpdateCamera(Vector3D position, Vector3D lookAt)
{
	// set the camera
	gluLookAt(position.x, position.y, position.z,
               lookAt.x, lookAt.y, lookAt.z,
               0.0, 1.0, 0.0);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::RenderTriangleStrips(unsigned char* verts, int size, unsigned int textureID, int numTerrainTexRepeat,
	unsigned int detailMapID, int numDetailMapRepeat, Vector3D scale, RGB<float> lightColour, unsigned char* lightMap)
{
	unsigned char hcolour = 0;
	float texLeft = 0, texBottom = 0, texTop = 0;
	float shadeHigh = 0, shadeLow = 0;

	glDisable( GL_BLEND );

	glActiveTextureARB(GL_TEXTURE0_ARB );
	//bind texture 0
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glActiveTextureARB( GL_TEXTURE1_ARB );
	//bind texture 1
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,detailMapID);
	glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB );
	glTexEnvi( GL_TEXTURE_ENV, GL_RGB_SCALE_ARB, 2 );

	glEnable( GL_CULL_FACE );

	// iterate through z axis
	for(int z = 0; z < size-1; z++) {
		glBegin(GL_TRIANGLE_STRIP);
		// iterate through x axis
		for(int x = 0; x < size-1; x++) {
				//calculate the texture coordinates
			texLeft = ( float )x/size;
			texBottom= ( float )z/size;
			texTop = ( float )( z+1 )/size;

			// create triangle strip first point
			//hcolour = GetHeightColour(verts, size, x, z);
			//glColor3ub(hcolour, hcolour, hcolour);
			shadeLow = GetHeightColour(lightMap, size, x, z);
			shadeHigh = GetHeightColour(lightMap, size, x, z+1);
			glColor4ub(shadeLow*lightColour.r, shadeLow*lightColour.g,
						shadeLow*lightColour.b, 255);

			// set multi texture deatils for first point
			glMultiTexCoord2fARB( GL_TEXTURE0_ARB, texLeft*numTerrainTexRepeat, texBottom*numTerrainTexRepeat );		
			glMultiTexCoord2fARB( GL_TEXTURE1_ARB, texLeft*numDetailMapRepeat, texBottom*numDetailMapRepeat);
			glVertex3f((float)x*scale.x, GetHeightScaled(verts, size, scale.y, x, z), (float)z*scale.z);


			//create next point in triangle strip
			//hcolour = GetHeightColour(verts, size, x, z+1);
			//glColor3ub(hcolour, hcolour, hcolour);
			glColor4ub(shadeHigh*lightColour.r, shadeHigh*lightColour.g,
						shadeHigh*lightColour.b, 255);
			// set multi texture details for second point
			glMultiTexCoord2fARB( GL_TEXTURE0_ARB,texLeft*numTerrainTexRepeat, texTop*numTerrainTexRepeat );		
			glMultiTexCoord2fARB( GL_TEXTURE1_ARB, texLeft*numDetailMapRepeat, texTop*numDetailMapRepeat);
			glVertex3f((float)x*scale.x, GetHeightScaled(verts, size, scale.y, x, z+1), (float)(z+1)*scale.z);
		}
		glEnd();
	}

	// unbind detail map
	glActiveTextureARB( GL_TEXTURE1_ARB );
	glDisable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, 0 );

	// unbind multitexture
	glActiveTextureARB( GL_TEXTURE0_ARB );
	glDisable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, 0 );


}

//--------------------------------------------------------------------------------------

void ViewOpenGL::Render2D(unsigned int image, float left, float right,
		float top, float bottom)
{
	glColor3f(1.0f, 1.0f, 1.0f); // ensure drawing onto white

	// setup and bind texture
	glActiveTextureARB(GL_TEXTURE0_ARB );
	//bind texture 0
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,image);
	// setup 2D ortho view in window
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0.0, m_winWidth, 0.0, m_winHeight);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glLoadIdentity();

			glBegin(GL_QUADS); // draw to screen
				glMultiTexCoord2fARB( GL_TEXTURE0_ARB, 1, 1);
				glVertex2f(right, top); 
				glMultiTexCoord2fARB( GL_TEXTURE0_ARB, 0, 1);
				glVertex2f(left, top);
				glMultiTexCoord2fARB( GL_TEXTURE0_ARB, 0, 0);
				glVertex2f(left,bottom);
				glMultiTexCoord2fARB( GL_TEXTURE0_ARB, 1, 0);
				glVertex2f(right, bottom);
			glEnd();

			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	// release texture
	glActiveTextureARB( GL_TEXTURE0_ARB );
	glDisable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, 0 );
}

//--------------------------------------------------------------------------------------

unsigned char ViewOpenGL::GetHeightColour(unsigned char* verts, int size, int xPos, int zPos)
{
		return verts[(zPos*size) + xPos];
}

//--------------------------------------------------------------------------------------

float ViewOpenGL::GetHeightScaled(unsigned char* verts, int size, float scaleY, int xPos, int zPos)
{
		return ((float)(verts[(zPos*size)+xPos]) * scaleY);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::Rotate(float angle, float x, float y, float z) 
{
	glRotatef(angle, x, y, z);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::Translate(float x, float y, float z)
{
	glTranslatef(x, y, z);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::Scale(float x, float y, float z)
{
	glScalef(x, y, z);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::PushMatrix()
{
	glPushMatrix();
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::PopMatrix()
{
	glPopMatrix();
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::SwapBuffers()
{
	glutSwapBuffers();
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::LoadIdentity()
{
	glLoadIdentity();
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::DrawSphere(double radius, int slices, int stacks)
{
	glutSolidSphere(radius, slices, stacks);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::DrawCylinder(double baseRadius, double topRadius, double height, int slices, int stacks)
{
	GLUquadricObj* quad = 0;

	quad = gluNewQuadric();

	gluCylinder(quad, baseRadius, topRadius, height, slices, stacks);
}

//--------------------------------------------------------------------------------------

void ViewOpenGL::DrawTree(double baseRadius, double topRadius, double height, int slices, int stacks)
{
	glColor3f(0.52f, 0.37f, 0.26f);
	
	PushMatrix();
	Rotate(-90.0f, 1.0f, 0.0f, 0.0f);
	DrawCylinder(baseRadius, topRadius, height, slices, stacks);
	PopMatrix();

	glColor3f(0.31f, 0.31f, 0.18f);

	PushMatrix();
	Translate(0.0f, height, 0.0f);
	DrawSphere(baseRadius*4, slices, stacks);
	PopMatrix();
}

unsigned int ViewOpenGL::BindTexture(Texture* rawImage)
{
 //image* texture=loadTextureRaw(filename);
        if(!rawImage)
		  return -1;
	m_numTextures++;

	  //unsigned int texID;
	  	glEnable(GL_TEXTURE_2D);
   // glGenTextures(1, &texID);
		 glGenTextures(1, &m_numTextures);

	glBindTexture(GL_TEXTURE_2D, m_numTextures); 
    
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); 
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR ); 
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,rawImage->GetWidth(),rawImage->GetHeight(),0,GL_RGB,GL_UNSIGNED_BYTE,rawImage->GetData());
	glBindTexture(GL_TEXTURE_2D, m_numTextures); 
	//delete texture;
	//texture=NULL;
	return m_numTextures;
}

unsigned int ViewOpenGL::CreateNewTexture(Texture* rawImage)
{
	m_numTextures++;
 glGenTextures( 1, &m_numTextures);
 glEnable( GL_TEXTURE_2D );
  glBindTexture( GL_TEXTURE_2D, m_numTextures);



 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );		
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
//   int iType=texture.GetBPP();
  //				if( iType==24 )
int					iType= GL_RGB;
	//			else
//	int				iType= GL_RGBA;
			//create a mipmapped texture
	
			//gluBuild2DMipmaps( GL_TEXTURE_2D, iType, texture.GetWidth(), texture.GetHeight(), iType, GL_UNSIGNED_BYTE, texture.GetData() );
				gluBuild2DMipmaps( GL_TEXTURE_2D, iType, rawImage->GetWidth(), rawImage->GetHeight(), iType, GL_UNSIGNED_BYTE, rawImage );
			//textureSet=true;
glBindTexture( GL_TEXTURE_2D, m_numTextures);

	return m_numTextures;
}