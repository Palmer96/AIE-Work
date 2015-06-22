#include <iostream>
#include "Object.h"
#include "MathLib.h"


Object::Object()
{
	Vector3 coords(0.0f, 0.0f, 0.0f);
	fRotation = 2.12;
}

Object::Object(Vector3 Vec)
{
	Vector3 coords(Vec.x, Vec.y, Vec.z);
}
 
void Object::UpdateTransform()
{
	transform = Matrix3();
	transform = transform.Translation(coords) * transform.Rotation(fRotation) * transform.Scale(coords);


}


Object::~Object()
{

}

//void Object::Move()
//{
//
//
//
//}
