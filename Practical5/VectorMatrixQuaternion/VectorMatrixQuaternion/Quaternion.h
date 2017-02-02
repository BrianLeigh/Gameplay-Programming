//Description:		A program containing 3 classes that allows for the manipulation of vector3, matrix and quaternion variables.
//Name:				Brian Leigh
//Student ID:		C00159600
//Date:				23/11/2016
#include <string>
#pragma once

class Vector3;

class Quaternion
{

	friend Quaternion operator*(const Quaternion& q1, const Quaternion& q2);
	friend Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
	friend Quaternion operator-(const Quaternion& q1, const Quaternion& q2);
	friend Quaternion operator*(const Quaternion& q, const float& f);
	friend Quaternion operator*(const Quaternion& q, const double& d);
	friend Quaternion operator*(const Quaternion& q, const int& i);
	friend Quaternion operator*(const float& f, const Quaternion& q );
	friend Quaternion operator*(const double& d, const Quaternion& q);
	friend Quaternion operator*(const int& i, const Quaternion& q);

public:
	Quaternion(); //Default Constructor
	Quaternion(float w, float x, float y, float z); //overloaded constructor
	Quaternion(float f, Vector3 v); //overloaded constructor
	std::string toString();
	float modulus() const;
	float modulusSquared() const;
	Quaternion normalise() const;
	Quaternion conjugate() const;
	Quaternion inverse() const;
	Quaternion multiply(const Quaternion& q) const;
	Vector3 rotate(const Vector3& q, const int& i) const;
	Quaternion operator-() const;


private:
	float m_w;
	float m_x;
	float m_y;
	float m_z;

};
#include "Vector3.h"