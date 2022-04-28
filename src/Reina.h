#pragma once
#include"Vector3d.h"
#include"Color_RGB.h"

class Reina 
{
public:
	Vector3d posicion;
	Color_RGB color;
	float escala;

	Reina();
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void Mover(unsigned char c);
};