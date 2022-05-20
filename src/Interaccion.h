#pragma once

#include"Vector3d.h"

#include"DIOSITA.h"
#include"Tablero.h"

//#include"Pieza.h"
//PIEZAS
#include"Peon.h"
#include"Rey.h"




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



	//static char Seleccionar(Pieza& diosita, Tablero& tab);
	static Vector3d Seleccionar(Pieza& diosita);
	static void Desplazar(Pieza& diosita, Pieza& pieza);
	static bool Comprobar_movimiento(Pieza& diosita, Pieza& pieza);
	static bool Comprobar_choque_piezas(Pieza& diosita, Pieza& pieza);
	static bool Comprobar_comer(Pieza& diosita, Pieza& pieza);


	//static bool Comprobar_camino(Pieza& diosita, Pieza& pieza);
};
