#include <iostream>
#include "Vectors.h"



int main()
{
	//Vector2 Vec2Vec1(10.0f, 20.0f);
	//Vector2 Vec2Vec2(5.0f, 0.2f);
	//
	//Vector2 Vec2Test1(0.0f, 0.0f);
	//Vector2 Vec2Test2(0.0f, 0.0f);
	//Vector2 Vec2Test3(0.0f, 0.0f);
	//float Vec2Test4;
	//float f2Float = 5.0f;
	//
	//
	//std::cout << "Vec 1: (" << Vec2Vec1.x << "," << Vec2Vec1.y << ")" << std::endl;
	//std::cout << "Vec 2: (" << Vec2Vec2.x << "," << Vec2Vec2.y << ")" << std::endl;
	//std::cout << "Float:  " << f2Float << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << "Add Vectors" << std::endl;
	//Vec2Test1 = Vec2Vec1 + Vec2Vec2;
	//std::cout << "(" << Vec2Test1.x << "," << Vec2Test1.y << ")" << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << "Subtract Vectors" << std::endl;
	//Vec2Test2 = Vec2Vec1 - Vec2Vec2;
	//std::cout << "(" << Vec2Test2.x << "," << Vec2Test2.y << ")" << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << "Multiply Vectors" << std::endl;
	//Vec2Test2 = Vec2Vec1 * Vec2Vec2;
	//std::cout << "(" << Vec2Test2.x << "," << Vec2Test2.y << ")" << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << "Divide Vectors" << std::endl;
	//Vec2Test2 = Vec2Vec1 / Vec2Vec2;
	//std::cout << "(" << Vec2Test2.x << "," << Vec2Test2.y << ")" << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << "Vector * Float" << std::endl;
	//Vec2Test3 = Vec2Test3.VecFlo(Vec2Vec1, f2Float);
	//std::cout << "(" << Vec2Test3.x << "," << Vec2Test3.y << ")" << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << "Float * Vector" << std::endl;
	//Vec2Test4 = Vec2Vec1.FloVec(Vec2Vec1, f2Float);
	//std::cout << Vec2Test4 << std::endl;
	//
	//
	//system("pause");

	Vector3 Vec3Vec1(10.0f, 20.0f, 15.0f);
	Vector3 Vec3Vec2(5.0f, 0.2f, 3.0f);
		  	   
	Vector3 Vec3Test1(0.0f, 0.0f, 0.0f);
	Vector3 Vec3Test2(0.0f, 0.0f, 0.0f);
	Vector3 Vec3Test3(0.0f, 0.0f, 0.0f);
	Vector3 Vec3Test4(0.0f, 0.0f, 0.0f);
	Vector3 Vec3Test5(0.0f, 0.0f, 0.0f);
	Vector3 Vec3Test6;
	
	float f3Float = 5.0f;


	std::cout << "Vec 1: (" << Vec3Vec1.x << "," << Vec3Vec1.y << "," << Vec3Vec1.z << ")" << std::endl;
	std::cout << "Vec 2: (" << Vec3Vec2.x << "," << Vec3Vec2.y << "," << Vec3Vec2.z << ")" << std::endl;
	std::cout << "Float:  " << f3Float << std::endl;

	std::cout << std::endl;
	std::cout << "Add Vectors" << std::endl;
	Vec3Test1 = Vec3Vec1 + Vec3Vec2;
	std::cout << "(" << Vec3Test1.x << "," << Vec3Test1.y << "," << Vec3Test1.z << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "Subtract Vectors" << std::endl;
	Vec3Test2 = Vec3Vec1 - Vec3Vec2;
	std::cout << "(" << Vec3Test2.x << "," << Vec3Test2.y << "," << Vec3Test2.z << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "Multiply Vectors" << std::endl;
	Vec3Test3 = Vec3Vec1 * Vec3Vec2;
	std::cout << "(" << Vec3Test3.x << "," << Vec3Test3.y << "," << Vec3Test3.z << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "Divide Vectors" << std::endl;
	Vec3Test4 = Vec3Vec1 / Vec3Vec2;
	std::cout << "(" << Vec3Test4.x << "," << Vec3Test4.y << "," << Vec3Test4.z << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "Vector * Float" << std::endl;
	Vec3Test5 = Vec3Test5.VecFlo(Vec3Vec1, f3Float);
	std::cout << "(" << Vec3Test5.x << "," << Vec3Test5.y << "," << Vec3Test5.z << ")" << std::endl;


	std::cout << "----------MATRIX---------" << std::endl << std::endl;

	Matrix3 Mat3Mat1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	std::cout << "Matrix 1" << std::endl;
	std::cout << "| " << Mat3Mat1.a11 << "  " << Mat3Mat1.a12 << "  " << Mat3Mat1.a13 << " |" << std::endl;
	std::cout << "| " << Mat3Mat1.a21 << "  " << Mat3Mat1.a22 << "  " << Mat3Mat1.a23 << " |" << std::endl;
	std::cout << "| " << Mat3Mat1.a31 << "  " << Mat3Mat1.a32 << "  " << Mat3Mat1.a33 << " |" << std::endl;

	Matrix3 Mat3Mat2(2, 3, 4, 5, 6, 7, 8, 9, 1);
	std::cout << "Matrix 2" << std::endl;
	std::cout << "| " << Mat3Mat2.a11 << "  " << Mat3Mat2.a12 << "  " << Mat3Mat2.a13 << " |" << std::endl;
	std::cout << "| " << Mat3Mat2.a21 << "  " << Mat3Mat2.a22 << "  " << Mat3Mat2.a23 << " |" << std::endl;
	std::cout << "| " << Mat3Mat2.a31 << "  " << Mat3Mat2.a32 << "  " << Mat3Mat2.a33 << " |" << std::endl;

	Matrix3 Mat3Test1 = (Mat3Mat1 + Mat3Mat2);
	std::cout << "Matrix 1 + Matrix 2" << std::endl;
	std::cout << "| " << Mat3Test1.a11 << "  " << Mat3Test1.a12 << "  " << Mat3Test1.a13 << " |" << std::endl;
	std::cout << "| " << Mat3Test1.a21 << "  " << Mat3Test1.a22 << "  " << Mat3Test1.a23 << " |" << std::endl;
	std::cout << "| " << Mat3Test1.a31 << "  " << Mat3Test1.a32 << "  " << Mat3Test1.a33 << " |" << std::endl;

	Matrix3 Mat3Test2 = (Mat3Mat1 - Mat3Mat2);
	std::cout << "Matrix 2 - Matrix 1" << std::endl;
	std::cout << "| " << Mat3Test2.a11 << "  " << Mat3Test2.a12 << "  " << Mat3Test2.a13 << " |" << std::endl;
	std::cout << "| " << Mat3Test2.a21 << "  " << Mat3Test2.a22 << "  " << Mat3Test2.a23 << " |" << std::endl;
	std::cout << "| " << Mat3Test2.a31 << "  " << Mat3Test2.a32 << "  " << Mat3Test2.a33 << " |" << std::endl;

	Matrix3 Mat3Test3 = Mat3Mat1 * Mat3Mat2;
	std::cout << "Matrix 1 * Matrix 2" << std::endl;
	std::cout << "| " << Mat3Test3.a11 << "  " << Mat3Test3.a12 << "  " << Mat3Test3.a13 << " |" << std::endl;
	std::cout << "| " << Mat3Test3.a21 << "  " << Mat3Test3.a22 << "  " << Mat3Test3.a23 << " |" << std::endl;
	std::cout << "| " << Mat3Test3.a31 << "  " << Mat3Test3.a32 << "  " << Mat3Test3.a33 << " |" << std::endl;
	system("pause");
}