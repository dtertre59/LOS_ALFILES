#pragma once
#include"Tablero.h"
#include"Reina.h"



class Partida {
public:
	Tablero* tablero;
	Reina* reina;

	Partida();
	void Inicializa();
	void Dibuja();
};