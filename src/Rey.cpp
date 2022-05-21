#include "Rey.h"
#include"freeglut.h"


Rey::Rey()
{
	posicion.Set_vector(-1, 3, 0);
	color.Set_color('b');
	escala = 1;
}

void Rey::Inicializa(unsigned char c, float x, float y, float z)
{
	posicion.Set_vector(x, y, z);
	color.Set_color(c);
	escala = 1;

	dni[0] = c - 32;
	dni[1] = 'R';
	dni[2] = '1';

	//fila
	if (x == 70)
		dni[3] = '1';
	else
		dni[3] = '8';
	//columna

	dni[4] = 'E';
}

void Rey::Inicializa(unsigned char c)
{
	posicion.Set_vector(0, 0, 0);
	color.Set_color(c);
	escala = 1;
}


//PINTAR FIGURA

void Rey::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);

	//formas geométricas

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1));
	glutSolidTorus((escala * 0.5), (escala * 4), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));


	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1));
	glutSolidCone((escala * 4), (escala * 7.5), 40, 40); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 5));
	glutSolidTorus((escala * 0.5), (escala * 2), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 5));
	gluCylinder(gluNewQuadric(), escala * 2, escala * 1, escala * 5, 40, 40);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 10));
	glutSolidTorus((escala * 0.3), (escala * 1), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 10)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 10.5));
	glutSolidTorus((escala * 0.2), (escala * 1), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 10.5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 12.5));
	glutSolidCone((escala * -2), (escala * -4.5), 40, 40); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 12.5)));
	//Cruz
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 12.5));
	glutSolidCube(escala * 0.4);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 12.5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 12.9));
	glutSolidCube(escala * 0.4);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 12.9)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 13.3));
	glutSolidCube(escala * 0.4);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 13.3)));

	glTranslatef(posicion.x , posicion.y + (escala * 0.4), posicion.z + (escala * 13.3));
	glutSolidCube(escala * 0.4);
	glTranslatef(-(posicion.x ), -(posicion.y + (escala * 0.4)), -(posicion.z + (escala * 13.3)));

	glTranslatef(posicion.x, posicion.y + (escala * -0.4), posicion.z + (escala * 13.3));
	glutSolidCube(escala * 0.4);
	glTranslatef(-(posicion.x ), -(posicion.y + (escala * -0.4)), -(posicion.z + (escala * 13.3)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 13.7));
	glutSolidCube(escala * 0.4);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 13.7)));
}

void Rey::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}


//MOVIMIENTO DTERTRE59 ESTA MAL:FALTAN 4 OPCIONES APRENDE A JUGAR AL AJEDREZ SALUDOS

bool Rey::Movimiento(const Vector3d& muevo_a)
{
	int flag = 0;
	int npx = muevo_a.x;
	int npy = muevo_a.y;
	int x = muevo_a.x - posicion.x;
	int y = muevo_a.y - posicion.y;

	//movimientos posibles -2/-1
	if (x == -10 && y == 0)
	{
		if (npx >= 00 && npx < 80)
			if (npy >= 00 && npy <= 70)
			{
				flag = 1;;
			}
	}
	if (x == -10 && y == -10)
	{
		if (npx >= 00 && npx < 80)
			if (npy >= 00 && npy <= 70)
			{
				flag = 1;;
			}
	}
	if (x == -10 && y == 10)
	{
		if (npx >= 00 && npx < 80)
			if (npy >= 00 && npy <= 70)
			{
				flag = 1;;
			}
	}
	if (x == 0 && y == -10)
	{
		if (npx >= 00 && npx < 80)
			if (npy >= 00 && npy <= 70)
			{
				flag = 1;;
			}
	}
	if (x == 0 && y == 10)
	{
		if (npx >= 00 && npx < 80)
			if (npy >= 00 && npy <= 70)
			{
				flag = 1;;
			}
	}
	if (x == 10 && y == -10)
	{
		if (npx >= 00 && npx < 80)
			if (npy >= 00 && npy <= 70)
			{
				flag = 1;;
			}
	}
	if (x == 10 && y == 0)
	{
		if (npx >= 00 && npx < 80)
			if (npy >= 00 && npy <= 70)
			{
				flag = 1;;
			}
	}
	if (x == 10 && y == 10)
	{
		if (npx >= 00 && npx < 80)
			if (npy >= 00 && npy <= 70)
			{
				flag = 1;;
			}
	}
	if (flag == 1)
	{
		return 1;
	}
	else
		return 0;
}