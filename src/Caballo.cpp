#include "Caballo.h"
#include "freeglut.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Color_RGB.h"


Caballo::Caballo()
{
	//
}

void Caballo::Inicializa(unsigned char c)
{
	posicion.Set_vector(0, 0, 0);
	color.Set_color(c);
	escala =1;
	if (c == 'b')
	{
		i0 = 2;
		j0 = 1;
	}
	if (c == 'n')
	{
		//glRotatef(180, 0, 0, 1);
		i0 = 2;
		j0 = 8;
		
		//glRotatef(-180, 0, 0,- 1);
	}

}

void Caballo::Dibuja()
{
	/*
	color;
	if (color=color.Get_color = (109, 76, 65))
	{
		glRotatef(180, 0, 0, 1);
	}
	*/
	glColor3ub(color.rojo, color.verde, color.azul);
	//glRotatef(180, 0,0 , 1);
	//base toroide
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1));
	glutSolidTorus(escala * 0.5, escala * 3, 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	//cuerpo cono
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1));
	glutSolidCone(escala*3, escala*6, 100, 100);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	// segunda bse toroide
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 3.5));
	glutSolidTorus(escala * 0.35, escala * 2, 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 3.5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 4));
	glutSolidTorus(escala * 0.25, escala * 1.9, 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 4)));
	

	//base cubo cuerpo caballo
	glTranslatef(posicion.x , posicion.y, posicion.z + (escala * 5.1));
	glutSolidCube(3*escala);
	glTranslatef(-posicion.x , -posicion.y, -(posicion.z + (escala *5.1)));

	//cabeza caballo
	glTranslatef(posicion.x + (escala * (-1.5)), posicion.y, posicion.z + (escala * 8.1));
	glutSolidCube(3*escala);
	glTranslatef(-(posicion.x + (escala * (-1.5))), -(posicion.y ), -(posicion.z + (escala * 8.1)));

	//nuca caballo/pelo
	glTranslatef(posicion.x + (escala * (0.75)), posicion.y+(escala*(-0.75)), posicion.z + (escala * 7.25));
	glutSolidCube(1.5*escala);
	glTranslatef(-(posicion.x + (escala * (0.75))), -(posicion.y+(escala * (-0.75))), -(posicion.z + (escala * 7.25)));

	glTranslatef(posicion.x + (escala * (0.75)), posicion.y + (escala * (0.75)), posicion.z + (escala * 7.25));
	glutSolidCube(1.5 * escala);
	glTranslatef(-(posicion.x + (escala * (0.75))), -(posicion.y + (escala * (0.75))), -(posicion.z + (escala * 7.25)));
	

	glTranslatef(posicion.x + (escala * (0.375)), posicion.y + (escala * (-0.375)), posicion.z + (escala * 8.25));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (0.375))), -(posicion.y + (escala * (-0.375))), -(posicion.z + (escala * 8.25)));

	glTranslatef(posicion.x + (escala * (0.375)), posicion.y + (escala * (0.375)), posicion.z + (escala * 8.25));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (0.375))), -(posicion.y + (escala * (0.375))), -(posicion.z + (escala * 8.25)));

	glTranslatef(posicion.x + (escala * (0.375)), posicion.y + (escala * (-1.125)), posicion.z + (escala * 8.25));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (0.375))), -(posicion.y + (escala * (-1.125))), -(posicion.z + (escala * 8.25)));

	glTranslatef(posicion.x + (escala * (0.375)), posicion.y + (escala * (1.125)), posicion.z + (escala * 8.25));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (0.375))), -(posicion.y + (escala * (1.125))), -(posicion.z + (escala * 8.25)));


	//morro caballo/boca
	
	glTranslatef(posicion.x + (escala * (-3.75)), posicion.y+(escala*(-0.75)), posicion.z + (escala * 6.6));
	glutSolidCube(1.5 * escala);
	glTranslatef(-(posicion.x + (escala * (-3.75))), -(posicion.y + (escala * (-0.75))), -(posicion.z + (escala * 6.6)));

	glTranslatef(posicion.x + (escala * (-3.75)), posicion.y + (escala * (0.75)), posicion.z + (escala * 6.6));
	glutSolidCube(1.5 * escala);
	glTranslatef(-(posicion.x + (escala * (-3.75))), -(posicion.y + (escala * (0.75))), -(posicion.z + (escala * 6.6)));
	
	glTranslatef(posicion.x + (escala * (-3.75)), posicion.y + (escala * (-0.75)), posicion.z + (escala * 7.35));
	glutSolidCube(1.5 * escala);
	glTranslatef(-(posicion.x + (escala * (-3.75))), -(posicion.y + (escala * (-0.75))), -(posicion.z + (escala * 7.35)));

	glTranslatef(posicion.x + (escala * (-3.75)), posicion.y + (escala * (0.75)), posicion.z + (escala * 7.35));
	glutSolidCube(1.5 * escala);
	glTranslatef(-(posicion.x + (escala * (-3.75))), -(posicion.y + (escala * (0.75))), -(posicion.z + (escala * 7.35)));


	glTranslatef(posicion.x + (escala * (-4.5)), posicion.y + (escala * (-0.75)), posicion.z + (escala * 6.6));
	glutSolidCube(1.5 * escala);
	glTranslatef(-(posicion.x + (escala * (-4.5))), -(posicion.y + (escala * (-0.75))), -(posicion.z + (escala * 6.6)));

	glTranslatef(posicion.x + (escala * (-4.5)), posicion.y + (escala * (0.75)), posicion.z + (escala * 6.6));
	glutSolidCube(1.5 * escala);
	glTranslatef(-(posicion.x + (escala * (-4.5))), -(posicion.y + (escala * (0.75))), -(posicion.z + (escala * 6.6)));

	//mas morro caballo
	glTranslatef(posicion.x + (escala * (-3.375)), posicion.y + (escala * (-0.375)), posicion.z + (escala * 8.475));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (-3.375))), -(posicion.y + (escala * (-0.375))), -(posicion.z + (escala * 8.475)));

	glTranslatef(posicion.x + (escala * (-3.375)), posicion.y + (escala * (0.375)), posicion.z + (escala * 8.475));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (-3.375))), -(posicion.y + (escala * (0.375))), -(posicion.z + (escala * 8.475)));

	glTranslatef(posicion.x + (escala * (-3.375)), posicion.y + (escala * (-1.125)), posicion.z + (escala * 8.475));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (-3.375))), -(posicion.y + (escala * (-1.125))), -(posicion.z + (escala * 8.475)));

	glTranslatef(posicion.x + (escala * (-3.375)), posicion.y + (escala * (1.125)), posicion.z + (escala * 8.475));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (-3.375))), -(posicion.y + (escala * (1.125))), -(posicion.z + (escala * 8.475)));

	//orejas caballo
	glTranslatef(posicion.x + (escala * (-0.75)), posicion.y+(escala*(-1)), posicion.z + (escala * 9.6));
	glutSolidCone(escala * 0.5, escala * 1.7, 100, 100);
	glTranslatef(-(posicion.x + (escala * (-0.75))), -(posicion.y + (escala * (-1))), -(posicion.z + (escala * 9.6)));

	glTranslatef(posicion.x + (escala * (-0.75)), posicion.y + (escala * (1)), posicion.z + (escala * 9.6));
	glutSolidCone(escala * 0.5, escala * 1.7, 100, 100);
	glTranslatef(-(posicion.x + (escala * (-0.75))), -(posicion.y + (escala * (1))), -(posicion.z + (escala * 9.6)));

	//espalda caballo
	glTranslatef(posicion.x+(escala*1.875), posicion.y + (escala * (-0.375)), posicion.z + (escala * 6.975));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x+(escala*(1.875))), -(posicion.y + (escala * (-0.375))), -(posicion.z + (escala * 6.975)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (0.375)), posicion.z + (escala * 6.975));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (0.375))), -(posicion.z + (escala * 6.975)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (-1.125)), posicion.z + (escala * 6.975));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (-1.125))), -(posicion.z + (escala * 6.975)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (1.125)), posicion.z + (escala * 6.975));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (1.125))), -(posicion.z + (escala * 6.975)));


	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (-0.375)), posicion.z + (escala * 6.225));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (-0.375))), -(posicion.z + (escala * 6.225)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (0.375)), posicion.z + (escala * 6.225));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (0.375))), -(posicion.z + (escala * 6.225)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (-1.125)), posicion.z + (escala * 6.225));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (-1.125))), -(posicion.z + (escala * 6.225)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (1.125)), posicion.z + (escala * 6.225));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (1.125))), -(posicion.z + (escala * 6.225)));


	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (-0.375)), posicion.z + (escala * 5.475));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (-0.375))), -(posicion.z + (escala * 5.475)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (0.375)), posicion.z + (escala * 5.475));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (0.375))), -(posicion.z + (escala * 5.475)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (-1.125)), posicion.z + (escala * 5.475));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (-1.125))), -(posicion.z + (escala * 5.475)));

	glTranslatef(posicion.x + (escala * 1.875), posicion.y + (escala * (1.125)), posicion.z + (escala * 5.475));
	glutSolidCube(0.75 * escala);
	glTranslatef(-(posicion.x + (escala * (1.875))), -(posicion.y + (escala * (1.125))), -(posicion.z + (escala * 5.475)));


	//glRotatef(-180, 0,0 , 1);
}
void Caballo::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

void Caballo::Mover(unsigned char c)
{
	if (c == 'i')
	{
		posicion.x = posicion.x - 10;
	}
	if (c == 'k')
	{
		posicion.x = posicion.x + 10;
	}
	if (c == 'j')
	{
		posicion.y = posicion.y - 10;
	}
	if (c == 'l')
	{
		posicion.y = posicion.y + 10;
	}
}
int Caballo::pos_Movimiento(int i2, int j2)
{
	int posible=0;
	int i, j;
	int t = 0;

	//movimientos posibles	
	
	if ((i0 - 2 > 0 && i0 - 2 <= 7) && (j0 - 1 >= 0 && j0 - 1 <= 7)) 
	{ 
		posible++;
		i2 = i0 - 2;
		j2 = j0 - 1;
		movimiento = true;
	}
	if ((i0 - 2 > 0 && i0 - 2 <= 7) && (j0 + 1 >= 0 && j0 + 1 <= 7)) 
	{
		posible++;
		i2 = i0 - 2;
		j2 = j0 + 1;
		movimiento = true;
	}
	if ((i0 - 1 > 0 && i0 - 1 <= 7) && (j0 - 2 >= 0 && j0 - 2 <= 7))
	{
		posible++;
		i2 = i0 - 1;
		j2 = j0 - 2;
		movimiento = true;
	}
	if ((i0 - 1 > 0 && i0 - 1 <= 7) && (j0 + 2 >= 0 && j0 + 2 <= 7)) 
	{
		posible++;
		i2 = i0 - 1;
		j2 = j0 + 2;
		movimiento = true;
	}
	if ((i0 + 1 > 0 && i0 + 1 <= 7) && (j0 - 2 >= 0 && j0 - 2 <= 7))
	{
		posible++;
		i2 = i0 + 1;
		j2 = j0 - 2;
		movimiento = true;
	}
	if ((i0 + 1 > 0 && i0 + 1 <= 7) && (j0 + 2 >= 0 && j0 + 2 <= 7)) 
	{
		posible++;
		i2 = i0 + 1;
		j2 = j0 + 2;
		movimiento = true;
	}
	if ((i0 + 2 > 0 && i0 + 2 <= 7) && (j0 - 1 >= 0 && j0 - 1 <= 7))
	{
		posible++;
		i2 = i0 + 2;
		j2 = j0 - 1;
		movimiento = true;
	}
	if ((i0 + 2 > 0 && i0 + 2 <= 7) && (j0 + 1 >= 0 && j0 + 1 <= 7))
	{
		posible++;
		i2 = i0 + 2;
		j2 = j0 + 1;
		movimiento = true;
	}
	else
		movimiento = false;
	
	i0 = i2;
	j0 = j2;
	return posible;

}