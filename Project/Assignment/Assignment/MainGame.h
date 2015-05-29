
/** 
  * @class MainGame
  * @brief Main game class
  * 
  * Controller class for the main game. 
  * Brings all the other classes for the game together to create and run the game
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

#ifndef MAINGAME_H
#define MAINGAME_H

#include "Camera.h"

class MainGame
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
	MainGame();
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
	~MainGame();

	/** 
	  * @brief Game Run Method
	  * @warning None
	  * 
	  * Mehtod starts the game
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Run();


private:

	/** 
	  * @brief Initialise game members and states
	  * @warning None
	  * 
	  * Initialises all game members, set game states and
	  * load objects and textures
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Init();

	/** 
	  * @brief Main game loop
	  * @warning None
	  * 
	  * Managaes the game input and display methods, time counter etc
	  * updtaes game states
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void GameLoop();

	/** 
	  * @brief Process player input
	  * @warning None
	  * 
	  * Processes the player input and updates variables as required
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void ProcessInput();

	void Update();

	/** 
	  * @brief Render everything to window
	  * @warning None
	  * 
	  * Sets up the window for rendering and renders everything to screen
	  * 
	  * @param deltaT: float type variable in MainGame class for time
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Display(float deltaT);

	void Animate(float deltaT);


	/** 
	  * @brief Camera object
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Camera m_camera;

	/** 
	  * @brief Window width
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_winWidth;

	/** 
	  * @brief Window Height
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_winHeight;

	/** 
	  * @brief Old mouse X position on screen
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_oldX;

	/** 
	  * @brief Old mouse Y position on screen
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_oldY;	

	/** 
	  * @brief Input processing oneshot
	  * @warning None
	  * 
	  * Data entry input oneshot to ensure key's are not repeatedly unintentionally
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool m_inputOneShot;

	/** 
	  * @brief Menu state
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool m_showMenu;

	/** 
	  * @brief Wireframe state
	  * @warning None
	  * 
	  * Detail
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool m_wireframe;

	/** 
	  * @brief Menu texture ID
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned int m_menu;
	
	
	/** 
	  * @brief Player height in world
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float m_playerHeight;

	/** 
	  * @brief Mouse movement sensitivity
	  * @warning None
	  *  
	  * 
	  * @pre 
	  * @post 
	  */ 
	float m_mouseSensitivity;

	/** 
	  * @brief Game running state
	  * @warning None
	  *  
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool m_running;
};

#endif