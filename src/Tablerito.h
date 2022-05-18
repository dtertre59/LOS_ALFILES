#pragma once
#include<iostream>

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

	int Comprobar_movimiento(int x, int y); //devuelve un numero segun lo que haya en la casilla

	bool Mover(char x, char y, string& pieza);
	//bool Mover(int x, int y, string& pieza);


	//te imprime el tablero por teclado
	ostream& to_string(ostream& o);


};

