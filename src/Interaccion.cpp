#include "Interaccion.h"




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


void Interaccion::Desplazar(Pieza& diosita, Pieza& pieza)
{
	pieza.posicion = diosita.posicion;
}


/*
#include"Interaccion.h"

Interaccion::Interaccion()
{
	aux_posicion.Set_vector(0, 0, 0);
	wait = 'w';
}

void Interaccion::Inicializa()
{
	aux_posicion.Set_vector(0, 0, 0);
	wait = 'w';
}


void Interaccion::Seleccionar(DIOSITA& diosita, Peon& p)
{
	if (diosita.posicion.x == p.posicion.x && diosita.posicion.y == p.posicion.y) //hacer sobrecarca de el operador == con vertor 3d posiccion
	{
	}

}

void Interaccion::Desplazar(DIOSITA& diosita, Peon& p)
{

	if (diosita.posicion.x != p.posicion.x || diosita.posicion.y != p.posicion.y)
	{
		p.posicion = diosita.posicion;
		}


}
*/
/*
void Interaccion::Seleccionar(DIOSITA& dio)
{

}
*/