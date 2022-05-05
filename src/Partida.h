#pragma once
#include"Tablero.h"

#include"Peon.h"
#include"Casilla_vacia.h"




class Partida {
public:
	Tablero* tablero;
	Peon* peon;
	Casilla_vacia* vacio;

	Partida();
	void Inicializa();
	void Dibuja();
};