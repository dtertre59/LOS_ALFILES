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

void Vector3d::MoverVect(float xx, float yy, float zz)
{
	x += xx;
	y += yy;
	z += zz;
}


//FINCION INDEPENDIENTE SOBRECARGA DEL OPERADOR ==

bool operator==(const Vector3d& v1, const Vector3d& v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return 1;
	else
		return 0;
}

