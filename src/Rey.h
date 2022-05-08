#pragma once

#include"Pieza.h"

class Rey : public Pieza
{
public:

	Rey();
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void Mover(unsigned char c);
};

