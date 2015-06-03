
/** 
  * @class QuestionList
  * @brief Class to store, load and access question objects
  * 
  * Class to store question objects. 
  * Loads formatted question from a .txt file into a 
  * map of questions. Provides methods to get map and
  * clear instance
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

#ifndef QUESTIONLIST_H
#define QUESTIONLIST_H

#include "Question.h"
#include <map>
 
class QuestionList
{
public:

	/** 
	  * @brief 
	  * @brief Default constructor
	  * @warning None
	  * 
	  * Default class constructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	QuestionList();

	/** 
	  * @brief Default destructor
	  * @warning None
	  * 
	  * Default class destructorl
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	~QuestionList(){}

	/** 
	  * @brief Load question from txt file
	  * @warning Correct formatting of .txt file required
	  * 
	  * Loads formatted questions from a text file and sets to question object.
	  * Question objects stored in a map with question and answer
	  * 
	  * @param file: std::string type variable in QuestionList class for txt file to load
	  * @return bool value for successful loading
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool LoadQuestions(std::string file);

	/** 
	  * @brief Get question map
	  * @warning None
	  * 
	  * Returns map of loaded questions
	  * 
	  * @return std::map<int,Question> value for loaded questions
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	std::map<int, Question> GetQuestions();

	/** 
	  * @brief Clear object
	  * @warning None
	  * 
	  * Clears all details of instance
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Clear();

	/** 
	  * @brief Convert string to int
	  * @warning None
	  * 
	  * Converts a string to an int value
	  * 
	  * @param str: std::stri type variable in QuestionList class to be converted
	  * @return int value for converted string
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int strInt(std::string str);

	/** 
	  * @brief Convert string to float
	  * @warning None
	  * 
	  * Converts a string to an float value
	  * 
	  * @param str: std::stri type variable in QuestionList class to be converted
	  * @return float value for converted string
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float strFloat(std::string str);

private:

	/** 
	  * @brief Check file exists
	  * @warning None
	  * 
	  * Tests file name to confirm exists before attempting to load
	  * 
	  * @param file: std::stri type variable in QuestionList class for file name
	  * @return bool value indicate file exists
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool FileExists(std::string file);

	/** 
	  * @brief Member to hold questions
	  * @warning None
	  * 
	  * Stores question objects along with a key to identify each question
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	std::map<int, Question> m_questions;

	/**
	  * @brief copy constructor declaration.
	  * @warning None
	  * 
	  * Copy constructor declaration. Declared private so can't be called
	  * 
	  * @param : const QuestionList type variable in QuestionList class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	QuestionList(const QuestionList&);

	/** 
	  * @brief overloaded = operator
	  * @warning None
	  * 
	  * Overloaded = operator. Declared private so can't be called
	  * 
	  * @param : const QuestionList type variable in QuestionList class 
	  * @return QuestionList & value 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	QuestionList& operator=(const QuestionList&);
};
#endif