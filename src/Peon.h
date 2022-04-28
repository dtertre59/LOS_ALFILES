#pragma once

#include"Pieza.h"

class Peon:public Pieza
{
public:
	/*
	Vector3d posicion;
	Color_RGB color;
	float escala;
	*/
	Peon();
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void Mover(unsigned char c);
};
