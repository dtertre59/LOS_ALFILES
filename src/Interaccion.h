#pragma once

#include"Vector3d.h"
#include"ETSIDI.h"
#include"DIOSITA.h"
#include"Tablero.h"

//#include"Pieza.h"
//PIEZAS
#include"Peon.h"
#include"Rey.h"




class Interaccion
{
public:

	static Vector3d Seleccionar(Pieza& diosita);
	static void Desplazar(Pieza& diosita, Pieza& pieza);
	static bool Comprobar_movimiento(Pieza& diosita, Pieza& pieza);

	static void Comer(Vector3d pos_comer,Tablerito& tablerito);


};
