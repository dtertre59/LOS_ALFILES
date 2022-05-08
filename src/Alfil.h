#pragma once

#include"Pieza.h"

class Alfil: public Pieza{
public:
	Alfil();
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void Mover(unsigned char c);
};