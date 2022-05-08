#pragma once
#include"Tablero.h"

//PIEZAS

#include"Peon.h"
#include"Torre.h"
#include"Alfil.h"
#include"Caballo.h"
#include "Dama.h"
#include "Rey.h"

class Partida {
public:
	Tablero* tablero;
	Peon* peon;
	Caballo* caballo;
	Torre* torre;
	Alfil* alfil;
	Rey* rey;
	Dama* dama;

	enum class Turno { BLANCAS, NEGRAS, };
	enum class IntroDatos { EJE_X, EJE_Y };

	Turno turno;
	IntroDatos introdatos;


	Partida();
	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char c);
};