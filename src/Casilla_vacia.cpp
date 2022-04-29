#include"Casilla_vacia.h"
#include"freeglut.h"


Casilla_vacia::Casilla_vacia()
{
	posicion.Set_vector(0, 0, 0);
	color.Set_color('b');
	escala = 1;
}

void Casilla_vacia::Inicializa(unsigned char c, float x, float y, float z)
{
	posicion.Set_vector(x, y, z);
	color.Set_color(c);
	escala = 1;
}

void Casilla_vacia::Inicializa(unsigned char c)
{
	posicion.Set_vector(0, 0, 0);
	color.Set_color(c);
	escala = 1;
}


//PINTAR FIGURA

void Casilla_vacia::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);

	//formas geométricas

	//esfera
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 2));
	glutSolidSphere((escala * 2), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 2)));
}

void Casilla_vacia::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

//MOVER FIGURA CON TECLADO

void Casilla_vacia::Mover(unsigned char c)
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