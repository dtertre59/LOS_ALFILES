#pragma once
#include"Pieza.h"

class DIOSITA :public Pieza
{
public:

	DIOSITA();
	void Inicializa();
	void Dibuja();
	void SetPosX(float x);
	void SetPosY(float y);
};