#pragma once

#include"ETSIDI.h"
#include"Partida.h"

#include"Vista.h"

//PIEZAS

#include"Peon.h"
#include"Casilla.h"



class Coordinador_ajedrez
{
private:
	
	unsigned char pi;
	Peon peon;
	Casilla casilla;

protected:
	enum class Estado { INICIO, PARTIDA_M, VISTA_PIEZA, CONTROLES, PAUSA, EXIT };
	Estado estado;


	Partida *partida;
	Vista vista;


public:

	Coordinador_ajedrez();
	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char key);
};




