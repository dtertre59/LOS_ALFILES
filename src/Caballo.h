#pragma once

#include"Pieza.h"


class Caballo:public Pieza
{
public:
	int i0, j0;
	bool movimiento = false;

	Caballo();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char);
	void Dibuja();
	void Escala(unsigned char);
	void Mover(unsigned char);
	int pos_Movimiento(int,int);
	//bool Movimiento(const Vector3d& muevo_a);
	//int prox_movimiento(int,int);
};