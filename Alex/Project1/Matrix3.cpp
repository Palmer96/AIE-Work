#include <iostream>
#include "Matrix3.h"

Matrix3::Matrix3()
{
	m[0] = 1;
	m[1] = 2;
	m[2] = 3;
	m[3] = 4;
	m[4] = 5;
	m[5] = 6;
	m[6] = 7;
	m[7] = 8;
	m[8] = 9;

}

Matrix3 Matrix3::operator+(Matrix3 mInput)
{
	Matrix3 fish;

	for (int i = 0; i < 9; i++)
	{
		fish.m[i] = m[i] + mInput.m[i];
	}
	return fish;
}


Matrix3 Matrix3::operator-(Matrix3 mInput)
{
	Matrix3 fish;

	for (int i = 0; i < 9; i++)
	{
		fish.m[i] = m[i] - mInput.m[i];
	}
	return fish;
}

Matrix3 Matrix3::operator*(Matrix3 mInput)
{
	Matrix3 fish;
	float fTemp = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int h = 0; h < 3; h++)
			{
				 fTemp += mm[h][j] * mInput.mm[i][h];
			}
			fish.mm[i][j] = fTemp;
			fTemp = 0;
		}
	}
	return fish;
}

//Matrix3 Matrix3::operator*(Vector3 vInput)
//{
//	Matrix3 fish;
//	Matrix3 temp;
//	temp.m[0] = vInput.x;
//	temp.m[1] = vInput.y;
//	temp.m[2] = vInput.x;
//	float fTemp = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			for (int h = 0; h < 3; h++)
//			{
//				fTemp += mm[h][j] * temp.m[i];
//			}
//			fish.mm[i][j] = fTemp;
//			fTemp = 0;
//		}
//	}
//	return fish;
//}


Matrix3::~Matrix3()
{


}