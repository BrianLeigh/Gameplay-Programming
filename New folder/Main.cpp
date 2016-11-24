#include "Vector3.h"
#include "Matrix3.h"
#include "Quaternion.h"
#include <iostream>
int main()
{
	float f1 = 1;
	float f2 = 2;
	double d1 = 1.5;
	double d2 = 2.5;
	int i = 2;
	Vector3 v1(1, 1, 1);
	Vector3 v2(2, 2, 2);
	Matrix3 m1(v1, v1, v2);
	Matrix3 m2(f1, f2, f1, f2, f2, f1, f2, f1, f1);
	Quaternion q1(f2, v2);
	Quaternion q2(f2, f1, f1, f2);
	float answerFloat;
	double answerDouble;
	int answerInt;
	Vector3 answerVector;
	Quaternion answerQuaternion;
	Matrix3 answerMatrix;


	//Vector test
	answerFloat = v1 * v2;
	std::cout << "v1 * v2 = " << answerFloat << std::endl;

	answerVector = v1 + v2;
	std::cout << "v1 + v2 = " << answerVector.toString() << std::endl;

	answerVector = v1 - v2;
	std::cout << "v1 - v2 = " << answerVector.toString() << std::endl;

	answerVector = v1 * f1;
	std::cout << "v1 * f1 = " << answerVector.toString() << std::endl;
	
	answerVector = v1 * d1;
	std::cout << "v1 * d1 = " << answerVector.toString() << std::endl;

	answerVector = v1 * i;
	std::cout << "v1 * i = " <<  answerVector.toString() << std::endl;

	std::cout << "v1 length = " << v1.length() << std::endl;
	std::cout << "v1 length squared = " << v1.lengthSquared() << std::endl;

	//Quaternion Test

	answerQuaternion = q1 * q2;
	std::cout << "q1 * q2 = " << answerQuaternion.toString() << std::endl;

	answerQuaternion = q1 + q2;
	std::cout << "q1 + q2 = " <<  answerQuaternion.toString() << std::endl;

	answerQuaternion = q1 - q2;
	std::cout << "q1 - q2 = " << answerQuaternion.toString() << std::endl;

	answerQuaternion = q1 * f2;
	std::cout << "q1 * f2 = " <<  answerQuaternion.toString() << std::endl;

	answerQuaternion = q1 * d2;
	std::cout << "q1 * d2 = " <<  answerQuaternion.toString() << std::endl;

	answerQuaternion = q1 * i;
	std::cout << "q1 * i = " <<  answerQuaternion.toString() << std::endl;

	answerQuaternion = f2 * q1;
	std::cout << "f2 * q1 = " << answerQuaternion.toString() << std::endl;

	answerQuaternion = d2 * q1;
	std::cout << "d2 * q1 = " << answerQuaternion.toString() << std::endl;

	answerQuaternion = i * q1;
	std::cout << "i * q1 = " << answerQuaternion.toString() << std::endl;

	std::cout << "q1 modulus = " << q1.modulus() << std::endl;

	std::cout << "q1 modulus squared = " << q1.modulusSquared() << std::endl;
	 
	answerQuaternion = q1.conjugate();
	std::cout << "q1 conjugate = " << answerQuaternion.toString() << std::endl;

	answerQuaternion = q1.inverse();
	std::cout << "q1 inverse = " <<  answerQuaternion.toString() << std::endl;

	answerQuaternion = q1.multiply(q2);
	std::cout << "q1 multiply by q2 " << answerQuaternion.toString() << std::endl;

	answerVector = q1.rotate(v1, i);
	std::cout << "q1 rotate =" << answerVector.toString() << std::endl;

	answerQuaternion = q1.operator-();
	std::cout << "q1 negate = " << answerQuaternion.toString() << std::endl;

	//Matrix Test

	answerMatrix = m1 + m2;
	std::cout << "m1 + m2 = " <<  answerMatrix.toString << std::endl;

	answerMatrix = m1 - m2;
	std::cout << "m1 - m2 = " << answerMatrix.toString << std::endl;

	answerMatrix = m1 * f2;
	std::cout << "m1 * f2 = " << answerMatrix.toString << std::endl;

	answerMatrix = f2 * m1;
	std::cout << "f2 + m1 = " << answerMatrix.toString << std::endl;

	answerMatrix = m1.transpose(m2);
	std::cout << "m1 transpose = " << answerMatrix.toString << std::endl;

	answerMatrix = m1.inverse(m2);
	std::cout << "m1 inverse = " << answerMatrix.toString << std::endl;

	answerMatrix = m1.rotateX(i);
	std::cout << "m1 rotate x = " << answerMatrix.toString << std::endl;

	answerMatrix = m1.rotateY(i);
	std::cout << "m1 rotate y = " << answerMatrix.toString << std::endl;

	answerMatrix = m1.rotateZ(i);
	std::cout << "m1 rotate z = " << answerMatrix.toString << std::endl;
}