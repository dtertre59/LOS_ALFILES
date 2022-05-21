#include "Interaccion.h"

//te devuelve la posicion seleccionada
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

//Mueve la pieza donde esté Diosita
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