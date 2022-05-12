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

	//crear  tablerito vacio
	tablerito = new char* [8];
	for (int i = 0; i < 8; i++)
	{
		tablerito[i] = new char[8];

	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablerito[i][j] = '0';
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



	//inicializar  tablerito con las fichas en sus posiciones

	for (int i = 0; i < 8; i++)
	{
		tablerito[6][i] = 'p';
		tablerito[1][i] = 'p';
	}
	tablerito[7][4] = 'r';
	tablerito[0][4] = 'r';
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

/*
void Tablero::InicializaT()
{
	tablerito= new float * [8];
	for (int i = 0; i < 8; i++)
		{
			tablerito[i] = new float[8];
		
		}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablerito[i][j]=0.0;
		}
	}
}
*/
