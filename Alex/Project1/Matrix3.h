#include <iostream>

#ifndef Matrix3_H_
#define Matrix3_H_

class Matrix3
{
public:

	Matrix3();
	
	
	Matrix3 operator+(Matrix3 mInput);
	Matrix3 operator-(Matrix3 mInput);
	Matrix3 operator*(Matrix3 mInput);
	//Matrix3 operator*(Vector3 vInput);

	


	~Matrix3();


	union
	{
		struct
		{
			double m00, m01, m02, m10, m11, m12, m20, m21, m22;
		};
		double m[9];
		double mm[3][3];
	};


	

private:

};


#endif Matrix3_H_