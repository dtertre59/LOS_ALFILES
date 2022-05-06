#pragma once
#include"Tablero.h"

//PIEZAS

#include"Peon.h"
#include"Torre.h"
#include"Alfil.h"
#include"Caballo.h"

class Partida {
public:
	Tablero* tablero;
	Peon* peon;

	enum class Turno{ BLANCAS, NEGRAS, };
	enum class IntroDatos{ EJE_X, EJE_Y};

	Turno turno;
	IntroDatos introdatos;


	Partida();
	void Inicializa();
	void Dibuja();
};