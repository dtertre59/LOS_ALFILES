#pragma once

#include"Pieza.h"

class Torre: public Pieza
{
public:
	Torre();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	bool Movimiento(const Vector3d& muevo_a);
};