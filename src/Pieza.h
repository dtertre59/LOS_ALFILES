#pragma once

#include"Vector3d.h"
#include"Color_RGB.h"

#include"Peon.h"

class Pieza 
{
protected:

	//ATRIBUTOS
	Vector3d posicion;
	Color_RGB color;
	float escala;

public:

	//METODOS
	Pieza() : posicion(), color(), escala(1) {};

	//virtual void Dibuja();

};

