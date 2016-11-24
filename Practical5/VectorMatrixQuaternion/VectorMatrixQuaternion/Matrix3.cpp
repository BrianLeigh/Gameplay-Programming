//Description:		A program containing 3 classes that allows for the manipulation of vector3, matrix and quaternion variables.
//Name:				Brian Leigh
//Student ID:		C00159600
//Date:				23/11/2016

#include "Matrix3.h"
//Default constructor
Matrix3::Matrix3() :
	m_m11(0.0),
	m_m12(0.0),
	m_m13(0.0),
	m_m21(0.0),
	m_m22(0.0),
	m_m23(0.0),
	m_m31(0.0),
	m_m32(0.0),
	m_m33(0.0)
{

}
//Overloaded constructor, takes 3 vector3s as parameters
Matrix3::Matrix3(Vector3 row1, Vector3 row2, Vector3 row3) :
	m_m11(row1.getX()),
	m_m12(row1.getY()),
	m_m13(row1.getZ()),
	m_m21(row2.getX()),
	m_m22(row2.getY()),
	m_m23(row2.getZ()),
	m_m31(row3.getX()),
	m_m32(row3.getY()),
	m_m33(row3.getZ())
{
}
//Overloaded constructor, takes 9 floats as parameters
Matrix3::Matrix3(float m11, float m12, float m13,
	float m21, float m22, float m23,
	float m31, float m32, float m33) :
	m_m11(m11),
	m_m12(m12),
	m_m13(m13),
	m_m21(m21),
	m_m22(m22),
	m_m23(m23),
	m_m31(m31),
	m_m32(m32),
	m_m33(m33)
{
}
//Used to find the 3 rows of a matrix by returning 3 vector3s, each corresponding to a row in the matrix3
Vector3 Matrix3::row(int i) const
{
	switch (i)
	{
	case 0:
		return Vector3(m_m11, m_m12, m_m13);
	case 1:
		return Vector3(m_m21, m_m22, m_m23);
	case 2:
	default:
		return Vector3(m_m31, m_m32, m_m33);
	}
}
//Used to find the 3 columns of a matrix3 by returning 3 vector3s, each corresponding to a different column
Vector3 Matrix3::column(int i) const
{
	switch (i)
	{
	case 0:
		return Vector3(m_m11, m_m21, m_m31);
	case 1:
		return Vector3(m_m12, m_m22, m_m32);
	case 2:
	default:
		return Vector3(m_m13, m_m23, m_m33);
	}
}
//Used to transpose a matrix3
Matrix3 Matrix3::transpose(const Matrix3& m)
{
	return Matrix3(m.column(0),
		m.column(1),
		m.column(2));
}
//Used to find the determinant of a matrix3
float Matrix3::determinant() const
{
	return m_m11 * m_m22 * m_m33 - m_m11 * m_m32 * m_m23 + m_m21 * m_m32 * m_m13 - m_m31 * m_m22 * m_m13 + m_m31 * m_m12 * m_m23 - m_m21 * m_m12 * m_m33;
}
//Used to find the inverse of a matrix3
Matrix3 Matrix3::inverse(const Matrix3& m)
{
	float det = m.determinant();
	if (det == 0)
		return Matrix3();
	else
	{
		float scale = 1 / det;
		return Matrix3(m.m_m22 * m.m_m33 - m.m_m23 * m.m_m32, m.m_m13 * m.m_m32 - m.m_m12 * m.m_m33, m.m_m12 * m.m_m23 - m.m_m13 * m.m_m22,
			m.m_m23 * m.m_m31 - m.m_m21 * m.m_m33, m.m_m11 * m.m_m33 - m.m_m13 * m.m_m31, m.m_m13 * m.m_m21 - m.m_m11 * m.m_m23,
			m.m_m21 * m.m_m32 - m.m_m22 * m.m_m31, m.m_m12 * m.m_m31 - m.m_m11 * m.m_m32, m.m_m11 * m.m_m22 - m.m_m12 * m.m_m21) * scale;
	}
}
//Used to rotate a matrix3 along its x axis
Matrix3 Matrix3::rotateX(const int &angle)
{
	float radians = radians = acos(-1) / 180 * angle;
	Matrix3 answer;
	answer.m_m11 = 1;
	answer.m_m12 = 0;
	answer.m_m13 = 0;
	answer.m_m21 = 0;
	answer.m_m22 = cos(radians);
	answer.m_m23 = -sin(radians);
	answer.m_m31 = 0;
	answer.m_m32 = sin(radians);
	answer.m_m33 = cos(radians);
	return answer;
}
//Used to rotate a matrix3 along its y axis
Matrix3 Matrix3::rotateY(const int &angle)
{
	float radians = radians = acos(-1) / 180 * angle;
	Matrix3 answer;
	answer.m_m11 = cos(radians);
	answer.m_m12 = 0;
	answer.m_m13 = sin(radians);
	answer.m_m21 = 0;
	answer.m_m22 = 1;
	answer.m_m23 = 0;
	answer.m_m31 = -sin(radians);
	answer.m_m32 = 0;
	answer.m_m33 = cos(radians);
	return answer;
}
//Used to rotate a matrix3 along its z axis
Matrix3 Matrix3::rotateZ(const int &angle)
{
	float radians = radians = acos(-1) / 180 * angle;
	Matrix3 answer;
	answer.m_m11 = cos(radians);
	answer.m_m12 = -sin(radians);
	answer.m_m13 = 0;
	answer.m_m21 = sin(radians);
	answer.m_m22 = cos(radians);
	answer.m_m23 = 0;
	answer.m_m31 = 0;
	answer.m_m32 = 0;
	answer.m_m33 = 1;
	return answer;
}
//Used to scale a matrix by a scalar value
Matrix3 Matrix3::scale(const float& s)
{
	return Matrix3(s/100, 0, 0,
				   0, s/ 100, 0,
				   0, 0, s/ 100);
}
//Allows you to add 2 matrix3s
Matrix3 operator+(const Matrix3& m1, const Matrix3& m2)
{
	return Matrix3(m1.row(0) + m2.row(0),
				   m1.row(1) + m2.row(1),
				   m1.row(2) + m2.row(2));
}
//Allows you to take one matrix3 from another
Matrix3 operator-(const Matrix3& m1, const Matrix3& m2)
{
	return Matrix3(m1.row(0) - m2.row(0),
		m1.row(1) - m2.row(1),
		m1.row(2) - m2.row(2));
}
//Allows you to negate amatrix3
Matrix3 operator-(Matrix3 & m)
{
	return -1 * m;
}
//Allows you to multiply a matrix3 by a vector3
Vector3 operator*(const Matrix3& m, const Vector3& v)
{
	return Vector3(m.m_m11 * v.getX() + m.m_m12 * v.getY() + m.m_m13 * v.getZ(),
		m.m_m21 * v.getX() + m.m_m22 * v.getY() + m.m_m23 * v.getZ(),
		m.m_m31 * v.getX() + m.m_m32 * v.getY() + m.m_m33 * v.getZ());
}
//Allows you to multiply a matrix by a vector, reversed
Vector3 operator*(const Vector3& v, const Matrix3& m)
{
	return Vector3(m.m_m11 * v.getX() + m.m_m12 * v.getY() + m.m_m13 * v.getZ(),
		m.m_m21 * v.getX() + m.m_m22 * v.getY() + m.m_m23 * v.getZ(),
		m.m_m31 * v.getX() + m.m_m32 * v.getY() + m.m_m33 * v.getZ());
}
//Allows you to multiply a matrix by a float
Matrix3 operator*(const Matrix3& m, const float& f)
{
	return Matrix3(m.row(0) * f, m.row(1) * f, m.row(2) * f);
}
//Allows you to multiply a matrix by a double
Matrix3 operator*(const double& d, const Matrix3& m)
{
	return Matrix3(m.row(0) * d, m.row(1) * d, m.row(2) * d);
}
//Allows you to multiply a matrix3 by another matrix3
Matrix3 operator*(const Matrix3& m1, const Matrix3& m2)
{
	return Matrix3(m1.row(0) * m2.column(0), m1.row(0) * m2.column(1), m1.row(0) * m2.column(2),
		m1.row(1) * m2.column(0), m1.row(1) * m2.column(1), m1.row(1) * m2.column(2),
		m1.row(2) * m2.column(0), m1.row(2) * m2.column(1), m1.row(2) * m2.column(2));
}
std::string Matrix3::toString()
{
	return std::string("( " + std::to_string(m_m11) + " , " + std::to_string(m_m12) + " , " + std::to_string(m_m13)
						+ " , " + std::to_string(m_m21) + " , " + std::to_string(m_m22) + " , " + std::to_string(m_m23)
						+ " , " + std::to_string(m_m31) + " , " + std::to_string(m_m32) + " , " + std::to_string(m_m33) + ")");
}