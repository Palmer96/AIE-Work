#include <iostream>
#include "Vectors.h"



int main()
{
	Vector2 Vec1(10.0f, 20.0f);
	Vector2 Vec2(5.0f, 0.2f);

	Vector2 VecTest1(0.0f, 0.0f);
	Vector2 VecTest2(0.0f, 0.0f);
	Vector2 VecTest3(0.0f, 0.0f);
	float VecTest4;
	float fFloat = 5.0f;

	


	//std::cout << Vec3 << std::endl;

	std::cout << Vec1.x << std::endl;
	std::cout << Vec1.y << std::endl << std::endl;


	std::cout << "(" << Vec1.x << "," << Vec1.y << ")" << std::endl;
	std::cout << "(" << Vec2.x << "," << Vec2.y << ")" << std::endl;
	
	std::cout << std::endl;
	std::cout << "Add Vectors" << std::endl;
	VecTest1 = Vec1 + Vec2;
	std::cout << "(" << VecTest1.x << "," << VecTest1.y << ")" << std::endl;
	
	//std::cout << std::endl;
	//std::cout << "Subtract Vectors" << std::endl;
	//VecTest2 = VecTest2.SubVec(Vec1, Vec2);
	//std::cout << "(" << VecTest2.x << "," << VecTest2.y << ")" << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << "Vector * Float" << std::endl;
	//VecTest3 = VecTest3.VecFlo(Vec1, fFloat);
	//std::cout << "(" << VecTest3.x << "," << VecTest3.y << ")" << std::endl;
	//
	//std::cout << std::endl;
	//std::cout << "Vector * Float" << std::endl;
	//VecTest4 = Vec1.FloVec(Vec1, fFloat);
	//std::cout << VecTest4 << std::endl;


	system("pause");


}