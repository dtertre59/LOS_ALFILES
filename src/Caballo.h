#pragma once
#include "Color_RGB.h"
#include "Vector3d.h"

class Caballo
{
public:
	Vector3d posicion;
	Color_RGB color;
	float escala;
	int i0, j0;
	bool movimiento = false;

	Caballo();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char);
	void Dibuja();
	void Escala(unsigned char);
	void Mover(unsigned char);
	int pos_Movimiento(int,int);
	//int prox_movimiento(int,int);
};