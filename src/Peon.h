#pragma once

#include"Pieza.h"
#include "Tablero.h"
#include"Interaccion.h"

class Peon :public Pieza,public Tablero
{
public:
	
	Peon();
	void Inicializa(unsigned char c, float x, float y, float z);
	void Inicializa(unsigned char c);
	void Dibuja();
	void Escala(unsigned char c);
	void ColPieza();


	bool Movimiento(const Vector3d& muevo_a); //dtertre59 prueba movimiento correcto
	

	void Mover(int x,int y); //funcion mover de lobo

	friend class Interaccion;
};
