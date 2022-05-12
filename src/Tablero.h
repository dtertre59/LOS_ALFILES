#pragma once
#include"Casilla.h"

class Tablero 
{
protected:
	Casilla** pcasilla;
	char **tablerito;
public:	

	Tablero();
	void Inicializa();
	void Dibuja();
	//void InicializaT();
	friend class Interaccion;
};

