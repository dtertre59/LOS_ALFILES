#pragma once
#include "Vector3d.h"
class Pared
{
public:
	Pared();
	
	Vector3d limite1;
	Vector3d limite2;
	void dibuja();
	void setColor(unsigned char, unsigned char, unsigned char);
	void setPos(float,float,float,float);
	//float distancia(Vector2D punto, Vector2D* direccion = 0);
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
};