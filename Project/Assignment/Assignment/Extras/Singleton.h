
/** 
  * @class Singleton
  * @brief Singleton template class
  * 
  * Simple template class for Singleton test
  * 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 19.03.15
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

#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton
{
public:

	/** 
	  * @brief Get only class instance
	  * @warning None
	  * 
	  * Returns the only class instance
	  * 
	  * @return T * value 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	static T *GetInstance();

private:

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
	Singleton();

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
	~Singleton();

	/** 
	  * @brief Copy constructor
	  * @warning None
	  * 
	  * Copy constructor for class
	  * 
	  * @param copyObj: const Singleton type variable in StatTest class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Singleton(const Singleton &copyObj);
	
	/** 
	  * @brief Overloaded = operator
	  * @warning None
	  * 
	  * Detail
	  * 
	  * @param copyObj: const Singleton type variable in StatTest class 
	  * @return Singleton & value 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Singleton &operator =(const Singleton &copyObj);

};

#endif

template <class T>
T *Singleton<T>::GetInstance() {
	static T instance;
	return &instance;
}