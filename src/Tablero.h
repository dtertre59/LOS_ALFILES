#pragma once
#include"Casilla.h"

class Tablero 
{
protected:
	Casilla** pcasilla;
public:	

	Tablero();
	void Inicializa();
	void Dibuja();
};

