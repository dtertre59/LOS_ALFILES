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
	void Set_color(unsigned char c);

	void Set_pos(Vector3d v) { posicion= v; }
	Vector3d Get_pos() { return posicion; }

	float devPosx() { return posicion.x; }
	float devPosy() { return posicion.y; }




	virtual void Dibuja()=0;
	virtual void ColPieza() {
		int i = 0;
	}
	//friend void Gestor_dibuja(Pieza&);

	friend class Interaccion;
	friend class Partida;
};


