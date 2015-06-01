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

	/*
	float FloVec(float x1, float y1, float Float);
	float MatVec(float x1, float y1, float Matrix);
	float MatMat(float Matrix1, float Matrix2);
	float Dot(float x1, float y1, float x2, float y2);
	float Cross(float x1, float y1, float x2, float y2);
	float Magnitude(float x, float y);
	float Normalised(float x, float y);
	*/
	
	Vector2 operator+(const Vector2& v2) const;
	Vector2& operator+=(const Vector2& v2);
	Vector2 operator-(const Vector2& v2) const;
	Vector2& operator-=(const Vector2& v2);



	float x;
	float y;

};






#endif // _VECTORS_H
