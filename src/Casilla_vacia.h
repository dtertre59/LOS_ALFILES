#pragma once

#include"Pieza.h"

class Casilla_vacia :public Pieza
{
public:
	/*
	Vector3d posicion;
	Color_RGB color;
	float escala;
	*/
	Casilla_vacia();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void Mover(unsigned char c);
};
