#pragma once
#include"Vector3d.h"
#include"ETSIDI.h"
#include"DIOSITA.h"

class Interaccion
{
public:

	static Vector3d Seleccionar(Pieza& diosita);
	static void Desplazar(Pieza& diosita, Pieza& pieza);
	static bool Comprobar_movimiento(Pieza& diosita, Pieza& pieza);
};
