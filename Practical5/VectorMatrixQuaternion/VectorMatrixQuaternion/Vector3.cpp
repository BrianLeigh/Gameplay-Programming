//Description:		A program containing 3 classes that allows for the manipulation of vector3, matrix and quaternion variables.
//Name:				Brian Leigh
//Student ID:		C00159600
//Date:				23/11/2016

#include "Vector3.h"

//Default constructor
Vector3::Vector3() :
	m_x(0),
	m_y(0),
	m_z(0)
{

}

//Overloaded Constructor, takes in 3 floats as parameters, one for each axis on a vector(x,y,z)
Vector3::Vector3(float x, float y, float z) :
	m_x(x),
	m_y(y),
	m_z(z)
{

}
//Used to find the length of a vector
float Vector3::length()
{
	return std::sqrtf((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}
//Calculates the squared length of a vector
float Vector3::lengthSquared()
{
	return(m_x * m_x) + (m_y * m_y) + (m_z * m_z);
}
//Makes the length of a vector 1
void Vector3::normalise()
{
	if (length() > 0.0)
	{
		float magnitude = length();
		m_x /= magnitude;
		m_y /= magnitude;
		m_z /= magnitude;
	}
}
//Multiplies all components of a Vector3 by -1
Vector3 Vector3::operator-() const
{
	return Vector3(-m_x, -m_y, -m_z);
}
//Returns the x component of a vector3
float Vector3::getX() const
{
	return m_x;
}
//Returns the y component of a vector3
float Vector3::getY() const
{
	return m_y;
}
//Returns the z component of a vector3
float Vector3::getZ() const
{
	return m_z;
}
//Returns a string format of a Vector3
std::string Vector3::toString()
{
	return std::string( "( " + std::to_string(m_x) + " , " + std::to_string(m_y) + " , " + std::to_string(m_z) + ")");
}

//Allows for 2 vector3s to be added together, returns a new vector3
Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.m_x + v2.m_x,
				   v1.m_y + v2.m_y,
				   v1.m_z + v2.m_z
				  );
}
//Allows one vector3 to be taken away from another vector3, returns a new vector3
Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.m_x - v2.m_x,
		v1.m_y - v2.m_y,
		v1.m_z - v2.m_z
	);
}
//Allows you to find the vector product of two vector3s, returns a vector3
Vector3 operator^(const Vector3& v1, const Vector3& v2)
{
	return Vector3((v1.m_y * v2.m_z) - (v1.m_z * v2.m_y),
				   (v1.m_z * v2.m_x) - (v1.m_x * v2.m_z),
				   (v1.m_x * v2.m_y) - (v1.m_y * v2.m_x));
}
//Allows you to multiply 2 vector3s, returns a float
float operator*(const Vector3& v1, const Vector3& v2)
{
	return float(v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z);
}

//Allows you to multiply a vector3 and a float, returns a new vector3
Vector3 operator*(const Vector3& v, const float& f)
{
	return Vector3(	v.m_x * f, v.m_y * f, v.m_z * f);
}
//Allows you to multiply a vector3 and a double, returns a new vector3
Vector3 operator*(const Vector3& v, const double& d)
{
	return Vector3(v.m_x * d, v.m_y * d, v.m_z * d);
}
//Allows you to multiply a vector3 and a int, returns a new vector3
Vector3 operator*(const Vector3& v, const int& i)
{
	return Vector3(v.m_x * i, v.m_y * i, v.m_z * i);
}