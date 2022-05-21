#pragma once
#include"Pieza.h"


class Caballo:public Pieza
{
public:

	Caballo();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char);
	void Dibuja();
	void Escala(unsigned char);
	void Mover(unsigned char);
	bool Movimiento(const Vector3d& muevo_a);
};