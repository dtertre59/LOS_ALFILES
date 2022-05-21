#include"Peon.h"
#include"freeglut.h"
#include <math.h>

Peon::Peon()
{
	posicion.Set_vector(-1, 3, 0);
	color.Set_color('b');
	escala = 1;
}

void Peon::Inicializa(unsigned char c, float x,float y,float z)
{
	posicion.Set_vector(x,y,z);
	color.Set_color(c);
	escala = 1;

	
	dni[0] = c-32;  //-32 para ponerlo en mayusculas
	dni[1] = 'P'; //P de peon
	if (y == 0)
		dni[2] = '1';   //numero de peon, segun la columna
	else
		dni[2] = (y / 10) + 49;

	//fila
	if (x == 60)
		dni[3] = '2';
	else
		dni[3] = '7';
	//columna

	dni[4] = dni[2] + 16;
	
}

void Peon::Inicializa(unsigned char c)
{
	posicion.Set_vector(0,0,0);
	color.Set_color(c);
	escala = 1;
}

//PINTAR FIGURA
void Peon::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);

	//formas geométricas	

	//base
	glTranslatef(posicion.x, posicion.y, posicion.z+(escala*1));
	glutSolidTorus((escala*1), (escala * 3), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z+ (escala * 1)));

	//cono
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 2));
	glutSolidCone((escala * 3), (escala * 6), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 2)));

	//esfera
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 8));
	glutSolidSphere((escala * 2), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 8)));
}

void Peon::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

//MOVIMIENTO
bool Peon::Movimiento(const Vector3d& muevo_a)
{
	int flag = 0;
	int npx = muevo_a.x;
	int npy = muevo_a.y;
	int x = muevo_a.x - posicion.x;
	int y = muevo_a.y - posicion.y;
	if (dni[0]=='B') //color blanco
	{
		if (x == -10 && y == 0)
		{
			flag = 1;
		}
		else if (x == -20 && y == 0)
		{
			if(posicion.x==60)
			{
				flag = 1;
			}
		}
		else if (x == -10 && y == -10)
		{
			flag = 1;
		}
		else if (x == -10 && y == 10)
		{
			flag = 1;
		}
		else
			flag = 0;
	}
	if (dni[0] == 'N') //color negro
	{
		if (x == 10 && y == 0)
		{
			flag = 1;
		}
		else if (x == 20 && y == 0)
		{
			if (posicion.x == 10)
			{
				flag = 1;
			}
		}
		else if (x == 10 && y == -10)
		{
			flag = 1;
		}
		else if (x == 10 && y == 10)
		{
			flag = 1;
		}
		
		else
			flag = 0;
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}