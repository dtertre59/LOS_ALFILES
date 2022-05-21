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

	dni[0] = c - 32;
	dni[1] = 'A';
	if (y == 20)
		dni[2] = '1';
	else
		dni[2] = '2';

	//fila
	if (x == 70)
		dni[3] = '1';
	else
		dni[3] = '8';

	//columna
	if (y == 20)
		dni[4] = 'C';
	else
		dni[4] = 'F';

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

bool Alfil::Movimiento(const Vector3d& muevo_a)
{
	int npx, npy;
	int flag = 0;

	npx = muevo_a.x;
	npy = muevo_a.y;
	int x = muevo_a.x - posicion.x;
	int y = muevo_a.y - posicion.y;
	
	if (x == y)
	{
		flag = 1;
	}
	else if (x == -y)
	{
		flag = 1;
	}
		
	
	if (flag == 1)
	{
		return 1;
	}
	else
		return 0;
	
}