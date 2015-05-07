
/** 
  * @class InputGLFW
  * @brief Provide Input functionality via GLFW library
  * 
  * Input class to handle user input with the GLFW library
  * Provides methods for mouse input, mouse buttons,
  * and keyboard characters and press/release states
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

#ifndef INPUTGLFW_H
#define INPUTGLFW_H
 
class InputGLFW
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
	InputGLFW();

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
	~InputGLFW();

	/** 
	  * @brief Initialise OpenGL
	  * @warning None
	  * 
	  * Initialises all the variables and states required for
	  * GLFW library. Sets callback functions for keyboard input
	  * mouse position and mouse button
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Init();

	/** 
	  * @brief Handles keyboard input
	  * @warning None
	  * 
	  * Method to handle keyboard input and set values for use
	  * by other classes
	  * 
	  * @param key: int type variable in InputGLFW class for key pressed
	  * @param action: int type variable in InputGLFW class for key pressed state
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Keyboard(int key, int action);

	/** 
	  * @brief Keyboard callback function
	  * @warning None
	  * 
	  * Static function for use in callback function which allows instance method to be used
	  * 
	  * @param key1: int type variable in InputGLFW class for key pressed
	  * @param action1: int type variable in InputGLFW class for key pressed state
	  * 
	  * @pre 
	  * @post 
	  */ 
	static void KeyboardCallback(int key1, int action1);

	/** 
	  * @brief Handle mouse postion input
	  * @warning None
	  * 
	  * Method to handle mouse input and set values for use
	  * by other classes
	  * 
	  * @param x: int type variable in InputGLFW class for mouse x position
	  * @param y: int type variable in InputGLFW class for mouse y position
	  * 
	  * @pre 
	  * @post 
	  */ 
	void MousePos(int x, int y);

	/** 
	  * @brief Mouse callback function
	  * @warning None
	  * 
	  * Static function for use in callback function which allows instance method to be used
	  * 
	  * @param x: int type variable in InputGLFW class for mouse x position
	  * @param y: int type variable in InputGLFW class for mouse y position
	  * 
	  * @pre 
	  * @post 
	  */ 
	static void MousePosCallback(int x, int y);

	/** 
	  * @brief Mouse Button input
	  * @warning None
	  * 
	  * Method to handle mouse button input and set values for use
	  * by other classes
	  * 
	  * @param button: int type variable in InputGLFW class for button pressed
	  * @param action: int type variable in InputGLFW class for button pressed state 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void MouseButton(int button, int action);

	/** 
	  * @brief Mouse button callback function
	  * @warning None
	  * 
	  * Static function for use in callback function which allows instance method to be used
	  * 
	  * @param button: int type variable in InputGLFW class for button pressed
	  * @param action: int type variable in InputGLFW class for button pressed state 
	  * 
	  * @pre 
	  * @post 
	  */ 
	static void MouseButtonCallback(int button, int action);

	/** 
	  * @brief Mouse X position on screen
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int mouseX;

	/** 
	  * @brief Mouse Y position on screen
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	int mouseY;

	/** 
	  * @brief Mouse left button pressed state
	  * @warning None
	  * 
	  *
	  * @pre 
	  * @post 
	  */ 
	bool mouseLeft;

	/** 
	  * @brief Mouse right button pressed state
	  * @warning None
	  * 
	  *
	  * @pre 
	  * @post 
	  */ 
	bool mouseRight;

	/** 
	  * @brief Keyboard button pressed
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int key;

	/** 
	  * @brief Keyboard button pressed state
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool keyPress;

	/** 
	  * @brief Keyboard button released state
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool keyRelease;

private:

};

#endif