#include "Color_RGB.h"


//CONSTRUCTOR
Color_RGB::Color_RGB()
{
	rojo = 255;
	verde = 255;
	azul = 255;
}

//COLOR DEPENDIENDO DE LA LETRA
void Color_RGB::Set_color(unsigned char  c)
{
	if (c == 'b')
	{
		rojo = 255;
		verde = 245;
		azul = 157;
	}
	else if (c == 'n')
	{
		rojo = 55;
		verde = 34;
		azul = 8;
	}
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
	}
	else
	{
		rojo = 255;
		verde = 255;
		azul = 255;
	}
}
