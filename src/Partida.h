#pragma once
#include"Tablero.h"
#include"Peon.h"



class Partida {
public:
	Tablero* tablero;
	Peon* peon;

	Partida();
	void Inicializa();
	void Dibuja();
};