#include"Partida.h"

Partida::Partida()
{
	tablero = new Tablero;
	peon = new Peon[16];
	vacio = new Casilla_vacia[2];
	//caballo = new Caballo[2];
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

	vacio[0].Inicializa('b', 7 * 10, 4 * 10, 0);
	vacio[1].Inicializa('n', 0 * 10, 3 * 10, 0);
}

void Partida::Dibuja()
{
	//dibujar tablero
	tablero->Dibuja();
	caja.dibuja();

	//dibujar  peones
	for (int i = 0; i < 16; i++)
	{
		peon[i].Dibuja();
	}

	//dibujar damas y reyes
	for (int i = 0; i < 2; i++)
	{
		vacio[i].Dibuja();
	}

	//dibujar torres, caballos y alfiles
	for (int i = 0; i < 4; i++)
	{
		caballo.Dibuja();
		//los dibuja de torres, caballos y alfiles
	}
}