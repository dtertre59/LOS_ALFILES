#pragma once

//PIEZAS

#include"Peon.h"
#include"Torre.h"
#include"Caballo.h"
#include"Alfil.h"



class Visualizar_piezas
{
	Peon* peon;
	Torre* torre;
	//Caballo* caballo;
	Alfil* alfil;
	
public:
	Visualizar_piezas();
	void visualizar(unsigned char c);
};