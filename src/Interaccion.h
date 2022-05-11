#pragma once

#include"Vector3d.h"

#include"DIOSITA.h"


//#include"Pieza.h"
//PIEZAS
#include"Peon.h"
#include"Rey.h"

#include"Clase_Prueba.h"

class Interaccion
{
	
	//Vector3d aux_posicion;
	//unsigned char wait;
	

public:
	//Interaccion();
	//void Inicializa();
	//static void Seleccionar(DIOSITA& dio);
	//static void Desplazar(DIOSITA& diosita, Peon& p);
	
	//static void Seleccionar(Clase_Prueba& prueba);
	static void Seleccionar(Pieza& diosita, Pieza& pieza);
	static void Desplazar(Pieza& diosita, Pieza& pieza);

};
