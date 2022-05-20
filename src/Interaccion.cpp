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
	ETSIDI::play("sonidos/mover.wav");
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
	/*
	Vector3d p = pieza.Get_pos();
	Vector3d d = diosita.Get_pos();
	Vector3d r =diosita.Get_pos()-pieza.Get_pos();
	int flag = 0;
	*/

	if (diosita.Get_pos() == pieza.Get_pos())
	{
		return 0;
	}
	else 
		return 1;
}


bool Interaccion::Comprobar_comer(Pieza& diosita, Pieza& pieza)
{
	if (pieza.color.bn == 1)
	{
		
	}
	return 1;
}














/*
bool Interaccion::Comprobar_camino(Pieza& diosita, Pieza& pieza)
{
	Vector3d p = pieza.Get_pos();
	Vector3d d = diosita.Get_pos();
	Vector3d r;
	r.Set_vector(0, 0, 0);
	r.x = d.x - p.x;
	r.y = d.y - p.y;
	int verificacion=0;

	if (r.y == 0 && r.x>0) //si
	{
		for (p.x; d.x; p.x + 10)
		{
			if (Comprobar_choque_piezas(diosita, pieza))
				verificacion = 1;
		}
	}
	else if (r.y == 0 && r.x < 0) //si
	{
		for (p.x; d.x; p.x - 10)
		{
			if (Comprobar_choque_piezas(diosita, pieza))
				verificacion = 1;
		}
	}
	else if (r.x == 0 && r.y>0) //si
	{
		for (p.y; d.y; p.y + 10)
		{
			if (Comprobar_choque_piezas(diosita, pieza))
				verificacion = 1;
		}
	}
	else if (r.x == 0 && r.y < 0)
	{
		for (p.y; d.y; p.y - 10)
		{
			if (Comprobar_choque_piezas(diosita, pieza))
				verificacion = 1;
		}
	}

	
	if (r.x == r.y && r.x > 0)
	{
		for (p.x, p.y; d.x, d.y; p.x + 10, p.y + 10)
		{
			verificacion = Comprobar_choque_piezas(diosita, pieza);
		}
	}
	if (r.x == -r.y && r.x > 0)
	{
		for (p.x, p.y; d.x, d.y; p.x + 10, p.y - 10)
		{
			verificacion =Comprobar_choque_piezas(diosita, pieza);
		}
	}
	if (r.x ==r.y && r.x < 0)
	{
		for (p.x, p.y; d.x, d.y; p.x - 10, p.y - 10)
		{
			verificacion =Comprobar_choque_piezas(diosita, pieza);
		}
	}
	if (r.x == -r.y && r.x < 0)
	{
		for (p.x, p.y; d.x, d.y; p.x - 10, p.y + 10)
		{
			verificacion =Comprobar_choque_piezas(diosita, pieza);
		}
	}
	
		
	if (verificacion == 1)
	{
		return 0;
	}
	else
		return 1;
	
}
*/






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



