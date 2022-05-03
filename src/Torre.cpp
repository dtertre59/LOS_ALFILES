#include"Torre.h"
#include"freeglut.h"

void Torre::Inicializa(unsigned char c)
{
	posicion.Set_vector(0, 0, 0);
	color.Set_color(c);
	escala = 1;
}


//PINTAR FIGURA

void Torre::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);

	//formas geométricas

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1));
	glutSolidTorus((escala * 1), (escala * 3), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1)+0.55);
	glutSolidTorus((escala * 1.5-0.35), (escala * 3-0.85), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1));
	glutSolidCone((escala * 3), (escala * 6), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 2)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1)+3.75);
	glutSolidCube(3.5);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1) + 2.5);
	glutSolidCube(3.5);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z ));
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1));
	glutSolidCone((escala * 1.5), (escala * 4), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 2)));
	///////almenas
	glTranslatef(posicion.x, posicion.y+2, posicion.z + (escala * 1)+2);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)-1));

	glTranslatef(posicion.x, posicion.y , posicion.z+1);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));
	
	glTranslatef(posicion.x+2, posicion.y , posicion.z + (escala * 1)-1);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	
	glTranslatef(posicion.x -4, posicion.y, posicion.z + (escala * 1));
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	glTranslatef(posicion.x , posicion.y-2, posicion.z + (escala * 1));
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));
	glTranslatef(posicion.x, posicion.y - 2, posicion.z + (escala * 1));
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	glTranslatef(posicion.x+2, posicion.y , posicion.z + (escala * 1));
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));
	glTranslatef(posicion.x + 2, posicion.y, posicion.z + (escala * 1));
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));

	glTranslatef(posicion.x , posicion.y+2, posicion.z + (escala * 1));
	glutSolidCube(1);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1)));


}
	



void Torre::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

//MOVER FIGURA CON TECLADO

void Torre::Mover(unsigned char c)
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