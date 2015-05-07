
/** 
  * @class Vec3
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

#ifndef VEC3_H
#define VEC3_H

class Vec3
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
	Vec3();

	/** 
	  * @brief Constructor with x,y,z initialisation
	  * @warning None
	  * 
	  * Constructor with vector initialisation via x, y and z values
	  * 
	  * @param x: float type variable in Vec3 class for x member
	  * @param y: float type variable in Vec3 class for y member
	  * @param z: float type variable in Vec3 class for z member
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vec3(float x, float y, float z);

	/** 
	  * @brief Constructor with array initialisation
	  * @warning None
	  * 
	  * Constructor with vector initialisation via a 3-float array of values
	  * 
	  * @param values: float type array pointer variable in Vec3 class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vec3(float* values);

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
	~Vec3();

	/** 
	  * @brief Set x,y,z values
	  * @warning None
	  * 
	  * Set the values of the vector's members
	  * 
	  * @param x: float type variable in Vec3 class for x member
	  * @param y: float type variable in Vec3 class for y member
	  * @param z: float type variable in Vec3 class for z member
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
	  * @param values: float type array pointer variable in Vec3 class for x,y,z
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
	  * @param scalar: const float type variable in Vec3 class for scalar subtraction
	  * @return const Vec3 value for result of subtraction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vec3 operator -  (const float scalar) const;

	/** 
	  * @brief overloaded '-' operator
	  * @warning None
	  * 
	  * overloaded '-' operator, vector - vector
	  * 
	  * @param vec: const Vec3 type variable in Vec3 class for subtraction
	  * @return const Vec3 value for result of subtraction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vec3 operator -  (const Vec3& vec)  const;

	/** 
	  * @brief overloaded '-' operator for vector negation
	  * @warning None
	  * 
	  * overloaded '-' operator for vector negation
	  * 
	  * @return const Vec3 value for negated vector
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vec3 operator -  ();

	/** 
	  * @brief overloaded '+' operator
	  * @warning None
	  * 
	  * overloaded '+' operator, vector + scalar
	  * 
	  * @param scalar: const float type variable in Vec3 class for scalar addition
	  * @return const Vec3 value for result of scalar addition
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vec3 operator +  (const float scalar ) const;

	/** 
	  * @brief overloaded '+' operator
	  * @warning None
	  * 
	  * overloaded '+' operator, vector + vector
	  * 
	  * @param vec: const Vec3 type variable in Vec3 class for vector addition
	  * @return const Vec3 value for result of vector addition
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vec3 operator +  (const Vec3& vec)  const;

	/** 
	  * @brief overloaded '=' operator
	  * @warning None
	  * 
	  * overloaded '=' operator, vector= new vector
	  * 
	  * @param vec: const Vec3 type variable in Vec3 class for member assignment
	  * @return const void value from member assignment
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator =  (const Vec3& vec);

	/** 
	  * @brief overloaded '+=' operator
	  * @warning None
	  * 
	  * overloaded '+=' operator, vector+= scalar
	  * 
	  * @param scalar: const float type variable in Vec3 class for scalar addition 
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
	  * @param vec: const Vec3 type variable in Vec3 class for vector addition
	  * @return const void value for result of vector addition
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator += (const Vec3& vec);

	/** 
	  * @brief overloaded '-=' operator
	  * @warning None
	  * 
	  * overloaded '-=' operator, vector-= scalar
	  * 
	  * @param scalar: const float type variable in Vec3 class for scalar subtraction
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
	  * @param vec: const Vec3 type variable in Vec3 class for vector subtraction
	  * @return const void value for result of vector subtraction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator -= (const Vec3& vec);

	/** 
	  * @brief overloaded '*' operator
	  * @warning None
	  * 
	  * overloaded '*' operator for evaluation, vector * scalar
	  * 
	  * @param scalar: const float type variable in Vec3 class for scalar multiplication
	  * @return const Vec3 value for result of multiplication
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vec3 operator *  (const float scalar) const;

	/** 
	  * @brief overloaded '*' operator
	  * @warning None
	  * 
	  * overloaded '*' operator, vector * vector
	  * 
	  * @param vec: const Vec3 type variable in Vec3 class for vector multiplication
	  * @return const Vec3 value for result of vector multiplication
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vec3 operator *  (const Vec3& vec)  const;

	/** 
	  * @brief overloaded '/' operator
	  * @warning None
	  * 
	  * overloaded '/' operator, vector/scalar
	  * 
	  * @param scalar: const float type variable in Vec3 class for scalar division
	  * @return const Vec3 value for result of scalar division
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const Vec3 operator /  (const float scalar) const;

	/** 
	  * @brief overloaded '*=' operator
	  * @warning None
	  * 
	  * overloaded '*=' operator, vector*=scalar
	  * 
	  * @param scalar: const float type variable in Vec3 class for scalar multiplication
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
	  * @param vec: const Vec3 type variable in Vec3 class for vector multiplication
	  * @return const void value for result of vector multiplication
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator *= (const Vec3& vec);

	/** 
	  * @brief overloaded '/=' operator
	  * @warning None
	  * 
	  * overloaded '/=' operator, vector/= scalar
	  * 
	  * @param scalar: const float type variable in Vec3 class for scalar division
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
	  * @param vec: const Vec3 type variable in Vec3 class for vector division
	  * @return const void value for result of vector division
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const void operator /= (const Vec3& vec);

	//overloaded '==' operator for evaluation, vector == vector
	/** 
	  * @brief overloaded '==' operator
	  * @warning None
	  * 
	  * overloaded '==' operator for evaluation, vector == vector
	  * 
	  * @param vec: const Vec3 type variable in Vec3 class for comparison
	  * @return const bool value true to indicate if vectors are equal
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const bool operator == (const Vec3& vec)  const;

	//overloaded '!=' operator for evaluation, vector != vector
	/** 
	  * @brief overloaded '!=' operator
	  * @warning None
	  * 
	  * overloaded '!=' operator for evaluation, vector != vector
	  * 
	  * @param vec: const Vec3 type variable in Vec3 class for comparison
	  * @return const bool value true to indicate if vectors not equal
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	const bool operator != (const Vec3& vec)  const;

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
	  * @param vec: Vec3 type variable in Vec3 class for dot product calculation
	  * @return float value for dot product value
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float DotProduct(Vec3& vec);

	/** 
	  * @brief Calc cross product
	  * @warning None
	  * 
	  * Calculate the cross product of two vectors
	  * 
	  * @param vec: Vec3 type variable in Vec3 class for cross product calculation
	  * @return Vec3 value for the cross product
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vec3 CrossProduct(Vec3& vec);

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