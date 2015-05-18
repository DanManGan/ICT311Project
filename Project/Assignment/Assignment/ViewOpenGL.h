
/** 
  * @class ViewOpenGL
  * @brief OpenGL Graphics Facade Class
  * 
  * Facade class for OpenGL.
  * Provides high level graphics functions to be used for
  * rendering with OpenGL and GLFW library without the need 
  * to make specific function calls to OpenGL API
  * 
  * 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 20.04.15
  * @status under construction
  * 
  * @author 
  * @version 
  * @date 
  * @status 
  * 
  * @todo 
  * 
  * @bugs 
  */ 


#ifndef VIEWOPENGL_H
#define VIEWOPENGL_H

#include "Vector3D.h"
//#include "textureHandler\image.h"
#include "AssetManagement/Texture.h"

class ViewOpenGL
{
public:
	
	/** 
	  * @brief Default constructor
	  * @warning None
	  * 
	  * Default class constructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	ViewOpenGL();

	/** 
	  * @brief Default destructor
	  * @warning None
	  * 
	  * Default class destructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	~ViewOpenGL();

	/** 
	  * @brief Initialise OpenGL
	  * @warning None
	  * 
	  * Initialises all the variables and states required for
	  * OpenGL and GLFW library
	  * 
	  * @return bool value true for initialisation success
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool Init();

	/** 
	  * @brief Open new window
	  * @warning None
	  * 
	  * Creates and opens a new window of the specified height and width
	  * Sets the window reshape callback function 
	  * 
	  * @param width: int type variable in ViewOpenGL class for window width
	  * @param height: int type variable in ViewOpenGL class for window height
	  * @return bool value true to indicate window created
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool OpenWindow(int width, int height);

	/** 
	  * @brief Sets on screen window position
	  * @warning None
	  * 
	  * Sets the window position on the screen according to the
	  * x and y values passed in.
	  * x and y are for the upper left corner of the window
	  * 
	  * @param x: int type variable in ViewOpenGL class for x axis screen position
	  * @param y: int type variable in ViewOpenGL class for y axis screen position
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetWindowPosition(int x, int y);

	/** 
	  * @brief Sets window title
	  * @warning None
	  * 
	  * Sets the title of the window on the screen according to the 
	  * characters passed in
	  * 
	  * @param name: char pointer type variable in ViewOpenGL class for window title
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetWindowTitle(char* name);

	/** 
	  * @brief Reshape implementation method
	  * @warning None
	  * 
	  * Method to handle the actual reshaping of a window.
	  * Adjusts the view via associated function calls to ensure aspect 
	  * ratio etc are maintained as the window is reshaped
	  * 
	  * @param width: int type variable in ViewOpenGL class for window width
	  * @param height: int type variable in ViewOpenGL class for window height
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Reshape(int width,  int  height);

	/** 
	  * @brief Reshape function for OpenGL callback
	  * @warning None
	  * 
	  * Static function for OpenGL/GLFW window size callback function
	  * This method is used to call the instance reshape method
	  * created static to meet callback function requirements
	  * 
	  * @param width: int type variable in ViewOpenGL class for window width
	  * @param height: int type variable in ViewOpenGL class for window height
	  * 
	  * @pre 
	  * @post 
	  */ 
	static void ReshapeCallback(int width, int height);

	/** 
	  * @brief Call pre-render functions
	  * @warning None
	  * 
	  * Clears colour and depth buffer, sets to matrix mode to model view
	  * and loads the identity matrix before rendering
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void BeginRendering();

	/** 
	  * @brief Call post-render functions
	  * @warning None
	  * 
	  * Forces execution of buffered commands and then swaps graphics buffers
	  * for display to screen
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void EndRendering();

	/** 
	  * @brief Set Clear Colour buffer values
	  * @warning None
	  * 
	  * Specify the red, green, blue, and alpha values used when the
      * color buffers are cleared. The initial values are all 0.
	  * 
	  * @param r: float type variable in ViewOpenGL class for red value
	  * @param g: float type variable in ViewOpenGL class for green value
	  * @param b: float type variable in ViewOpenGL class for blue value
	  * @param alpha: float type variable in ViewOpenGL class for alpha value
	  * 
	  * @pre 
	  * @post 
	  */ 
	void ClearColour(float r, float g, float b, float alpha);

	/** 
	  * @brief Sets the current colour
	  * @warning None
	  * 
	  * Sets the current colour to be used when rendering based on the
	  * r,g,b values passed in
	  * 
	  * @param r: unsigned ch type variable in ViewOpenGL class for red value
	  * @param g: unsigned ch type variable in ViewOpenGL class for green value
	  * @param b: unsigned ch type variable in ViewOpenGL class for blue value
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetColour(unsigned char r, unsigned char g, unsigned char b);

	/** 
	  * @brief Set wireframe view
	  * @warning None
	  * 
	  * Sets the view to wireframe for rendering
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetWireframeView();

	/** 
	  * @brief Set Solid view
	  * @warning None
	  * 
	  * Sets the view to solid for rendering
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetSolidView();

	/** 
	  * @brief Update camera view
	  * @warning None
	  * 
	  * Uses the passed in values to set the camera position and
	  * whatthe camera is looking at
	  * 
	  * @param position: Vector3D type variable in ViewOpenGL class for camera position
	  * @param lookAt: Vector3D type variable in ViewOpenGL class for what the camera is looking at
	  * 
	  * @pre 
	  * @post 
	  */ 
	void UpdateCamera(Vector3D position, Vector3D lookAt);

	/** 
	  * @brief Renders textured triangle strip
	  * @warning None
	  * 
	  * Renders a textured triangle strip with detail map.
	  * Y axis scale, texture & detail map repetition can also be applied
	  * when renderering triangle strip
	  * 
	  * @param verts: unsigned char type pointer variable in ViewOpenGL class for vertices to be rendered in strip
	  * @param size: int type variable in ViewOpenGL class for size of triangle strip
	  * @param textureID: unsigned int type variable in ViewOpenGL class for texture id
	  * @param numTerrainTexRepeat: int type variable in ViewOpenGL class for number of times texture to be repeated
	  * @param detailMapID: unsigned int type variable in ViewOpenGL class for detail map id
	  * @param numDetailMapRepeat: int type variable in ViewOpenGL class number of times detail map to be repeated
	  * @param scale: Vector3D type variable in ViewOpenGL class for x, y znd z scaling
	  * 
	  * @pre 
	  * @post 
	  */ 
	void RenderTriangleStrips(unsigned char* verts, int size, unsigned int textureID, 
		int numTerrainTexRepeat, unsigned int detailMapID, int numDetailMapRepeat, 
		Vector3D scale, RGB<float> lightColour, unsigned char* lightMap);

	/** 
	  * @brief Render 2D image
	  * @warning None
	  * 
	  * Renders 2D image to window in ortho mode.
	  * Image position is set via the float left, right, top, bottom values
	  * 
	  * @param image: unsigned int type variable in ViewOpenGL class for texture id
	  * @param left: float type variable in ViewOpenGL class for image left side
	  * @param right: float type variable in ViewOpenGL class for image right side
	  * @param top: float type variable in ViewOpenGL class for image top side
	  * @param bottom: float type variable in ViewOpenGL class bottom side
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Render2D(unsigned int image, float left, float right,
		float top, float bottom);
	
	void DrawTree(double baseRadius, double topRadius, 
					double height, int slices, int stacks);

	void DrawSphere(double radius, int slices, int stacks);
	
	void DrawCylinder(double baseRadius, double topRadius, 
						double height, int slices, int stacks);

	void Rotate(float angle, float x, float y, float z);
	void Translate(float x, float y, float z);
	void Scale(float x, float y, float z);
	void PushMatrix();
	void PopMatrix();
	void LoadIdentity();
	void SwapBuffers();

	unsigned int BindTexture(Texture* rawImage);

	unsigned int CreateNewTexture(Texture* rawImage);

	unsigned int aCreateNewTexture(unsigned char* tex,int width,int height);

private:

	/** 
	  * @brief RenderTriangleStrip Helper function
	  * @warning None
	  * 
	  * Gets the height colour for a terrain when rendering triangle strips 
	  * 
	  * @param verts: unsigned char type pointer variable in ViewOpenGL class for points to be rendered
	  * @param size: int type variable in ViewOpenGL class for size of the triangle strip
	  * @param xPos: int type variable in ViewOpenGL class for x position on the strip
	  * @param zPos: int type variable in ViewOpenGL class for z position on the strip
	  * @return unsigned char value for y position at the x and z coordinates
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned char GetHeightColour(unsigned char* verts, int size, int xPos, int zPos);

	/** 
	  * @brief RenderTriangleStrip Helper function
	  * @warning None
	  * 
	  * Gets the scaled height colour for a terrain when rendering triangle strips
	  * 
	  * @param verts: unsigned char type pointer variable in ViewOpenGL class for points to be rendered
	  * @param size: int type variable in ViewOpenGL class for size of the triangle strip
	  * @param scaleY: float type variable in ViewOpenGL class for y scale 
	  * @param xPos: int type variable in ViewOpenGL class for x position on the strip
	  * @param zPos: int type variable in ViewOpenGL class for z position on the strip
	  * @return unsigned char value for scaled y position at the x and z coordinates
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetHeightScaled(unsigned char* verts, int size, float scaleY, int xPos, int zPos);

	/** 
	  * @brief Window width value
	  * @warning None
	  * 
	  * Values for the width of the main window
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_winWidth;

	/** 
	  * @brief Window height value
	  * @warning None
	  * 
	  * Value for the height of the main window
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_winHeight;

	unsigned int m_numTextures;
};

#endif