#pragma once

#include"ETSIDI.h"
#include"Partida.h"

#include"Vista.h"

//PIEZAS

#include"Pieza.h"
#include"Peon.h"


class Coordinador_ajedrez
{
private:
	
	Peon* peon;

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



