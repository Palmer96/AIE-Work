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



	//			float MatVec(Vector2 a, float Matrix);
	//			float MatMat(float Matrix1, float Matrix2);

	float Dot(Vector2 a_1, Vector2 a_2);
	float Magnitude(Vector2 a);
	Vector2 Normalised(Vector2 a, float magnitude);


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


class Vector3
{
public:
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();

	Vector3 operator+(const Vector3& v3) const;
	Vector3& operator+=(const Vector3& v3);
	Vector3 operator-(const Vector3& v3) const;
	Vector3& operator-=(const Vector3& v3);
	Vector3 Vector3::operator/(float v3)const;
	Vector3& operator/=(const Vector3& v3);
	Vector3 Vector3::operator*(float v3)const;
	Vector3& operator*=(const Vector3& v3);

	Vector3 AddVec(Vector3 a_1, Vector3 a_2, Vector3 a_z);
	Vector3 SubVec(Vector3 a_1, Vector3 a_2, Vector3 a_z);
	Vector3 VecFlo(Vector3 a, float Float);
	float FloVec(Vector3 a, float Float);

	float Dot(Vector3 a_1, Vector3 a_2, Vector3 a_z);
	Vector3 Cross(Vector3 a_1, Vector3 a_2, Vector3 a_z);
	float Magnitude(Vector3 a);
	Vector3 Normalised(Vector3 a, float magnitude);

	float x;
	float y;
	float z;

};




class Vector4
{
public:
	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_q);
	~Vector4();

	Vector4 operator+(const Vector4& v4) const;
	Vector4& operator+=(const Vector4& v4);
	Vector4 operator-(const Vector4& v4) const;
	Vector4& operator-=(const Vector4& v4);
	Vector4 operator/(float v4)const;
	Vector4& operator/=(const Vector4& v4);
	Vector4 operator*(float v4)const;
	Vector4& operator*=(const Vector4& v4);
	
	Vector4 AddVec(Vector4 a_1, Vector4 a_2, Vector4 a_z, Vector4 a_q);
	Vector4 SubVec(Vector4 a_1, Vector4 a_2, Vector4 a_z, Vector4 a_q);
	Vector4 VecFlo(Vector4 a, float Float);
	float FloVec(Vector4 a, float Float);

	float Dot(Vector4 a_1, Vector4 a_2, Vector4 a_z, Vector4 a_q);
	Vector4 Cross(Vector4 a_1, Vector4 a_2, Vector4 a_z, Vector4 a_q);
	float Magnitude(Vector4 a);
	Vector4 Normalised(Vector4 a, float magnitude);

	float x;
	float y;
	float z;
	float q;

};














#endif // _VECTORS_H
