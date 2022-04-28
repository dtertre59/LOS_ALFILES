#pragma once
#include"Vector3d.h"
#include"Color_RGB.h"

class Casilla
{
public:
	Vector3d posicion;
	Color_RGB color;
	float escala;

	void Inicializa(unsigned char c,int x,int y);
	void Dibuja();
};

