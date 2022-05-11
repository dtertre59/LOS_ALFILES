#pragma once

#include"Pieza.h"

#include"Interaccion.h"

class DIOSITA :public Pieza
{
public:
	
	DIOSITA();
	void Inicializa();
	void Dibuja();

	void SetPosX(float x);
	void SetPosY(float y);
	float devPosx() { return posicion.x; }
	float devPosy() { return posicion.y; }
	//clases amigas
	//friend class Interaccion;
};