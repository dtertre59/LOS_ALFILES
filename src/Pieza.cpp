#include "Pieza.h"

void Pieza::Set_color(unsigned char c)
{
	color.Set_color(c);
}

void Pieza::Cambiar_dni(string s)
{
	dni = s;
}

void Pieza::Cambiar_escala(float es) 
{ 
	escala = es; 
}