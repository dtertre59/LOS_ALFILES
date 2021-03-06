#pragma once

#include"Pieza.h"
#include "Tablero.h"
#include"Interaccion.h"

class Peon :public Pieza
{
public:
	
	Peon();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	bool Movimiento(const Vector3d& muevo_a);
};
