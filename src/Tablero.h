#pragma once
#include"Casilla.h"

class Tablero 
{
protected:
	Casilla** pcasilla;
	float **tablerito;
public:	

	void Inicializa();
	void Dibuja();
	void InicializaT();
	
};

