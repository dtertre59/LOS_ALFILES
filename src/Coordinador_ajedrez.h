#pragma once

#include"ETSIDI.h"
#include"Partida.h"

#include"Vista.h"
#include"Reina.h"


class Coordinador_ajedrez
{
protected:
	enum class Estado { INICIO, JUEGO};
	Estado estado;


	/*
	Reina *r;
	Tablero t;
	*/

	Partida *partida;
	Vista vista;
public:

	Coordinador_ajedrez();
	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char key);
};