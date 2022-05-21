#pragma once
#include"Pieza.h"

class Casilla:public Pieza
{
public:
	Casilla();
	void Inicializa(unsigned char c,int x,int y);
	void Dibuja();
};

