#include "Casilla.h"
#include"freeglut.h"

void Casilla::Inicializa(unsigned char c,int x, int y)
{
	posicion.Set_vector(x, y, 0);
	color.Set_color(c);
	escala = 1;
}

void Casilla::Dibuja()
{

	glDisable(GL_LIGHTING);

	glColor3ub(color.rojo, color.verde, color.azul);

	glBegin(GL_POLYGON);
	glVertex3d(posicion.x + 5*escala, posicion.y - 5*escala, posicion.z);
	glVertex3d(posicion.x + 5*escala, posicion.y + 5*escala, posicion.z);
	glVertex3d(posicion.x - 5*escala, posicion.y + 5*escala, posicion.z);
	glVertex3d(posicion.x - 5*escala, posicion.y - 5*escala, posicion.z);
	glEnd();

	glEnable(GL_LIGHTING);
}
