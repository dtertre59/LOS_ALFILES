#pragma once

#include"Pieza.h"

class Rey : public Pieza
{
public:
	Rey();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	bool Movimiento(const Vector3d& muevo_a);
};

