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
void DIOSITA:: ColPieza() {
	int i = 0;
	int j = 0;
	if (posicion.x || posicion.y == 0.0)
	{
		if (posicion.x == 0.0)
		{
			j = (posicion.y / 10);
			i = (posicion.x);
		}
		else {
			i = (posicion.x / 10); j = (posicion.y);
		}
	}
	else {
		i = (posicion.x / 10);
		j = (posicion.y / 10);
	}
	if (tablerito[i][j] !='0')
	{
		flagA = 1;
	}
	else(flagA = 0);
	tablerito[i][j] = 'D';
}

