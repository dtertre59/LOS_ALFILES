#include"Tablero.h"

Tablero::Tablero()
{
	pcasilla = new Casilla * [8];

	for (int i = 0; i < 8; i++)
	{
		pcasilla[i] = new Casilla[8];
	}


	for (int j = 0; j < 8; j++)
	{
		for (int k = 0; k < 8; k++)
		{
			if ((k + j) % 2 == 0) // % sireve para sacar el residuo de la division
			{
				pcasilla[j][k].Inicializa('b', j * 10, k * 10);

			}
			else
			{
				pcasilla[j][k].Inicializa('n', j * 10, k * 10);
			}
		}
	}
}

void Tablero::Inicializa()
{
	pcasilla = new Casilla*[8];

	for (int i = 0; i < 8; i++)
	{
		pcasilla[i] = new Casilla[8];
	}


	for (int j = 0; j < 8; j++)
	{
		for (int k = 0; k < 8; k++)
		{
			if ((k + j) % 2 == 0) // % sireve para sacar el residuo de la division
			{
				pcasilla[j][k].Inicializa('b', j*10, k*10);
			}
			else
			{
				pcasilla[j][k].Inicializa('n', j*10, k*10);
			}
		}
	}
}

void Tablero::Dibuja()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			pcasilla[i][j].Dibuja();
		}
	}
}
