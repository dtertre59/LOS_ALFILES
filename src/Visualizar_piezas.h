#pragma once

//PIEZAS

#include"Peon.h"
#include"Alfil.h"
#include"Torre.h"



class Visualizar_piezas
{
	Peon* peon;
	Alfil* alfil;
	Torre* torre;
public:
	Visualizar_piezas();
	void visualizar(unsigned char c);
};