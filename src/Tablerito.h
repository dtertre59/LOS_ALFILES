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
	string Localizar_pieza(int x, int y);  //devuelve el id de la pe3iza
	string Localizar_pieza(char x, char y); //devuelve el id de la pieza
	string Localizar_pieza(Vector3d& mov);
	//Vector3d Localizar_pieza(Pieza& p);
	//Vector3d Localizar_pieza(string& dni_);

	int Comprobar_posicion_movimiento(Pieza& pieza, Vector3d move); //devuelve un numero segun lo que haya en la casilla

	int Comprobar_camino(Pieza& pieza, Vector3d move);

	int Comprobar_movimiento_completo(Pieza& pieza, Vector3d move);

	void Mover(string& pieza, char x, char y);
	void Mover(Pieza& pieza, Vector3d diosita_pos);
	//bool Mover(int x, int y, string& pieza);


	//te imprime el tablero por teclado
	ostream& to_string(ostream& o);


};

