#pragma once
//PIEZAS
#include"Peon.h"
#include"Torre.h"
#include"Caballo.h"
#include"Alfil.h"
#include"Dama.h"
#include"Rey.h"

//VISTA
#include"Vista.h"

class Visualizar_piezas
{
	Peon* peon;
	Torre* torre;
	Caballo* caballo;
	Alfil* alfil;
	Dama* dama;
	Rey* rey;

	Vista vista;
	
public:
	Visualizar_piezas();
	void Inicializa();
	void visualizar(unsigned char c);
	void Mover_vista();
};