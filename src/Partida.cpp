#include"Partida.h"

Partida::Partida()
{
	tablero = new Tablero;
	reina = new Reina;
}

void Partida::Inicializa()
{
	tablero->Inicializa();
	reina->Inicializa('n');

}

void Partida::Dibuja()
{
	tablero->Dibuja();
	reina->Dibuja();
}