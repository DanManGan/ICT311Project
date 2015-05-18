
/** 
  * @class Vector3D
  * @brief 3D vector class
  * 
  * 3D vector class with overloaded operators and other
  * required vector operation methods
  * 
  * 
  * 
  * @author Justin Pettit
  * @version 01
  * @date 22.08.14
  * @status complete
  * 
  * @author Justin Pettit
  * @version 02
  * @date 18.04.15
  * @status revised - complete
  * 
  * @todo 
  * 
  * @bugs 
  */ 

#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
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
	Vector3D();

	/** 
	  * @brief Constructor with x,y,z initialisation
	  * @warning None
	  * 
	  * Constructor with vector initialisation via x, y and z values
	  * 
	  * @param x: float type variable in Vector3D class for x member
	  * @param y: float type variable in Vector3D class for y member
	  * @param z: float type variable in Vector3D class for z member
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vector3D(float x, float y, float z);

	/** 
	  * @brief Constructor with array initialisation
	  * @warning None
	  * 
	  * Constructor with vector initialisation via a 3-float array of values
	  * 
	  * @param values: float type array pointer variable in Vector3D class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vector3D(float* values);

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
	~Vector3D();

	/** 
	  * @brief Set x,y,z values
	  * @warning None
	  * 
	  * Set the values of the vector's members
	  * 
	  * @param x: float type variable in Vector3D class for x member
	  * @param y: float type variable in Vector3D class for y member
	  * @param z: float type variable in Vector3D class for z member
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Set(float x, float y, float z);

	/** 
	  * @brief Set x,y,z via array
	  * @warning None
	  * 
	  * Set the values of the vector's members via a 3-float array of values
	  * 
	  * @param values: float type array pointer variable in Vector3D class for x,y,z
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Set(float* values);

	/** 
	  * @brief overloaded '-' operator
	  * @warning None
	  * 
	  * overloaded '-' operator, vector - scalar
	  * 
	  * @param scalar: const float type variable in Vector3D class for scalar subtraction
	  * @return const Vector3D value for result of subtraction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vector3D operator -  (const float scalar) const;

	/** 
	  * @brief overloaded '-' operator
	  * @warning None
	  * 
	  * overloaded '-' operator, vector - vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for subtraction
	  * @return const Vector3D value for result of subtraction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vector3D operator -  (const Vector3D& vec)  const;

	/** 
	  * @brief overloaded '-' operator for vector negation
	  * @warning None
	  * 
	  * overloaded '-' operator for vector negation
	  * 
	  * @return const Vector3D value for negated vector
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vector3D operator -  ();

	/** 
	  * @brief overloaded '+' operator
	  * @warning None
	  * 
	  * overloaded '+' operator, vector + scalar
	  * 
	  * @param scalar: const float type variable in Vector3D class for scalar addition
	  * @return const Vector3D value for result of scalar addition
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vector3D operator +  (const float scalar ) const;

	/** 
	  * @brief overloaded '+' operator
	  * @warning None
	  * 
	  * overloaded '+' operator, vector + vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for vector addition
	  * @return const Vector3D value for result of vector addition
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vector3D operator +  (const Vector3D& vec)  const;

	/** 
	  * @brief overloaded '=' operator
	  * @warning None
	  * 
	  * overloaded '=' operator, vector= new vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for member assignment
	  * @return const void value from member assignment
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator =  (const Vector3D& vec);

	/** 
	  * @brief overloaded '+=' operator
	  * @warning None
	  * 
	  * overloaded '+=' operator, vector+= scalar
	  * 
	  * @param scalar: const float type variable in Vector3D class for scalar addition 
	  * @return const void value for result of scalar addition
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator += (const float scalar);

	/** 
	  * @brief overloaded '+=' operator
	  * @warning None
	  * 
	  * overloaded '+=' operator, vector+= vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for vector addition
	  * @return const void value for result of vector addition
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator += (const Vector3D& vec);

	/** 
	  * @brief overloaded '-=' operator
	  * @warning None
	  * 
	  * overloaded '-=' operator, vector-= scalar
	  * 
	  * @param scalar: const float type variable in Vector3D class for scalar subtraction
	  * @return const void value for result of scalar subtraction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator -= (const float scalar);

	/** 
	  * @brief overloaded '-=' operator
	  * @warning None
	  * 
	  * overloaded '-=' operator, vector-= vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for vector subtraction
	  * @return const void value for result of vector subtraction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator -= (const Vector3D& vec);

	/** 
	  * @brief overloaded '*' operator
	  * @warning None
	  * 
	  * overloaded '*' operator for evaluation, vector * scalar
	  * 
	  * @param scalar: const float type variable in Vector3D class for scalar multiplication
	  * @return const Vector3D value for result of multiplication
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vector3D operator *  (const float scalar) const;

	/** 
	  * @brief overloaded '*' operator
	  * @warning None
	  * 
	  * overloaded '*' operator, vector * vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for vector multiplication
	  * @return const Vector3D value for result of vector multiplication
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vector3D operator *  (const Vector3D& vec)  const;

	/** 
	  * @brief overloaded '/' operator
	  * @warning None
	  * 
	  * overloaded '/' operator, vector/scalar
	  * 
	  * @param scalar: const float type variable in Vector3D class for scalar division
	  * @return const Vector3D value for result of scalar division
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vector3D operator /  (const float scalar) const;

	/** 
	  * @brief overloaded '*=' operator
	  * @warning None
	  * 
	  * overloaded '*=' operator, vector*=scalar
	  * 
	  * @param scalar: const float type variable in Vector3D class for scalar multiplication
	  * @return const void value for result of scalar multiplication
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator *= (const float scalar);

	/** 
	  * @brief overloaded '*=' operator
	  * @warning None
	  * 
	  * overloaded '*=' operator, vector/vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for vector multiplication
	  * @return const void value for result of vector multiplication
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator *= (const Vector3D& vec);

	/** 
	  * @brief overloaded '/=' operator
	  * @warning None
	  * 
	  * overloaded '/=' operator, vector/= scalar
	  * 
	  * @param scalar: const float type variable in Vector3D class for scalar division
	  * @return const void value for result of scalar division
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator /= (const float scalar);

	//overloaded '/=' operator, vector/vector
	/** 
	  * @brief overloaded '/=' operator
	  * @warning None
	  * 
	  * overloaded '/=' operator, vector/vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for vector division
	  * @return const void value for result of vector division
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator /= (const Vector3D& vec);

	//overloaded '==' operator for evaluation, vector == vector
	/** 
	  * @brief overloaded '==' operator
	  * @warning None
	  * 
	  * overloaded '==' operator for evaluation, vector == vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for comparison
	  * @return const bool value true to indicate if vectors are equal
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const bool operator == (const Vector3D& vec)  const;

	//overloaded '!=' operator for evaluation, vector != vector
	/** 
	  * @brief overloaded '!=' operator
	  * @warning None
	  * 
	  * overloaded '!=' operator for evaluation, vector != vector
	  * 
	  * @param vec: const Vector3D type variable in Vector3D class for comparison
	  * @return const bool value true to indicate if vectors not equal
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const bool operator != (const Vector3D& vec)  const;

	/** 
	  * @brief Normalise the vector
	  * @warning None
	  * 
	  * Normslises the vector by dividing the length by 1 then
	  * multiplying each member by the result
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void Normalise();

	/** 
	  * @brief Calc Vector Length
	  * @warning None
	  * 
	  * Calculate the vector's length/magnitude
	  * 
	  * @return float value for length of vector
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float Length();

	/** 
	  * @brief Calc dot product
	  * @warning None
	  * 
	  * Calculate the dot product of two vectors
	  * 
	  * @param vec: Vector3D type variable in Vector3D class for dot product calculation
	  * @return float value for dot product value
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float DotProduct(Vector3D& vec);

	/** 
	  * @brief Calc cross product
	  * @warning None
	  * 
	  * Calculate the cross product of two vectors
	  * 
	  * @param vec: Vector3D type variable in Vector3D class for cross product calculation
	  * @return Vector3D value for the cross product
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vector3D CrossProduct(Vector3D& vec);

	/** 
	  * @brief x member
	  * @warning None
	  * 
	  * X member in the vector
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float x;

	/** 
	  * @brief y member
	  * @warning None
	  * 
	  * Y member in the vector
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float y;

	/** 
	  * @brief z member
	  * @warning None
	  * 
	  * Z member in the vector
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float z;

private:

};

#endif