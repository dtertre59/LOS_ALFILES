#include"Reina.h"
#include"freeglut.h"


Reina::Reina()
{
	posicion.Set_vector(0, 0, 0);
	color.Set_color('b');
	escala = 1;
}


void Reina::Inicializa(unsigned char c)
{
	posicion.Set_vector(0,0,0);
	color.Set_color(c);
	escala = 1;
}


//PINTAR FIGURA

void Reina::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);

	//formas geométricas
	
	glTranslatef(posicion.x, posicion.y, posicion.z+(escala*1));
	glutSolidTorus((escala*1), (escala * 3), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z+ (escala * 1)));


	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 2));
	glutSolidCone((escala * 3), (escala * 6), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 2)));


	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 8));
	glutSolidSphere((escala * 2), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 8)));
}

void Reina::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

//MOVER FIGURA CON TECLADO

void Reina::Mover(unsigned char c)
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