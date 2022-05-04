#pragma once
#include "Pared.h"
class caja
{
public:
	caja();
	
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;
	Pared fondo;
	Pared principio;
	void dibuja();

	friend class Interaccion;
};
