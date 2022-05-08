#pragma once

#include"Pieza.h"

class Torre: public Pieza
{
public:
	Torre();
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void Mover(unsigned char c); 
};