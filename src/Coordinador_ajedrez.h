#pragma once

#include"ETSIDI.h"
#include"Partida.h"

#include"Vista.h"
#include"Visualizar_piezas.h"

/////////////////
//PIEZAS

#include"Casilla.h"

#include"Peon.h"



class Coordinador_ajedrez
{
private:
	
	unsigned char pi;

protected:
	enum class Estado { INICIO, PARTIDA_M, VISTA_PIEZA, CONTROLES, PAUSA, EXIT };
	Estado estado;


	Partida *partida;
	Visualizar_piezas* visualizarp;
	Vista vista;


public:

	Coordinador_ajedrez();
	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char key);
	void mueve();
};




