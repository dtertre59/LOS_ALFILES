#include"Vector3d.h"

Vector3d::Vector3d()
{
	x = y = z = 0;
}

void Vector3d::Set_vector(float equis,float i, float ceta)
{
	x = equis;
	y = i;
	z = ceta;
}

void Vector3d::Set_vector(Vector3d v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}



