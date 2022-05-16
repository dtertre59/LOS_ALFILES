#include "Interaccion.h"

//te devuelve la posicion seleccionada. falta comprobar si la posiccion seleccionada tiene alguna pieza
Vector3d Interaccion::Seleccionar(Pieza& diosita)
{
	//Vector3d ini;
	//ini.Set_vector(35, 35, 5);


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


//solo puede ocurrir cuando el punto a donde lo desplazas es valido
void Interaccion::Desplazar(Pieza& diosita, Pieza& pieza)
{
	pieza.posicion = diosita.posicion;
}


//devuelve un 1 si el movimiento esta permitido y un 0 si no esta permitido

bool Interaccion::Comprobar_movimiento(Pieza& diosita, Pieza& pieza)
{
	bool verificacion;
	
	verificacion = pieza.Movimiento(diosita.Get_pos()); //si la pieza se puede mover donde diosita devuelve un 1
	return verificacion;
	
}
bool Interaccion::Comprobar_choque_piezas(Pieza& diosita, Pieza& pieza)
{
	
	if (diosita.Get_pos() == pieza.Get_pos())
	{
		return 0;
	}
	else 
		return 1;
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



