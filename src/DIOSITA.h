#pragma once

#include"Pieza.h"

#include"Interaccion.h"

class DIOSITA :public Pieza, public Tablero
{
public:
	int flagA;
	DIOSITA();
	void Inicializa();
	void Dibuja();
	void ColPieza();
	void SetPosX(float x);
	void SetPosY(float y);
	float devPosx() { return posicion.x; }
	float devPosy() { return posicion.y; }
	//clases amigas
	//friend class Interaccion;
};