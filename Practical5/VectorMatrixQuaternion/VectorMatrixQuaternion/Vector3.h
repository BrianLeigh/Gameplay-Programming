//Description:		A program containing 3 classes that allows for the manipulation of vector3, matrix and quaternion variables.
//Name:				Brian Leigh
//Student ID:		C00159600
//Date:				23/11/2016
#pragma once

#include <math.h>
#include <string>
class Matrix3;

class Vector3
{
	//These allow multiple calcualtions of vector3 variables with different outputs, to be used in classes other than the Vector3 class.
	friend Vector3 operator+(const Vector3& v1, const Vector3& v2);
	friend Vector3 operator-(const Vector3& v1, const Vector3& v2);
	friend Vector3 operator^(const Vector3& v1, const Vector3& v2);
	friend float operator*(const Vector3& v1, const Vector3& v2);
	friend Vector3 operator*(const Vector3& v, const float& f);	
	friend Vector3 operator*(const Vector3& v, const double& d);
	friend Vector3 operator*(const Vector3& v, const int& i);

public:
	Vector3(); //Default Constructor
	Vector3(float x, float y, float z); //Overloaded constructor
	//Vector3 methods
	float length();
	float lengthSquared();
	void normalise();
	Vector3 operator- () const;
	float getX() const;
	float getY() const;
	float getZ() const;
	std::string toString();
private:
	//Member variables
	float m_x;
	float m_y;
	float m_z;

};
#include "Matrix3.h"
