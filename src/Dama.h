#pragma once
#include"Pieza.h"

class Dama : public Pieza
{
public:
	
	Dama();
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void Mover(unsigned char c);
};