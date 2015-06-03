
/** 
  * @class Question
  * @brief Store question data
  * 
  * Stores strings for a maths questions in a map and
  * has a member to store the answer.
  * Class is based on the idea that the question will be posed as a 
  * multiple choice question and the answer stored is the relevant multiple 
  * choice number
  * 
  * 
  * 
  * @author Justin Pettit
  * @version 00
  * @date 24.10.14
  * @status Complete
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

#ifndef QUESTION_H
#define QUESTION_H

#include <gl\glut.h>
#include <deque>

class Question
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
	Question();

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
	~Question(){}

	/** 
	  * @brief Sets question strings
	  * @warning None
	  * 
	  * Takes a deque of strings to be used for a maths question
	  * 
	  * @param strings: std::deque<std::string type variable in Question class for question strings
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetQuestion(std::deque<std::string> &strings);

	/** 
	  * @brief Set answer value
	  * @warning None
	  * 
	  * Sets the value for the correct multiple choice answer of the question
	  * 
	  * @param answer: int type variable in Question class for multiple choice answer
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetAnswer(int answer);

	/** 
	  * @brief Return question strings
	  * @warning None
	  * 
	  * Returns a deque of strings with the question stored
	  * 
	  * @return std::deque<std::string> value for question
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	std::deque<std::string> GetQuestion();

	/** 
	  * @brief Gets multiple choice answer
	  * @warning None
	  * 
	  * Returns the corect mutltiple choice answer based on the answer porvided in the question
	  * 
	  * @return int value for multiple choice answer
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int GetAnswer();

	/** 
	  * @brief Clears object
	  * @warning None
	  * 
	  * Clears all details from the object
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Clear();

private:

	/** 
	  * @brief stores question strings
	  * @warning None
	  * 
	  * deque to store the strings used for the question
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	std::deque<std::string> m_question;

	/** 
	  * @brief answer to question
	  * @warning None
	  * 
	  * member to store mutli choice answer value
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_answer;

};
#endif