#include"DIOSITA.h"
#include"freeglut.h"

DIOSITA::DIOSITA()
{
	posicion.Set_vector(7*10, 0, 0);
	color.Set_color('v');
	escala = 1;
}

void DIOSITA::Inicializa()
{

}

void DIOSITA::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);


	glTranslatef(posicion.x, posicion.y, posicion.z);
	glutSolidSphere((escala * 2), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z));
}

void DIOSITA::SetPosX(float x)
{
	posicion.x = x;
}

void DIOSITA::SetPosY(float y)
{
	posicion.y = y;
}

