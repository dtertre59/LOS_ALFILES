#pragma once
#include"Tablero.h"

#include"Peon.h"
#include"Casilla_vacia.h"
#include "Caballo.h"
#include "caja.h"




class Partida {
public:
	Tablero* tablero;
	Peon* peon;
	Casilla_vacia* vacio;
	Caballo caballo;
	caja caja;

	Partida();
	void Inicializa();
	void Dibuja();
};