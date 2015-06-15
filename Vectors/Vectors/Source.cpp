#include <iostream>
#include "Vectors.h"



int main()
{
	
	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
	std::cout << "//--------//	Vector 2D	//-----------------------------------------------//" << std::endl;
	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
	Vector2 Vec1(10.0f, 20.0f);
	std::cout << "Vec 1: (" << Vec1.x << "," << Vec1.y << ")" << std::endl;
	std::cout << "       |" << Vec1.x << "|" << std::endl;
	std::cout << "       |" << Vec1.y << "|" << std::endl;

	Matrix2 Mat1(1, 2, 3, 4);
	std::cout << "Matrix 1" << std::endl;
	std::cout << "| " << Mat1.a11 << "  " << Mat1.a12 << " |" << std::endl;
	std::cout << "| " << Mat1.a21 << "  " << Mat1.a22 << " |" << std::endl;



	Vector2 newVec = Mat1 * Vec1;

	std::cout << "(" << newVec.x << "," << newVec.y << ")" << std::endl;






	Matrix3 Mat3Test3 = Mat3Test3.Translation(Vec1.x, Vec1.y) * Mat3Test3.Scale(Vec1.x, Vec1.y);
	std::cout << "Matrix 1 * Matrix 2" << std::endl;
	std::cout << "| " << Mat3Test3.a11 << "  " << Mat3Test3.a12 << "  " << Mat3Test3.a13 << " |" << std::endl;
	std::cout << "| " << Mat3Test3.a21 << "  " << Mat3Test3.a22 << "  " << Mat3Test3.a23 << " |" << std::endl;
	std::cout << "| " << Mat3Test3.a31 << "  " << Mat3Test3.a32 << "  " << Mat3Test3.a33 << " |" << std::endl;







	/*

std::cout << "//-------------------------------------------------------------------------//" << std::endl;
	std::cout << "//--------//	Vector 3D	//-----------------------------------------------//" << std::endl;
	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
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

	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
	std::cout << "//--------//	Vector 4D	//-----------------------------------------------//" << std::endl;
	std::cout << "//-------------------------------------------------------------------------//" << std::endl;

	Vector3 Vec4Vec1(10.0f, 20.0f, 15.0f);
	Vector3 Vec4Vec2(5.0f, 0.2f, 3.0f);
			   
	Vector3 Vec4Test1(0.0f, 0.0f, 0.0f);
	Vector3 Vec4Test2(0.0f, 0.0f, 0.0f);
	Vector3 Vec4Test3(0.0f, 0.0f, 0.0f);
	Vector3 Vec4Test4(0.0f, 0.0f, 0.0f);
	Vector3 Vec4Test5(0.0f, 0.0f, 0.0f);
	Vector3 Vec4Test6;

	//float f3Float = 5.0f;


	std::cout << "Vec 1: (" << Vec4Vec1.x << "," << Vec4Vec1.y << "," << Vec4Vec1.z << ")" << std::endl;
	std::cout << "Vec 2: (" << Vec4Vec1.x << "," << Vec4Vec1.y << "," << Vec4Vec1.z << ")" << std::endl;
	std::cout << "Float:  " << f3Float << std::endl;

	std::cout << std::endl;
	std::cout << "Add Vectors" << std::endl;
	Vec3Test1 = Vec4Vec1 + Vec4Vec1;
	std::cout << "(" << Vec4Test1.x << "," << Vec4Test1.y << "," << Vec4Test1.z << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "Subtract Vectors" << std::endl;
	Vec3Test2 = Vec4Vec1 - Vec4Vec1;
	std::cout << "(" << Vec4Test2.x << "," << Vec4Test2.y << "," << Vec4Test2.z << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "Multiply Vectors" << std::endl;
	Vec3Test3 = Vec4Vec1 * Vec4Vec1;
	std::cout << "(" << Vec4Test3.x << "," << Vec4Test3.y << "," << Vec4Test3.z << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "Divide Vectors" << std::endl;
	Vec3Test4 = Vec4Vec1 / Vec4Vec2;
	std::cout << "(" << Vec4Test4.x << "," << Vec4Test4.y << "," << Vec4Test4.z << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "Vector * Float" << std::endl;
	Vec3Test5 = Vec3Test5.VecFlo(Vec4Vec1, f3Float);
	std::cout << "(" << Vec3Test5.x << "," << Vec3Test5.y << "," << Vec3Test5.z << ")" << std::endl;
	*/

	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
	std::cout << "//--------//	Matrix 2D	//-----------------------------------------------//" << std::endl;
	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
	
	
	/*

	Matrix2 Mat2Mat2(2, 3, 4, 5);
	std::cout << "Matrix 2" << std::endl;
	std::cout << "| " << Mat2Mat2.a11 << "  " << Mat2Mat2.a12 << " |" << std::endl;
	std::cout << "| " << Mat2Mat2.a21 << "  " << Mat2Mat2.a22 << " |" << std::endl;


	Matrix2 Mat2Test1 = (Mat2Mat1 + Mat2Mat2);
	std::cout << "Matrix 1 + Matrix 2" << std::endl;
	std::cout << "| " << Mat2Test1.a11 << "  " << Mat2Test1.a12 << " |" << std::endl;
	std::cout << "| " << Mat2Test1.a21 << "  " << Mat2Test1.a22 << " |" << std::endl;
																  
	Matrix2 Mat2Test2 = (Mat2Mat1 - Mat2Mat2);
	std::cout << "Matrix 2 - Matrix 1" << std::endl;			  
	std::cout << "| " << Mat2Test2.a11 << "  " << Mat2Test2.a12 << " |" << std::endl;
	std::cout << "| " << Mat2Test2.a21 << "  " << Mat2Test2.a22 << " |" << std::endl;
																  
	Matrix2 Mat2Test3 = Mat2Mat1 * Mat2Mat2;
	std::cout << "Matrix 1 * Matrix 2" << std::endl;			  
	std::cout << "| " << Mat2Test3.a11 << "  " << Mat2Test3.a12 << " |" << std::endl;
	std::cout << "| " << Mat2Test3.a21 << "  " << Mat2Test3.a22 << " |" << std::endl;
	
	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
	std::cout << "//--------//	Matrix 3D	//-----------------------------------------------//" << std::endl;
	std::cout << "//-------------------------------------------------------------------------//" << std::endl;

	Matrix3 Mat3Mat1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	std::cout << "Matrix 1" << std::endl;
	std::cout << "| " << Mat3Mat1.a11 << "  " << Mat3Mat1.a12 << "  " << Mat3Mat1.a13 << " |" << std::endl;
	std::cout << "| " << Mat3Mat1.a21 << "  " << Mat3Mat1.a22 << "  " << Mat3Mat1.a23 << " |" << std::endl;
	std::cout << "| " << Mat3Mat1.a31 << "  " << Mat3Mat1.a32 << "  " << Mat3Mat1.a33 << " |" << std::endl;

	std::cout << "" << std::endl;
	Matrix3 NewMatrix = NewMatrix.Transpose(Mat3Mat1);
	std::cout << "New Matrix" << std::endl;
	std::cout << "| " << NewMatrix.a11 << "  " << NewMatrix.a12 << "  " << NewMatrix.a13 << " |" << std::endl;
	std::cout << "| " << NewMatrix.a21 << "  " << NewMatrix.a22 << "  " << NewMatrix.a23 << " |" << std::endl;
	std::cout << "| " << NewMatrix.a31 << "  " << NewMatrix.a32 << "  " << NewMatrix.a33 << " |" << std::endl;



	
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

	std::cout << "//-------------------------------------------------------------------------//" << std::endl;
	std::cout << "//--------//	Matrix 4D	//-----------------------------------------------//" << std::endl;
	std::cout << "//-------------------------------------------------------------------------//" << std::endl;

	
	Matrix4 Mat4Mat1(1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7);
	std::cout << "Matrix 1" << std::endl;
	std::cout << "| " << Mat4Mat1.a11 << "  " << Mat4Mat1.a12 << "  " << Mat4Mat1.a13 << "  " << Mat4Mat1.a14 << " |" << std::endl;
	std::cout << "| " << Mat4Mat1.a21 << "  " << Mat4Mat1.a22 << "  " << Mat4Mat1.a23 << "  " << Mat4Mat1.a24 << " |" << std::endl;
	std::cout << "| " << Mat4Mat1.a31 << "  " << Mat4Mat1.a32 << "  " << Mat4Mat1.a33 << "  " << Mat4Mat1.a34 << " |" << std::endl;
	std::cout << "| " << Mat4Mat1.a41 << "  " << Mat4Mat1.a42 << "  " << Mat4Mat1.a43 << "  " << Mat4Mat1.a44 << " |" << std::endl;

	Matrix4 Mat4Mat2(2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8);
	std::cout << "Matrix 2" << std::endl;
	std::cout << "| " << Mat4Mat2.a11 << "  " << Mat4Mat2.a12 << "  " << Mat4Mat2.a13 << "  " << Mat4Mat2.a14 << " |" << std::endl;
	std::cout << "| " << Mat4Mat2.a21 << "  " << Mat4Mat2.a22 << "  " << Mat4Mat2.a23 << "  " << Mat4Mat2.a24 << " |" << std::endl;
	std::cout << "| " << Mat4Mat2.a31 << "  " << Mat4Mat2.a32 << "  " << Mat4Mat2.a33 << "  " << Mat4Mat2.a34 << " |" << std::endl;
	std::cout << "| " << Mat4Mat2.a41 << "  " << Mat4Mat2.a42 << "  " << Mat4Mat2.a43 << "  " << Mat4Mat2.a44 << " |" << std::endl;

	Matrix4 Mat4Test1 = (Mat4Mat1 + Mat4Mat2);
	std::cout << "Matrix 1 + Matrix 2" << std::endl;
	std::cout << "| " << Mat4Test1.a11 << "  " << Mat4Test1.a12 << "  " << Mat4Test1.a13 << "  " << Mat4Test1.a14 << " |" << std::endl;
	std::cout << "| " << Mat4Test1.a21 << "  " << Mat4Test1.a22 << "  " << Mat4Test1.a23 << "  " << Mat4Test1.a24 << " |" << std::endl;
	std::cout << "| " << Mat4Test1.a31 << "  " << Mat4Test1.a32 << "  " << Mat4Test1.a33 << "  " << Mat4Test1.a34 << " |" << std::endl;
	std::cout << "| " << Mat4Test1.a41 << "  " << Mat4Test1.a42 << "  " << Mat4Test1.a43 << "  " << Mat4Test1.a44 << " |" << std::endl;

	Matrix4 Mat4Test2 = (Mat4Mat1 - Mat4Mat2);
	std::cout << "Matrix 2 - Matrix 1" << std::endl;
	std::cout << "| " << Mat4Test2.a11 << "  " << Mat4Test2.a12 << "  " << Mat4Test2.a13 << "  " << Mat4Test2.a14 << " |" << std::endl;
	std::cout << "| " << Mat4Test2.a21 << "  " << Mat4Test2.a22 << "  " << Mat4Test2.a23 << "  " << Mat4Test2.a24 << " |" << std::endl;
	std::cout << "| " << Mat4Test2.a31 << "  " << Mat4Test2.a32 << "  " << Mat4Test2.a33 << "  " << Mat4Test2.a34 << " |" << std::endl;
	std::cout << "| " << Mat4Test2.a41 << "  " << Mat4Test2.a42 << "  " << Mat4Test2.a43 << "  " << Mat4Test2.a44 << " |" << std::endl;

	Matrix4 Mat4Test3 = Mat4Mat1 * Mat4Mat2;
	std::cout << "Matrix 1 * Matrix 2" << std::endl;
	std::cout << "| " << Mat4Test3.a11 << "  " << Mat4Test3.a12 << "  " << Mat4Test3.a13 << "  " << Mat4Test3.a14 << " |" << std::endl;
	std::cout << "| " << Mat4Test3.a21 << "  " << Mat4Test3.a22 << "  " << Mat4Test3.a23 << "  " << Mat4Test3.a24 << " |" << std::endl;
	std::cout << "| " << Mat4Test3.a31 << "  " << Mat4Test3.a32 << "  " << Mat4Test3.a33 << "  " << Mat4Test3.a34 << " |" << std::endl;
	std::cout << "| " << Mat4Test3.a41 << "  " << Mat4Test3.a42 << "  " << Mat4Test3.a43 << "  " << Mat4Test3.a44 << " |" << std::endl;
	*/

//	Mat2Mat1
//	Vec2Vec1
	


	system("pause");
}