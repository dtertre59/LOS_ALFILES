#include "Interaccion.h"
#include "Tablerito.h"
#include <Partida.h>
#include"Peon.h"

//te devuelve la posicion seleccionada. falta comprobar si la posiccion seleccionada tiene alguna pieza
Vector3d Interaccion::Seleccionar(Pieza& diosita)
{
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
	ETSIDI::play("sonidos/mover.wav");
}

//devuelve un 1 si el movimiento esta permitido y un 0 si no esta permitido

bool Interaccion::Comprobar_movimiento(Pieza& diosita, Pieza& pieza)
{
	bool verificacion;
	
	verificacion = pieza.Movimiento(diosita.Get_pos()); //si la pieza se puede mover donde diosita devuelve un 1
	return verificacion;
	
}




//COMER PIEZAS
/*
void Interaccion::Seleccionar_Comer(Vector3d pos_mover, Tablerito& tab)
{
	
	int pos_x = pos_mover.x / 10;
	int pos_y = pos_mover.y / 10;
	
	string dni_pieza_comer = tab.Localizar_pieza(pos_mover);

	int num = dni_pieza_comer[2] - 49; //el peon 1 tiene dentro [0]


	
	
	if (dni_pieza_comer[1] == 'P')
	{
		


		
	}
	else if (dni_pieza_comer[1] == 'T')
	{
		
	}
	else if (dni_pieza_comer[1] == 'A')
	{
		
	}
	else if (dni_pieza_comer[1] == 'C')
	{
		
	}
	else if (dni_pieza_comer[1] == 'D')
	{
		
	}
		
}

*/