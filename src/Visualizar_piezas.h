#pragma once

//PIEZAS

#include"Peon.h"
#include"Torre.h"
#include"Caballo.h"
#include"Alfil.h"
#include"Dama.h"
#include"Rey.h"




class Visualizar_piezas
{
	Peon* peon;
	Torre* torre;
	Caballo* caballo;
	Alfil* alfil;
	Dama* dama;
	Rey* rey;
	
public:
	Visualizar_piezas();
	void visualizar(unsigned char c);
};