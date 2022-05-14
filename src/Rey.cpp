#include "Rey.h"
#include"freeglut.h"


Rey::Rey()
{
	posicion.Set_vector(-1, 3, 0);
	color.Set_color('b');
	escala = 1;
}

void Rey::Inicializa(unsigned char c, float x, float y, float z)
{
	posicion.Set_vector(x, y, z);
	color.Set_color(c);
	escala = 1;
}

void Rey::Inicializa(unsigned char c)
{
	posicion.Set_vector(0, 0, 0);
	color.Set_color(c);
	escala = 1;
}


//PINTAR FIGURA

void Rey::Dibuja()
{
	//color de la figura
	glColor3ub(color.rojo, color.verde, color.azul);

	//formas geométricas

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
	//glutSolidCone((escala * 2), (escala * 10), 40, 40); //   radio base, height, slices, stacks
	gluCylinder(gluNewQuadric(), escala * 2, escala * 1, escala * 5, 40, 40);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 10));
	glutSolidTorus((escala * 0.3), (escala * 1), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 10)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 10.5));
	glutSolidTorus((escala * 0.2), (escala * 1), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 10.5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 12.5));
	glutSolidCone((escala * -2), (escala * -4.5), 40, 40); //   radio base, height, slices, stacks
	//gluCylinder(gluNewQuadric(), escala * 1, escala * 2, escala * 2.4, 40, 40);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 12.5)));
	//Cruz
	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 12.5));
	glutSolidCube(escala * 0.4);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 12.5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 12.9));
	glutSolidCube(escala * 0.4);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 12.9)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 13.3));
	glutSolidCube(escala * 0.4);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 13.3)));

	glTranslatef(posicion.x + (escala * 0.4), posicion.y, posicion.z + (escala * 13.3));
	glutSolidCube(escala * 0.4);
	glTranslatef(-(posicion.x + (escala * 0.4)), -posicion.y, -(posicion.z + (escala * 13.3)));

	glTranslatef(posicion.x + (escala * -0.4), posicion.y, posicion.z + (escala * 13.3));
	glutSolidCube(escala * 0.4);
	glTranslatef(-(posicion.x + (escala * -0.4)), -posicion.y, -(posicion.z + (escala * 13.3)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 13.7));
	glutSolidCube(escala * 0.4);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 13.7)));
}

void Rey::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

//MOVER FIGURA CON TECLADO

bool Rey::pos_Movimiento(int i2, int j2)
{
	int i, j;
	i = posicion.x / 10;
	j = posicion.y / 10;
	int t = 0;
	bool mov = false;

	if ((i2 + i0 > 0 && i2 + i0 <= 7) && (j2 +j0 >= 0 && j2 +j0 <= 7))
	{

		i2 = i0 + i2;
		j2 = j0 + j2;
		mov = true;
	}
	/**
	//movimientos posibles	
	if ((i2 + 1 > 0 && i2 +1 <= 7) && (j2  >= 0 && j2  <= 7))
	{
		
		i2 = i0 +1;
		j2 = j0 ;
		mov = true;
	}
	if ((i2 +1 > 0 && i2 -1<= 7) && (j2 -1 >= 0 && j2 - 1 <= 7))
	{
		
		i2 = i0 + 1;
		j2 = j0 - 1;
		mov = true;
	}
	if ((i2 > 0 && i2 <= 7) && (j2 - 1 >= 0 && j2 - 1 <= 7))
	{
		
		i2 = i0;
		j2 = j0 - 1;
		mov = true;
	}
	if ((i2 - 1 > 0 && i2 - 1 <= 7) && (j2 + 1 >= 0 && j2 + 1 <= 7))
	{
		
		i2 = i0 - 1;
		j2 = j0 + 1;
		mov = true;
	}
	
	if ((i2 - 1 > 0 && i2 - 1 <= 7) && (j2  >= 0 && j2  <= 7))
	{
		
		i2 = i0 - 1;
		j2 = j0 ;
		mov = true;
	}
	if ((i2 - 1 > 0 && i2 - 1 <= 7) && (j2+ 1 >= 0 && j2 + 1 <= 7))
	{
		
		i2 = i0 - 1;
		j2 = j0 + 1;
		mov = true;
	}
	if ((i2  > 0 && i2  <= 7) && (j2 + 1 >= 0 && j2 + 1 <= 7))
	{
		
		i2 = i0 ;
		j2 = j0 + 1;
		mov = true;
	}
	if ((i2 + 1 > 0 && i2 + 1 <= 7) && (j2 + 1 >= 0 && j2 + 1 <= 7))
	{
		
		i2 = i0 + 1;
		j2 = j0 + 1;
		mov = true;
	}
	*/
	/*
	else
		movimiento = false;
		*/
	///i0 = i2;
	//j0 = j2;
	return mov;

}

void Rey::Mover(int x,int y)
{
	/*
	bool mov;
	if (posicion.x > 00 && posicion.x < 80)
		if (posicion.y > 00 && posicion.y < 70)
		{
			mov = pos_Movimiento(x, y);
			if(mov==true)
				posicion.MoverVect(-10 * x, 10 * y, 0);
		}
		*/
	int npx, npy;

	//movimiento normal
	if (color.bn == 1)
	{
		x = x * (-1);
		int difx = 10 * x;
		int dify = 10 * y;
		npx = posicion.x + difx; //nueva posicion
		npy = posicion.y + dify; //nueva posicion
		//movimiento 1/0
		if (difx == -10 && dify == 0)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10*y, 0);

		//movimiento 1/-1
		if (difx == -10 && dify == -10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento 0/-1
		if (difx == 0 && dify == 10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento -1/-1
		if (difx == 10 && dify == -10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento -1/0
		if (difx == 10 && dify == 0)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento -1/1
		if (difx == 10 && dify == 10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento 0/1
		if (difx == 0 && dify == 10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento 1/1
		if (difx == -10 && dify == 10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);
	}

	if (color.bn == 2)
	{
		y = y * (-1);
		int difx = 10 * x;
		int dify = 10 * y;
		npx = posicion.x + difx; //nueva posicion
		npy = posicion.y + dify; //nueva posicion
		//movimiento 1/0
		if (difx == 10 && dify == 0)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento 1/-1
		if (difx == 10 && dify == 10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento 0/-1
		if (difx == 0 && dify == 10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento -1/-1
		if (difx == -10 && dify == 10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento -1/0
		if (difx == -10 && dify == 0)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento -1/1
		if (difx == -10 && dify == -10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento 0/1
		if (difx == 0 && dify == -10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);

		//movimiento 1/1
		if (difx == 10 && dify == -10)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
					posicion.MoverVect(10 * x, 10 * y, 0);
	}
}
	