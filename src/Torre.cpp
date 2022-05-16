#include"Torre.h"
#include"freeglut.h"

Torre::Torre()
{
	posicion.Set_vector(-1, 3, 0);
	color.Set_color('b');
	escala = 1;
}

void Torre::Inicializa(unsigned char c, float x, float y, float z)
{
	posicion.Set_vector(x, y, z);
	color.Set_color(c);
	escala = 1;
}
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

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 1.55));
	glutSolidTorus((escala * 1.5 - 0.35), (escala * 3 - 0.85), 40, 40);   //  innerRadius, outerRadius, sides, rings
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 1.55)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 2));
	glutSolidCone((escala * 3), (escala * 6), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 2)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 4.75));
	glutSolidCube(3.5);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 4.75)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 6.5));
	glutSolidCube(3.5);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 6.5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 6.5));
	glutSolidCone((escala * 1.5), (escala * 4), 100, 100); //   radio base, height, slices, stacks
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 6.5)));

	glTranslatef(posicion.x, posicion.y, posicion.z + (escala * 6.5)+3);
	glutSolidCube(3.5);
	glTranslatef(-posicion.x, -posicion.y, -(posicion.z + (escala * 6.5)+3));
	/// 
	glTranslatef(posicion.x, posicion.y+2, posicion.z + (escala * 6.5)+5);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -(posicion.y+2), -(posicion.z + (escala * 6.5)+5));

	glTranslatef(posicion.x, posicion.y + 2, posicion.z + (escala * 6.5) + 4);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 4));

	glTranslatef(posicion.x+2, posicion.y + 2, posicion.z + (escala * 6.5) + 5);
	glutSolidCube(1);
	glTranslatef(-(posicion.x+2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 5));

	glTranslatef(posicion.x+2, posicion.y + 2, posicion.z + (escala * 6.5) + 4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x+2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 4));

	glTranslatef(posicion.x + 2, posicion.y + 2, posicion.z + (escala * 6.5) + 3);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 3));

	glTranslatef(posicion.x + 2, posicion.y + 2, posicion.z + (escala * 6.5) + 2);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 2));

	glTranslatef(posicion.x + 2, posicion.y + 2, posicion.z + (escala * 6.5) + 1);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 1));

	glTranslatef(posicion.x + 2, posicion.y + 2, posicion.z + (escala * 6.5) );
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) ));

	glTranslatef(posicion.x + 2, posicion.y + 2, posicion.z + (escala * 6.5) -1);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) - 1));

	glTranslatef(posicion.x + 2, posicion.y + 2, posicion.z + (escala * 6.5) - 2);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) - 2));

	glTranslatef(posicion.x + 2, posicion.y + 2, posicion.z + (escala * 6.5) - 3);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) - 3));

	glTranslatef(posicion.x + 2, posicion.y + 2, posicion.z + (escala * 6.5) - 4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) -4));
	/// 

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) + 5);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 5));

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) + 4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 4));

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) + 3);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 3));

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) + 2);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 2));

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) + 1);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) + 1));

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) );
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) ));

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) - 1);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) - 1));

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) -2);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) -2));

	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) -3);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) -3)); 
	
	glTranslatef(posicion.x - 2, posicion.y + 2, posicion.z + (escala * 6.5) -4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y + 2), -(posicion.z + (escala * 6.5) -4));
	///
	glTranslatef(posicion.x, posicion.y - 2, posicion.z + (escala * 6.5) + 5);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 5));

	glTranslatef(posicion.x, posicion.y - 2, posicion.z + (escala * 6.5) + 4);
	glutSolidCube(1);
	glTranslatef(-posicion.x, -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 4));

	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) + 5);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 5));

	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) + 4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 4));

	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) + 3);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 3));
	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) + 2);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 2));
	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) + 1);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 1));

	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) );
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) ));

	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) - 1);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) - 1));

	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) -2);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5)-2));

	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) -3);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) -3));

	glTranslatef(posicion.x + 2, posicion.y - 2, posicion.z + (escala * 6.5) -4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) -4));
	/// 

	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) + 5);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 5));

	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) + 4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 4));

	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) + 3);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 3));
	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) + 2);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 2));
	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) + 1);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) + 1));
	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) );
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5)));
	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5)-1);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5)-1));
	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) - 2);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) - 2));
	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) - 3);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) - 3));
	glTranslatef(posicion.x - 2, posicion.y - 2, posicion.z + (escala * 6.5) - 4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y - 2), -(posicion.z + (escala * 6.5) - 4));
	///
	glTranslatef(posicion.x - 2, posicion.y , posicion.z + (escala * 6.5) + 5);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y ), -(posicion.z + (escala * 6.5) + 5));

	glTranslatef(posicion.x - 2, posicion.y , posicion.z + (escala * 6.5) + 4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x - 2), -(posicion.y ), -(posicion.z + (escala * 6.5) + 4));

	glTranslatef(posicion.x + 2, posicion.y, posicion.z + (escala * 6.5) + 5);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y), -(posicion.z + (escala * 6.5) + 5));

	glTranslatef(posicion.x + 2, posicion.y, posicion.z + (escala * 6.5) + 4);
	glutSolidCube(1);
	glTranslatef(-(posicion.x + 2), -(posicion.y), -(posicion.z + (escala * 6.5) + 4));
}
	



void Torre::Escala(unsigned char c)
{
	if (c == 'q')
		escala = escala * 1.2;
	if (c == 'e')
		escala = escala / 1.2;
}

//MOVER FIGURA CON TECLADO

bool Torre::Movimiento(const Vector3d& muevo_a)
{
	int npx, npy;
	int flag = 0;

	//if (color.bn == 1)
	
		npx = muevo_a.x;
		npy = muevo_a.y;
		int x = muevo_a.x - posicion.x;
		int y = muevo_a.y - posicion.y;
		if (x == 0 && y != 0)
		{
			//for (int i = -7; i < 8; i++)
			//{
				//if (i == y)
					if (npx > 00 && npx < 80)
						if (npy >= 00 && npy < 70)
						{
							flag = 1;;
						}
							
			//}
		}
	
		if (x != 0 && y == 0)
		{
			//for (int i = -7; i < 8; i++)
			//{
			//	if (i == x)
			if (npx > 00 && npx < 80)
				if (npy >= 00 && npy < 70)
				{
					flag=1;
				}
			//}
		}
		if (flag == 1)
		{
			return 1;
		}
		else
			return 0;
	

/*	if (color.bn == 2)
	{
		npx = muevo_a.x;
		npy = muevo_a.y;
		int x = muevo_a.x - posicion.x;
		int y = muevo_a.y - posicion.y;
		if (x == 0 && y != 0)
		{
			for (int i = 1; i < 8; i++)
			{
				if (i == y)
					if (npx > 00 && npx < 80)
						if (npy >= 00 && npy < 70)
						{
							flag = 1;
						}

			}
		}
		if (x != 0 && y == 0)
		{
			for (int i = 1; i < 8; i++)
			{
				if (i == x)
					if (npx > 00 && npx < 80)
						if (npy >= 00 && npy < 70)
						{
							flag = 1;
						}
			}
		}
	}*/
	
	
	
}
