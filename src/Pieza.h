#pragma once
#include"Vector3d.h"
#include"Color_RGB.h"
#include<iostream>

using namespace std;

class Pieza
{
protected:

	//ATRIBUTOS
	Vector3d posicion;
	Color_RGB color;
	float escala;
	string dni;

public:

	//METODOS
	Pieza() : posicion(), color(), escala(1), dni("00000") {};
	void Set_color(unsigned char c);

	void Set_pos(Vector3d v) { posicion = v; }
	Vector3d Get_pos() { return posicion; }

	float devPosx() { return posicion.x; }
	float devPosy() { return posicion.y; }

	void Cambiar_dni(string s);

	void Cambiar_escala(float es);

	//funciones virtuales
	virtual bool Movimiento(const Vector3d&) { return 0; };
	virtual void Dibuja() = 0;
	
	//clases amigas
	friend class Interaccion;
	friend class Partida;
	friend class Tablerito;
};