#pragma once

#include<iostream>
#include"ETSIDI.h"
#include"Tablero.h"
#include"Vista.h"
#include"Interaccion.h"

#include "Pieza.h"

#include"Peon.h"
#include"Torre.h"
#include"Alfil.h"
#include"Caballo.h"
#include "Dama.h"
#include "Rey.h"

#include"DIOSITA.h"
#include"Tablerito.h"

using namespace std;

class Partida 
{
protected:
	Tablero* tablero;
	Peon* peon;
	Caballo* caballo;
	Torre* torre;
	Alfil* alfil;
	Rey* rey;
	Dama* dama;

	DIOSITA* diosita;
	Tablerito* tablerito;

	enum class Turno { BLANCAS, NEGRAS, CAMBIO,CAMBIO2,JAQUE_MATE};
	enum class IntroDatos { EJE_X, EJE_Y, ESPERA };
	enum class MovDatos { M_EJE_X, M_EJE_Y, M_ESPERA };

	Turno turno;
	IntroDatos introdatos;
	MovDatos movdatos;

	Vista vista;

	string pieza_selec; //BR
	string dni_pieza_selec; //BR11E

	int control_selccion_pieza; //para saber si ya se ha seleccionadado la ficha
	Vector3d posicion_pieza_seleccionada;

	int flag_seleccion_pieza;  //1 si la pieza ha sido seleccionada

	int flag_numero_pieza;  // enumeracion de las piezas  //los peones del 0 al 7
	
	int comi; //contador piezas comidas

public:

	Partida();
	~Partida();

	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char c);
	void Mueve();
	void Comida(string& dni_pieza_comer);
};