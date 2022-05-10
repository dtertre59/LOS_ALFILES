#include "Color_RGB.h"

Color_RGB::Color_RGB()
{
	rojo = 255;
	verde = 255;
	azul = 255;
	bn = 'a';
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
<<<<<<< HEAD
	}else if(c=='v')
	{
		rojo = 0;
		verde = 255;
		azul = 0;
	}
	else
=======
		bn = 0;
	}else
>>>>>>> 650e197840c094e43703eaa57d827973be7fdd36
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