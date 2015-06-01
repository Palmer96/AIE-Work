#ifndef _VECTORS_H
#define _VECTORS_H



class Vector2
{
public:
	Vector2();
	Vector2(float a_x, float a_y);
	~Vector2();

	Vector2 AddVec(Vector2 a_1, Vector2 a_2);
	Vector2 SubVec(Vector2 a_1, Vector2 a_2);

	Vector2 VecFlo(Vector2 a, float Float);


	float FloVec(Vector2 a, float Float);
/*


	float MatVec(Vector2 a, float Matrix);
	float MatMat(float Matrix1, float Matrix2);
	float Dot(Vector2 a_1, Vector2 a_2);
	float Cross(Vector2 a_1, Vector2 a_2);
	float Magnitude(Vector2 a);
	float Normalised(Vector2 a);
	*/

	Vector2 operator+(const Vector2& v2) const;
	Vector2& operator+=(const Vector2& v2);

	Vector2 operator-(const Vector2& v2) const;
	Vector2& operator-=(const Vector2& v2);

	Vector2 Vector2::operator/(float v2)const;
	Vector2& operator/=(const Vector2& v2);

	Vector2 Vector2::operator*(float v2)const;
	Vector2& operator*=(const Vector2& v2);




	float x;
	float y;

};


















#endif // _VECTORS_H
