#pragma once

#include"Pieza.h"

class Rey : public Pieza
{
public:
	bool movimiento;
	int i0, j0;


	Rey();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);

	bool Movimiento(const Vector3d& muevo_a);


	//void Mover(int x,int y);
	//bool pos_Movimiento(int i2, int j2);
};

