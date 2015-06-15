#include <iostream>

#ifndef Matrix4_H_
#define Matrix4_H_

class Matrix4
{
public:

	Matrix4();


	Matrix4 operator+(Matrix4 mInput);
	Matrix4 operator-(Matrix4 mInput);
	Matrix4 operator*(Matrix4 mInput);




	~Matrix4();


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


#endif Matrix4_H_