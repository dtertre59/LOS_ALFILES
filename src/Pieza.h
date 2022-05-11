#pragma once

#include"Vector3d.h"
#include"Color_RGB.h"

//#include"Interaccion.h"


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

	virtual void Dibuja()=0;
	virtual void ColPieza() {
		int i = 0;
	}
	//friend void Gestor_dibuja(Pieza&);

	friend class Interaccion;
};


