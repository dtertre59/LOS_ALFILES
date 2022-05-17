#include "Color_RGB.h"

Color_RGB::Color_RGB()
{
	rojo = 255;
	verde = 255;
	azul = 255;
	bn = 1;
}
void Color_RGB::Set_color(unsigned char  c)
{

	if (c == 'b')
	{
		rojo = 255;
		verde = 245;
		azul = 157;
		bn = 1;
	}else if (c == 'n')
	{
		rojo = 55;
		verde = 34;
		azul = 8;
		bn = 2;
	}
	//colores BASICOS
	else if (c == 'a')
	{
		rojo = 255;
		verde = 255;
		azul = 0;
	}
	else if(c=='v')
	{
		rojo = 0;
		verde = 255;
		azul = 0;
		bn = 1;
	}
	else if (c == 'c')
	{
		rojo = 0;
		verde = 255;
		azul = 255;
	}
	else if (c == 'A')
	{
		rojo = 0;
		verde = 0;
		azul = 255;
	}
	else if (c == 'm')
	{
		rojo = 200;
		verde = 0;
		azul = 200;
	}
	else if (c == 'r')
	{
		rojo = 255;
		verde = 0;
		azul = 0;
		bn = 2;

	}

	else
	{
		rojo = 255;
		verde = 255;
		azul = 255;
	}
}

unsigned char Color_RGB:: Get_color()
{
	float r = rojo;
	float g = verde;
	float b = azul;
	return r, g, b;
}