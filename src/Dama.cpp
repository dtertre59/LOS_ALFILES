#include"Dama.h"
#include"freeglut.h"


Dama::Dama()
{
	posicion.Set_vector(-1, 3, 0);
	color.Set_color('b');
	escala = 1;
}
void Dama::Inicializa(unsigned char c, float x, float y, float z)
{
	posicion.Set_vector(x, y, z);
	color.Set_color(c);
	escala = 1;
}

void Dama::Inicializa(unsigned char c)
{
	posicion.Set_vector(0,0,0);
	color.Set_color(c);
	escala = 1;
}


//PINTAR FIGURA

void Dama::Dibuja()
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
	glutSolidCone((escala * 2), (escala * 10), 40, 40); //   radio base, height, slices, stacks
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

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 12.5));
	glutSolidSphere((escala * 1), 40, 40); //   radio, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 12.5)));

}

void Dama::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

//MOVER FIGURA CON TECLADO

void Dama::Mover(unsigned char c)
{
	if (c == 'i')
	{
		posicion.x = posicion.x - 0.25;
	}
	if (c == 'k')
	{
		posicion.x = posicion.x + 0.25;
	}
	if (c == 'j')
	{
		posicion.y = posicion.y - 0.25;
	}
	if (c == 'l')
	{
		posicion.y = posicion.y + 0.25;
	}
}