#include "Vec3.h"

#include <math.h>


//--------------------------------------------------------------------------------------

Vec3::Vec3()
{
	Set(0.0f, 0.0f, 0.0f);
}

//--------------------------------------------------------------------------------------

Vec3::Vec3(float ax, float ay, float az)
{
		x = ax;
		y = ay;
		z = az;
}

//--------------------------------------------------------------------------------------

Vec3::Vec3(float* values)
{
	Set(values);
}

//--------------------------------------------------------------------------------------

Vec3::~Vec3()
{
}

//--------------------------------------------------------------------------------------

void Vec3::Set(float ax, float ay, float az)
{
	x= ax;
	y= ay;
	z= az;
}

//--------------------------------------------------------------------------------------

void Vec3::Set(float* values)
{
	x= values[0];
	y= values[1];
	z= values[2];
}

//--------------------------------------------------------------------------------------

const Vec3 Vec3::operator -  (const float scalar) const
{
	//overloaded '-' operator, vector - scalar
	return Vec3(x - scalar,	y - scalar,	z - scalar);
}

//--------------------------------------------------------------------------------------

const Vec3 Vec3::operator -  (const Vec3& vec)  const
{
	//overloaded '-' operator, vector - vector
	return Vec3(x - vec.x, y - vec.y, z - vec.z);
}

//--------------------------------------------------------------------------------------

const Vec3 Vec3::operator -  (void)
{
	//overloaded '-' operator for vector negation, -vector
	x= -x;
	y= -y;
	z= -z;

	return *this;
}

//--------------------------------------------------------------------------------------

const Vec3 Vec3::operator +  (const float scalar) const
{
	//overloaded '+' operator, vector + scalar
	return Vec3(x + scalar, y + scalar, z + scalar);

}

//--------------------------------------------------------------------------------------

const Vec3 Vec3::operator +  (const Vec3& vec)  const
{
	//overloaded '+' operator, vector + vector
	return Vec3(x + vec.x, y + vec.y, z + vec.z);
}

//--------------------------------------------------------------------------------------

const void Vec3::operator =  (const Vec3& vec)
{
	//overloaded '=' operator, vector= scalar
	x= vec.x;
	y= vec.y;
	z= vec.z;
}

//--------------------------------------------------------------------------------------

const void Vec3::operator += (const float scalar)
{
	//overloaded '+=' operator, vector+= scalar
	x+= scalar;
	y+= scalar;
	z+= scalar;
}

//--------------------------------------------------------------------------------------

const void Vec3::operator += (const Vec3& vec)
{
	//overloaded '+=' operator, vector+= vector
	x+= vec.x;
	y+= vec.y;
	z+= vec.z;
}

//--------------------------------------------------------------------------------------

const void Vec3::operator -= (const float scalar)
{
	//overloaded '-=' operator, vector-= scalar
	x-= scalar;
	y-= scalar;
	z-= scalar;
}

//--------------------------------------------------------------------------------------

const void Vec3::operator -= (const Vec3& vec)
{
	//overloaded '-=' operator, vector-= vector
	x-= vec.x;
	y-= vec.y;
	z-= vec.z;
}

//--------------------------------------------------------------------------------------


const Vec3 Vec3::operator *  (const float scalar) const
{
	//overloaded '*' operator for evaluation, vector * scalar
	return Vec3(x*scalar, y*scalar, z*scalar);
}

//--------------------------------------------------------------------------------------

const Vec3 Vec3::operator *  (const Vec3& vec)  const
{
	//overloaded '*' operator, vector * vector
	return Vec3(x*vec.x, y*vec.y, z*vec.z);
}

//--------------------------------------------------------------------------------------

const Vec3 Vec3::operator /  (const float scalar) const
{
	//overloaded '/' operator, vector/scalar
	float fTemp;

	fTemp= 1/scalar;
		
	return Vec3(x*fTemp, y*fTemp, z*fTemp);
}

//--------------------------------------------------------------------------------------

const void Vec3::operator *= (const float scalar)
{
	//overloaded '*=' operator, vector*=scalar
	x*= scalar;
	y*= scalar;
	z*= scalar;
}

//--------------------------------------------------------------------------------------

const void Vec3::operator *= (const Vec3& vec)
{
	//overloaded '*=' operator, vector/vector
	x*= vec.x;
	y*= vec.y;
	z*= vec.z;
}

//--------------------------------------------------------------------------------------

const void Vec3::operator /= (const float scalar)
{
	//overloaded '/=' operator, vector/= scalar
	x/= scalar;
	y/= scalar;
	z/= scalar;
}

//--------------------------------------------------------------------------------------

const void Vec3::operator /= (const Vec3& vec)
{
	//overloaded '/=' operator, vector/vector
	x/= vec.x;
	y/= vec.y;
	z/= vec.z;
}

//--------------------------------------------------------------------------------------

const bool Vec3::operator == (const Vec3& vec)  const
{
	//overloaded '==' operator for evaluation, vector == vector
	return ((x==vec.x) && (y==vec.y) && (z==vec.z));
}

//--------------------------------------------------------------------------------------

const bool Vec3::operator != (const Vec3& vec)  const
{
	//overloaded '!=' operator for evaluation, vector != vector
	return !(*this==vec);	
}

//--------------------------------------------------------------------------------------

void Vec3::Normalise()
{
	float fTemp= 1/Length();

	x*= fTemp;
	y*= fTemp;
	z*= fTemp;
}

//--------------------------------------------------------------------------------------

float Vec3::Length()
{
	return ((float)sqrt(x*x + y*y + z*z));
}

//--------------------------------------------------------------------------------------

float Vec3::DotProduct(Vec3& vec)
{
	return (x*vec.x + y*vec.y + z*vec.z);
}

//--------------------------------------------------------------------------------------

Vec3 Vec3::CrossProduct(Vec3& vec)
{
	return Vec3(y*vec.z - z*vec.y, z*vec.x - x*vec.z, x*vec.y - y*vec.x);
}