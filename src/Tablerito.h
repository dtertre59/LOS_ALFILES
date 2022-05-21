#pragma once
#include<iostream>
#include"Vector3d.h"
#include"Pieza.h"

using namespace std;

class Tablerito
{
protected:
	string** tablerito;

public:

	Tablerito();
	void Inicializa();

	//devuelve de dni de la pieza que se encuentra el la posicion que metes
	string Localizar_pieza(int x, int y);
	string Localizar_pieza(char x, char y);
	string Localizar_pieza(Vector3d& mov);

	//devuelven diferntew valores segun el tipo de movimiento y si esta permitido o no
	int Comprobar_posicion_movimiento(Pieza& pieza, Vector3d move);
	int Comprobar_camino(Pieza& pieza, Vector3d move);
	int Comprobar_movimiento_completo(Pieza& pieza, Vector3d move);

	void Mover(string& pieza, char x, char y);
	void Mover(Pieza& pieza, Vector3d diosita_pos);

	//imprime el tablero por teclado
	ostream& to_string(ostream& o);
};

