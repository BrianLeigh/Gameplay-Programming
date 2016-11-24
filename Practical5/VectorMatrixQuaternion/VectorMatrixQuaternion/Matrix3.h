//Description:		A program containing 3 classes that allows for the manipulation of vector3, matrix and quaternion variables.
//Name:				Brian Leigh
//Student ID:		C00159600
//Date:				23/11/2016

#pragma once
#include "Vector3.h"
#include <math.h>

class Matrix3
{

	friend Matrix3 operator+(const Matrix3& m1, const Matrix3& m2);
	friend Matrix3 operator-(const Matrix3& m1, const Matrix3& m2);
	friend Matrix3 operator-(Matrix3& m);
	friend Vector3 operator*(const Matrix3& m, const Vector3& v);
	friend Vector3 operator*(const Vector3& v, const Matrix3& m);
	friend Matrix3 operator*(const double& d, const Matrix3& m);
	friend Matrix3 operator*(const Matrix3& m, const float& f);
	friend Matrix3 operator*(const Matrix3& m1, const Matrix3& m2);

public:
	Matrix3();
	Matrix3(Vector3 x, Vector3 y, Vector3 z);
	Matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
	Vector3 row(int i) const;
	Vector3 column(int j) const;
	Matrix3 transpose(const Matrix3& m);
	float determinant() const;
	Matrix3 inverse(const Matrix3& m);
	Matrix3 rotateX(const int &angle);
	Matrix3 rotateY(const int &angle);
	Matrix3 rotateZ(const int &angle);
	Matrix3 scale(const float& s);
	std::string toString();

private:
	float m_m11;
	float m_m12;
	float m_m13;
	float m_m21;
	float m_m22;
	float m_m23;
	float m_m31;
	float m_m32;
	float m_m33;
};