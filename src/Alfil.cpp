#include"Alfil.h"
#include"freeglut.h"

Alfil::Alfil()
{
	posicion.Set_vector(-1, 3, 0);
	color.Set_color('b');
	escala = 1;
}

void Alfil::Inicializa(unsigned char c, float x, float y, float z)
{
	posicion.Set_vector(x, y, z);
	color.Set_color(c);
	escala = 1;
}

void Alfil::Inicializa(unsigned char c)
{
	posicion.Set_vector(0,0,0);
	color.Set_color(c);
	escala = 1;
}


//PINTAR FIGURA

void Alfil::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);

	//formas geométricas
	
	glTranslatef(posicion.x, posicion.y, posicion.z+(escala*1));
	glutSolidTorus((escala*1), (escala * 3), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z+ (escala * 1)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 8));
	glutSolidTorus((escala * 0.75), (escala * 1.75), 25, 25);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 8)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 2));
	glutSolidCone((escala * 3), (escala * 8), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 2)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 10));
	glutSolidSphere((escala * 2), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 10)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 12.4));
	glutSolidSphere((escala * 0.95), 85, 85); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 12.4)));
}

void Alfil::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

//MOVER FIGURA CON TECLADO
/*
void Alfil::Mover(int x,int y)
{
	int npx, npy, j;

	//pieza blanca
	if (color.bn == 1)
	{
		npx = posicion.x - 10 * x;
		npy = posicion.y + 10 * y;

		if (x == y)
		{
			for (int i = -7, int j = -7; i < 8, j < 8; i++, j++)
			{
				if (x == y == i == j)
					if (npx > 00 && npx < 80)
						if (npy >= 00 && npy < 70)
						{
							x = x * (-1);
							posicion.MoverVect(10 * x, 10 * y, 0);
						}
			}
		}
	}

	// pieza negra
	if (color.bn == 2)
	{
		npx = posicion.x + 10 * x;
		npy = posicion.y - 10 * y;

		if (x == y)
		{
			for (int i = -7, int j = -7; i < 8, j < 8; i++, j++)
			{
				if (x == y == i == j)
					if (npx > 00 && npx < 80)
						if (npy >= 00 && npy < 70)
						{
							y = y * (-1);
							posicion.MoverVect(10 * x, 10 * y, 0);
						}
			}
		}
	}
}
*/