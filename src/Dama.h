#pragma once
#include"Pieza.h"

class Dama : public Pieza
{
public:
	
	Dama();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void Mover(int x,int y);
};