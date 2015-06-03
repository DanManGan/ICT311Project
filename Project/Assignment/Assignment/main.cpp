
/** 
  * @class main
  * @brief main program file
  * 
  * Main entry point for the program
  * 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 20.04.15
  * @status complete
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

#include "MainGame.h"
#include <gl/glut.h>

int main(int argc, char **argv)
{
	//glutInit(&argc, argv); // this is needed for screen text

	MainGame game; // create instance

	game.Run(); // run game

	return 0;
}