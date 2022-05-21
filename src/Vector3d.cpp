#include"Vector3d.h"

//CONSTRUCTOR INICIALIZA A 0
Vector3d::Vector3d()
{
	x = y = z = 0;
}

//SOBRECARGA DE LA FUNCION SET_VECTOR
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

float Vector3d::GetVect()
{
	return x;
	return y;
	return z;
}

//SOBRECARGA DEL OPERADOR - CON FUNCION MIEMBRO

Vector3d Vector3d:: operator - (Vector3d v)
{
	Vector3d res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
}


//FUNCION INDEPENDIENTE SOBRECARGA DEL OPERADOR ==

bool operator==(const Vector3d& v1, const Vector3d& v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return 1;
	else
		return 0;
}