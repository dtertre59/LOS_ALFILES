#include"Partida.h"

Partida::Partida()
{
	tablero = new Tablero;
	peon = new Peon[16];

}

void Partida::Inicializa()
{
	tablero->Inicializa();

	//inicializar peones
	for (int i = 0; i < 16; i++)
	{
		if (i < 8) {
			peon[i].Inicializa('b', 6 * 10, i * 10, 0);
		}
		else {
			peon[i].Inicializa('n', 10, (i - 8) * 10, 0);
		}
	}

	//inicializar piezas vacias (futuros reyes)

}

void Partida::Dibuja()
{
	//dibujar tablero
	tablero->Dibuja();


	//dibujar  peones
	for (int i = 0; i < 16; i++)
	{
		peon[i].Dibuja();
	}

	//dibujar damas y reyes
	for (int i = 0; i < 2; i++)
	{
		//ALGO.dIBUJA
	}

	//dibujar torres, caballos y alfiles
	for (int i = 0; i < 4; i++)
	{
		//los dibuja de torres, caballos y alfiles
	}
}