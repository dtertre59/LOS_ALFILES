#pragma once

#include"Pieza.h"
#include "Tablero.h"
#include"Interaccion.h"

class DIOSITA :public Pieza, public Tablero{
public:
	int flagA;
	DIOSITA();
	void Inicializa();
	void Dibuja();
	void ColPieza();
	void SetPosX(float x);
	void SetPosY(float y);



	//clases amigas
	//friend class Interaccion;
};