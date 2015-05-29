
#include "Vector3D.h"

#include "MathExtra.h"

#include <math.h>
#include <iostream>


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

bool Vector3D::IsZero()
{
	return (x == 0 && y == 0 && z == 0);
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
	return Vector3D(this->x - vec.x, this->y - vec.y, this->z - vec.z);
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
	return Vector3D(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator =  (const Vector3D& vec)
{
	//overloaded '=' operator, vector= scalar
	this->x= vec.x;
	this->y= vec.y;
	this->z= vec.z;
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
	this->x+= vec.x;
	this->y+= vec.y;
	this->z+= vec.z;
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
	this->x-= vec.x;
	this->y-= vec.y;
	this->z-= vec.z;
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
	return Vector3D(this->x*vec.x, this->y*vec.y, this->z*vec.z);
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
	this->x*= scalar;
	this->y*= scalar;
	this->z*= scalar;
}

//--------------------------------------------------------------------------------------

const void Vector3D::operator *= (const Vector3D& vec)
{
	//overloaded '*=' operator, vector/vector
	this->x*= vec.x;
	this->y*= vec.y;
	this->z*= vec.z;
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
	this->x/= vec.x;
	this->y/= vec.y;
	this->z/= vec.z;
}

//--------------------------------------------------------------------------------------

const bool Vector3D::operator == (const Vector3D& vec)  const
{
	//overloaded '==' operator for evaluation, vector == vector
	return ((this->x==vec.x) && (this->y==vec.y) && (this->z==vec.z));
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
	//std::cout << "normalise print " << std::endl;
	//Print();
	float fTemp= 1/this->Length();
	//std::cout << "length " << Length() << std::endl;
	this->x*= fTemp;
	this->y*= fTemp;
	this->z*= fTemp;
}

//--------------------------------------------------------------------------------------

float Vector3D::Length()
{
	return ((float)sqrt(x*x + y*y + z*z));
}

//--------------------------------------------------------------------------------------

float Vector3D::DotProduct(Vector3D& vec)
{
	return (this->x*vec.x + this->y*vec.y + this->z*vec.z);
}

//--------------------------------------------------------------------------------------

Vector3D Vector3D::CrossProduct(Vector3D& vec)
{
	return Vector3D(this->y*vec.z - this->z*vec.y, this->z*vec.x - this->x*vec.z, this->x*vec.y - this->y*vec.x);
}

//--------------------------------------------------------------------------------------

void Vector3D::Print()
{
	std::cout << "x: " << this->x << " y: " << this->y << " z: " << this->z << std::endl;
}


// return angle between two vectors in radians
const float Vector3D::AngleInRadians(Vector3D& normalVec) const
{
 Vector3D angle=*this;
 angle.Normalise();
 float dp = angle.DotProduct(normalVec);

	 	  if(dp>1.0)
		  dp=1.0;
	  else if(dp<-1.0)
	      dp=-1.0;
 return acosf(dp);
}

// return angle between two vectors in radians
const float Vector3D::AngleInDegrees(Vector3D& normalVec) const
{
 return(RAD_TO_DEG(AngleInRadians(normalVec))); 
}

//determines theta in degrees from a vector heading
//assumes vector stores a normalised vector
float Vector3D::GetHeadingDegrees()
{
 Vector3D heading=*this;
 heading.Normalise();
 float x=heading.x;
 float y=heading.y;
 float z=heading.z;
 float theta=RAD_TO_DEG((float)atan(z/x));
     if(z<0)
	 {
		 if(x>=0)
			 theta=360+theta;
		 if(x<0)
			 theta=180+theta;
	 }
	 if(x<0 && z>=0)
		 theta=180+theta;
 return theta;
}