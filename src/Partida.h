#pragma once
#include"Tablero.h"

//PIEZAS

#include"Peon.h"
#include"Torre.h"
#include"Alfil.h"
#include"Caballo.h"
#include "Dama.h"
#include "Rey.h"

#include"DIOSITA.h"

#include"Vista.h"

class Partida {
public:
	Tablero* tablero;
	Peon* peon;
	Caballo* caballo;
	Torre* torre;
	Alfil* alfil;
	Rey* rey;
	Dama* dama;

	DIOSITA* diosita;

	enum class Turno { BLANCAS, NEGRAS, CAMBIO};
	enum class IntroDatos { EJE_X, EJE_Y, ESPERA };
	enum class MovDatos { M_EJE_X, M_EJE_Y, M_ESPERA };

	Turno turno;
	IntroDatos introdatos;
	MovDatos movdatos;

	Vista vista;


	Partida();
	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char c);
	//void Mueve();
};