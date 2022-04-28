#include"Partida.h"

Partida::Partida()
{
	tablero = new Tablero;
	peon = new Peon;
}

void Partida::Inicializa()
{
	tablero->Inicializa();
	peon->Inicializa('b');

}

void Partida::Dibuja()
{
	tablero->Dibuja();
	peon->Dibuja();
}