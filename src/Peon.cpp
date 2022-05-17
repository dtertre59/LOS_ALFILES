#include"Peon.h"
#include"freeglut.h"
#include <math.h>
#include <stdlib.h>


Peon::Peon()
{
	posicion.Set_vector(-1, 3, 0);
	color.Set_color('b');
	escala = 1;
}


void Peon::Inicializa(unsigned char c, float x,float y,float z)
{
	posicion.Set_vector(x,y,z);
	color.Set_color(c);
	escala = 1;
}

void Peon::Inicializa(unsigned char c)
{
	posicion.Set_vector(0,0,0);
	color.Set_color(c);
	ColPieza();
	escala = 1;
}
void Peon::ColPieza()
{
	int i = 0;
	int j = 0;
	if (posicion.x||posicion.y == 0.0)
	{
		if (posicion.x == 0.0)
		{
			j = (posicion.y / 10);
			i = (posicion.x);
		}
		else { i = (posicion.x / 10); j = (posicion.y);
		}
	}
	else {
		 i = (posicion.x / 10);
		j = (posicion.y / 10);
	}
	tablerito[i][j] = 'P';
}


//PINTAR FIGURA

void Peon::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);

	//formas geométricas
	

	//base
	glTranslatef(posicion.x, posicion.y, posicion.z+(escala*1));
	glutSolidTorus((escala*1), (escala * 3), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z+ (escala * 1)));

	//cono
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 2));
	glutSolidCone((escala * 3), (escala * 6), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 2)));

	//esfera
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 8));
	glutSolidSphere((escala * 2), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 8)));
}

void Peon::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}



//MOVIMIENTO

bool Peon::Movimiento(const Vector3d& muevo_a)
{
	int flag = 0;
	int npx = muevo_a.x;
	int npy = muevo_a.y;
	int x = muevo_a.x - posicion.x;
	int y = muevo_a.y - posicion.y;
	if (color.bn == 1)
	{
		if (x == -10 && y == 0)
		{
			flag = 1;
		}
		else if (x == -20 && y == 0)
		{
			if(posicion.x==60)
			{
				flag = 1;
			}
		}
		else
			flag = 0;
	}
	if (color.bn == 2)
	{
		if (x == 10 && y == 0)
		{
			flag = 1;
		}
		if (x == 20 && y == 0)
		{
			if (posicion.x == 10)
			{
				flag = 1;
			}
		}
		else
			flag = 0;
	}
	if (flag == 1)
		return 1;
	else
		return 0;
}


























//MOVER FIGURA CON TECLADO

void Peon::Mover(int x,int y)
{
	int difx = -10 * x;
	int dify = 10 * y;
	int npx, npy;
	
	if (x >= 0)
	{
		if (color.bn ==1)
		{
			npx = posicion.x + difx; //nueva posicion
			npy = posicion.y + dify; //nueva posicion
			difx = abs(difx);
			dify = abs(dify);

			//movimiento normal
			if (difx == 10 && dify == 0)
				if (npx > 00 && npx < 80)
					if (npy >= 00 && npy < 70)
						posicion.MoverVect(-10 * x, 0, 0);


			//movimiento de inciio 2 casillas
			else if (difx == 20 && dify == 0)
				if (npx > 00 && npx < 80)
					if (npy >= 00 && npy < 70)
						posicion.MoverVect(-20 * x, 0, 0);



			//movimiento para comer
			else if (difx == 10 && dify == 10)
				if (npx > 00 && npx < 80)
					if (npy >= 00 && npy < 70)
						posicion.MoverVect(-10 * x, -10 * y, 0);
		}

		else if (color.bn == 2)
		{
			y = y*-1;
			npx = posicion.x - difx; //nueva posicion
			npy = posicion.y + dify; //nueva posicion
			difx = abs(difx);
			dify = abs(dify);

			//movimiento normal
			if (difx == 10 && dify == 0)
				if (npx > 00 && npx < 80)
					if (npy >= 00 && npy < 70)
						posicion.MoverVect(10 * x, 0, 0);


			//movimiento de inciio 2 casillas
			else if (difx == 20 && dify == 0)
			{
				if (posicion.x == 10)
					if (npx > 00 && npx < 80)
						if (npy >= 00 && npy < 70)
						{
							posicion.MoverVect(20 * x, 0, 0);
						}
			}
						

			//movimiento para comer
			else if (difx == 10 && dify == 10)
			{
				if (npx > 00 && npx < 80)
					if (npy >= 00 && npy < 70)
						posicion.MoverVect(10 * x, -10 * y, 0);
			}
									
		}
	}
	
	


	//falta distinguir peon blanco de negro para que solo se puedan mover hacia alante
	
	
	

}