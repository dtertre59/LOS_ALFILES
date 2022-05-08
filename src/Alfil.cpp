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

void Alfil::Mover(unsigned char c)
{
	if (c == 'i')
	{
		posicion.x = posicion.x - 10.0;
	}
	if (c == 'k')
	{
		posicion.x = posicion.x + 10.0;
	}
	if (c == 'j')
	{
		posicion.y = posicion.y - 10.0;
	}
	if (c == 'l')
	{
		posicion.y = posicion.y + 10.0;
	}
}