
/** 
  * @class ScreenText
  * @brief Dislpay text to screen
  * 
  * Class used to handle writing text to the screen
  * Deque of strings are passed in for printing
  * 
  * 
  * 
  * @author Justin Pettit
  * @version 00
  * @date 24.10.14
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

#ifndef SCREENTEXT_H
#define SCREENTEXT_H

#include "GL/glut.h"
#include <deque>

using namespace std;

class ScreenText
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
	ScreenText();

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
	~ScreenText(){}

	/** 
	  * @brief Renders text to screen
	  * @warning None
	  * 
	  * Sets all required OpenGL and glut states and renders
	  * text to screen
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Render();

	/** 
	  * @brief Sets values for screen size
	  * @warning None
	  * 
	  * Passes in values for current screen size so text is rendered appropriately
	  * 
	  * @param width: GLfloat type variable in ScreenText class for screen width
	  * @param height: GLfloat type variable in ScreenText class forscreen height
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetScreenSize(GLfloat width, GLfloat height);

	/** 
	  * @brief Sets text Large centered to be printed
	  * @warning None
	  * 
	  * Sets text Large centered to be printed to be printed
	  * to the screen in large font centre of screen
	  * 
	  * @param strings: std::deque<std::string type variable in ScreenText class text to print
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetLargeCenteredText(std::deque<std::string> &strings);

	/** 
	  * @brief Sets text Large centered on or off
	  * @warning None
	  * 
	  * Sets text display Large centered on or off according to bool state
	  * 
	  * @param state: bool type variable in ScreenText class for on or off
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetLargeCentredOn(bool state);

	/** 
	  * @brief Renders text to screen
	  * @warning None
	  * 
	  * renders the large centred text to screen
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void PrintLargeCentredText();

	/** 
	  * @brief Sets text medium top left to be printed
	  * @warning None
	  * 
	  * Sets text medium top left to be printed to be printed
	  * to the screen in large font centre of screen
	  * 
	  * @param strings: std::deque<std::string type variable in ScreenText class text to print
	  * 
	  * @pre 
	  * @post 
	  */
	void SetMediumTopLeftText(std::deque<std::string> &strings);
	
	/** 
	  * @brief Sets text medium top left on or off
	  * @warning None
	  * 
	  * Sets text display medium top left on or off according to bool state
	  * 
	  * @param state: bool type variable in ScreenText class for on or off
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetMediumTopLeftOn(bool state);

	/** 
	  * @brief Renders text to screen
	  * @warning None
	  * 
	  * renders the medium top left text to screen
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void PrintMediumTopLeftText();

private:

	/** 
	  * @brief prints a string of chars to screen
	  * @warning None
	  * 
	  * function to print a set of characters to the screen
	  * using user defined font
	  * 
	  * @param font: void type variable in ScreenText class for font
	  * @param str: const char type variable in ScreenText class to be printed
	  * 
	  * @pre 
	  * @post 
	  */ 
	void PrintCharsToScreen(void *font, const char *str);
 
	/** 
	  * @brief member for window width
	  * @warning None
	  * 
	  * stores window width value to ensure text is printed to screen correclty
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	GLfloat m_winWidth;

	/** 
	  * @brief member for window height
	  * @warning None
	  * 
	  * stores window height value to ensure text is printed to screen correclty
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	GLfloat m_winHeight;

	/** 
	  * @brief Member Medium Top Left printing
	  * @warning None
	  * 
	  * Used to dictate if Member Medium Top Left text is printed
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool m_printMediumTopLeft;

	/** 
	  * @brief Member large centred printing
	  * @warning None
	  * 
	  * Used to dictate if large centred text is printed
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	bool m_printLargeCentred;

	/** 
	  * @brief Stores large centred text
	  * @warning None
	  * 
	  * stores large centred text to be printed
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	std::deque<std::string> m_largeCentredText;

	/** 
	  * @brief Stores medium top left text
	  * @warning None
	  * 
	  * stores medium top left text to be printed
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 	
	std::deque<std::string> m_mediumTopLeftText;

	/**
	  * @brief copy constructor declaration.
	  * @warning None
	  * 
	  * Copy constructor declaration. Declared private so can't be called
	  * 
	  * @param : const ScreenText type variable in ScreenText class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	ScreenText(const ScreenText&);

	/** 
	  * @brief overloaded = operator
	  * @warning None
	  * 
	  * Overloaded = operator. Declared private so can't be called
	  * 
	  * @param : const ScreenText type variable in ScreenText class 
	  * @return ScreenText & value 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	ScreenText& operator=(const ScreenText&);
};
#endif