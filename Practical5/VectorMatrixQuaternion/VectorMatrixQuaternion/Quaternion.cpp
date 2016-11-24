//Description:		A program containing 3 classes that allows for the manipulation of vector3, matrix and quaternion variables.
//Name:				Brian Leigh
//Student ID:		C00159600
//Date:				23/11/2016

#include "Quaternion.h"
//Default Constructor
Quaternion::Quaternion() :
	m_w(0),
	m_x(0),
	m_y(0),
	m_z(0)
{

}

//Overloaded Constructor, takes in 4 floats as parameters
Quaternion::Quaternion(float w, float x, float y, float z) :
	m_w(w),
	m_x(x),
	m_y(y),
	m_z(z)
{

}
//Overloaded constructor, takes in 2 parameters, a float and a vector3
Quaternion::Quaternion(float w, Vector3 v) :
	m_w(w),
	m_x(v.getX()),
	m_y(v.getY()),
	m_z(v.getZ())
{

}
//Returns string version of all components in Quaternion
std::string Quaternion::toString()
{
	return std::string("( " + std::to_string(m_w) + " , " + std::to_string(m_x) + " , " + std::to_string(m_y) + " , " + std::to_string(m_z) + ")");
}

//Retruns the modulus of the quaternion
float Quaternion::modulus() const
{
	return sqrt(m_w * m_w + m_x * m_x + m_y * m_y + m_z * m_z);
}
//float modulusSquared() const;
float Quaternion::modulusSquared() const
{
	return (m_w * m_w + m_x * m_x + m_y * m_y + m_z * m_z);
}
//Normalises the quaternion
Quaternion Quaternion::normalise() const
{
	float temp = modulusSquared();
	if (temp > 0.001)
	{
		temp = sqrt(temp);
		return Quaternion(m_w / temp, m_x / temp, m_y / temp, m_z / temp);
	}
	else
	{
		return Quaternion(1, 0, 0, 0);
	}
}
//Returns the conjugate of a quaternion
Quaternion Quaternion::conjugate() const
{
	return Quaternion(m_w, -m_x, -m_y, -m_z);
}
//Returns the inverse of the Quaternion
Quaternion Quaternion::inverse() const
{
	return Quaternion(conjugate() * (1 / modulusSquared()));
}
//Allows you to rotate a quaternion by another quaternion
Quaternion Quaternion::multiply(const Quaternion& q) const
{
	return Quaternion(q.m_w *  m_w - q.m_x *  m_x - q.m_y *  m_y - q.m_z *  m_z,
					  q.m_w *  m_x + q.m_x *  m_w + q.m_y *  m_z - q.m_z *  m_y,
					  q.m_w *  m_y + q.m_y *  m_w + q.m_z *  m_x - q.m_x *  m_z,
					  q.m_w *  m_z + q.m_z *  m_w + q.m_x *  m_y - q.m_y *  m_x);
}
//Allows you to rotate the quaternion 
Vector3 Quaternion::rotate(const Vector3& v, const int& i) const
{
	Quaternion axis(normalise());
	Quaternion rotateQ;
	float angleRad = (acos(-1) / 180) * i;
	rotateQ = Quaternion(cos(angleRad / 2), sin(angleRad / 2) * axis.m_x, sin(angleRad / 2) * axis.m_y, sin(angleRad / 2) * axis.m_z);
	Quaternion inverse = rotateQ.inverse();
	Quaternion qNode = Quaternion(0, v.getX(), v.getY(), v.getZ());
	qNode = rotateQ * qNode * inverse;
	return Vector3(qNode.m_x, qNode.m_y, qNode.m_z);
}
//Quaternion operator-() const;
Quaternion Quaternion::operator-() const
{
	return Quaternion(-m_w, -m_x, -m_y, -m_z);
}

//use dto multiply 1 quaternion by another
Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(q1.multiply(q2));
}
//Allows you to add 2 quaternions together
Quaternion operator+(const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(q1.m_w + q2.m_w, q1.m_x + q2.m_x, q1.m_y + q2.m_y, q1.m_z + q2.m_z);
}
//Allows you to take one quaternion from another
Quaternion operator-(const Quaternion& q1, const Quaternion& q2)
{
	return Quaternion(q1.m_w - q2.m_w, q1.m_x - q2.m_x, q1.m_y - q2.m_y, q1.m_z - q2.m_z);
}
//Allows you to multiply a quaternion by a float
Quaternion operator*(const Quaternion &q, const float& f)
{
	return Quaternion(q.m_w * f, q.m_x * f, q.m_y * f, q.m_z * f);
}
//Allows you to multiply a quaternion by a double
Quaternion operator*(const Quaternion& q, const double& d)
{
	return Quaternion(q.m_w * d, q.m_x * d, q.m_y * d, q.m_z * d);
}
//Allows you to multiply a quaternion by a int
Quaternion operator*(const Quaternion& q, const int& i)
{
	return Quaternion(q.m_w * i, q.m_x * i, q.m_y * i, q.m_z * i);
}
//Allows you to multiply a quaternion by a float, reversed
Quaternion operator*(const float& f, const Quaternion& q)
{
	return Quaternion(q.m_w * f, q.m_x * f, q.m_y * f, q.m_z * f);
}
//Allows you to multiply a quaternion by a double, reversed
Quaternion operator*(const double& d, const Quaternion& q)
{
	return Quaternion(q.m_w * d, q.m_x * d, q.m_y * d, q.m_z * d);
}
//Allows you to multiply a quaternion by a int, reversed
Quaternion operator*(const int& i, const Quaternion& q)
{
	return Quaternion(q.m_w * i, q.m_x * i, q.m_y * i, q.m_z * i);
}
