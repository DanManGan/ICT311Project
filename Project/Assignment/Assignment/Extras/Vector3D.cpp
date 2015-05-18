#include "Vector3D.h"

#include <math.h>


//--------------------------------------------------------------------------------------

Vector3D::Vector3D()
{
	Set(0.0f, 0.0f, 0.0f);
}

//--------------------------------------------------------------------------------------

Vector3D::Vector3D(float ax, float ay, float az)
{
		x = ax;
		y = ay;
		z = az;
}

//--------------------------------------------------------------------------------------

Vector3D::Vector3D(float* values)
{
	Set(values);
}

//--------------------------------------------------------------------------------------

Vector3D::~Vector3D()
{
}

//--------------------------------------------------------------------------------------

void Vector3D::Set(float ax, float ay, float az)
{
	x= ax;
	y= ay;
	z= az;
}

//--------------------------------------------------------------------------------------

void Vector3D::Set(float* values)
{
	x= values[0];
	y= values[1];
	z= values[2];
}

//--------------------------------------------------------------------------------------

const Vector3D Vector3D::operator -  (const float scalar) const
{
	//overloaded '-' operator, vector - scalar
	return Vector3D(x - scalar,	y - scalar,	z - scalar);
}

//--------------------------------------------------------------------------------------

const Vector3D Vector3D::operator -  (const Vector3D& vec)  const
{
	//overloaded '-' operator, vector - vector
	return Vector3D(x - vec.x, y - vec.y, z - vec.z);
}

//--------------------------------------------------------------------------------------

const Vector3D Vector3D::operator -  (void)
{
	//overloaded '-' operator for vector negation, -vector
	x= -x;
	y= -y;
	z= -z;

	return *this;
}

//--------------------------------------------------------------------------------------

const Vector3D Vector3D::operator +  (const float scalar) const
{
	//overloaded '+' operator, vector + scalar
	return Vector3D(x + scalar, y + scalar, z + scalar);

}

//--------------------------------------------------------------------------------------

const Vector3D Vector3D::operator +  (const Vector3D& vec)  const
{
	//overloaded '+' operator, vector + vector
	return Vector3D(x + vec.x, y + vec.y, z + vec.z);
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator =  (const Vector3D& vec)
{
	//overloaded '=' operator, vector= scalar
	x= vec.x;
	y= vec.y;
	z= vec.z;
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator += (const float scalar)
{
	//overloaded '+=' operator, vector+= scalar
	x+= scalar;
	y+= scalar;
	z+= scalar;
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator += (const Vector3D& vec)
{
	//overloaded '+=' operator, vector+= vector
	x+= vec.x;
	y+= vec.y;
	z+= vec.z;
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator -= (const float scalar)
{
	//overloaded '-=' operator, vector-= scalar
	x-= scalar;
	y-= scalar;
	z-= scalar;
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator -= (const Vector3D& vec)
{
	//overloaded '-=' operator, vector-= vector
	x-= vec.x;
	y-= vec.y;
	z-= vec.z;
}

//--------------------------------------------------------------------------------------


const Vector3D Vector3D::operator *  (const float scalar) const
{
	//overloaded '*' operator for evaluation, vector * scalar
	return Vector3D(x*scalar, y*scalar, z*scalar);
}

//--------------------------------------------------------------------------------------

const Vector3D Vector3D::operator *  (const Vector3D& vec)  const
{
	//overloaded '*' operator, vector * vector
	return Vector3D(x*vec.x, y*vec.y, z*vec.z);
}

//--------------------------------------------------------------------------------------

const Vector3D Vector3D::operator /  (const float scalar) const
{
	//overloaded '/' operator, vector/scalar
	float fTemp;

	fTemp= 1/scalar;
		
	return Vector3D(x*fTemp, y*fTemp, z*fTemp);
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator *= (const float scalar)
{
	//overloaded '*=' operator, vector*=scalar
	x*= scalar;
	y*= scalar;
	z*= scalar;
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator *= (const Vector3D& vec)
{
	//overloaded '*=' operator, vector/vector
	x*= vec.x;
	y*= vec.y;
	z*= vec.z;
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator /= (const float scalar)
{
	//overloaded '/=' operator, vector/= scalar
	x/= scalar;
	y/= scalar;
	z/= scalar;
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator /= (const Vector3D& vec)
{
	//overloaded '/=' operator, vector/vector
	x/= vec.x;
	y/= vec.y;
	z/= vec.z;
}

//--------------------------------------------------------------------------------------

const bool Vector3D::operator == (const Vector3D& vec)  const
{
	//overloaded '==' operator for evaluation, vector == vector
	return ((x==vec.x) && (y==vec.y) && (z==vec.z));
}

//--------------------------------------------------------------------------------------

const bool Vector3D::operator != (const Vector3D& vec)  const
{
	//overloaded '!=' operator for evaluation, vector != vector
	return !(*this==vec);	
}

//--------------------------------------------------------------------------------------

void Vector3D::Normalise()
{
	float fTemp= 1/Length();

	x*= fTemp;
	y*= fTemp;
	z*= fTemp;
}

//--------------------------------------------------------------------------------------

float Vector3D::Length()
{
	return ((float)sqrt(x*x + y*y + z*z));
}

//--------------------------------------------------------------------------------------

float Vector3D::DotProduct(Vector3D& vec)
{
	return (x*vec.x + y*vec.y + z*vec.z);
}

//--------------------------------------------------------------------------------------

Vector3D Vector3D::CrossProduct(Vector3D& vec)
{
	return Vector3D(y*vec.z - z*vec.y, z*vec.x - x*vec.z, x*vec.y - y*vec.x);
}