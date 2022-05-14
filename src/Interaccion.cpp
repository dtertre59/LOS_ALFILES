#include "Interaccion.h"


Vector3d Interaccion::Seleccionar(Pieza& diosita)
{
	Vector3d ini;
	ini.Set_vector(35, 35, 5);


	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i * 10 == diosita.posicion.x && j * 10 == diosita.posicion.y)
			{
				return diosita.posicion;
			}
		}
	}
}

/*
char Interaccion::Seleccionar(Pieza& diosita, Tablero& tab)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i * 10 == diosita.posicion.x && j * 10 == diosita.posicion.y)
			{
				return tab.tablerito[i][j];
			}
			else
				return '0';
		}
	}
}
*/


void Interaccion::Desplazar(Pieza& diosita, Pieza& pieza)
{
	pieza.posicion = diosita.posicion;
}

