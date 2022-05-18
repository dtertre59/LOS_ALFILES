#include "Pieza.h"
/*
#include"Pieza.h"

void Gestor_dibuja(Pieza& pp)
{
	pp.Dibuja();
}
*/

void Pieza::Set_color(unsigned char c)
{
	color.Set_color(c);
}


void Pieza::Cambiar_dni(string s)
{
	dni = s;
}