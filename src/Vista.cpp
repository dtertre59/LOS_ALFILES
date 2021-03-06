#include"Vista.h"
#include"freeglut.h"
#include<math.h>

//CONSTRUCTORES VISTA

Vista::Vista() {
	
	posicion_ojo.Set_vector(140, 35, 40);
	mira_ojo.Set_vector(35, 35, 5);

	distancia = sqrt(posicion_ojo.x * posicion_ojo.x + posicion_ojo.y * posicion_ojo.y + posicion_ojo.z * posicion_ojo.z);
	distancia_plana = sqrt(posicion_ojo.x * posicion_ojo.x + posicion_ojo.y * posicion_ojo.y);
	angulo = atan2(posicion_ojo.z, distancia_plana);
	angulo_plano = atan2(posicion_ojo.y, posicion_ojo.x);

}

Vista::Vista(int v)
{
	if (v == 0)
	{
		posicion_ojo.Set_vector(20, 10, 5);
		mira_ojo.Set_vector(0, 0, 0);

		distancia = sqrt(posicion_ojo.x * posicion_ojo.x + posicion_ojo.y * posicion_ojo.y + posicion_ojo.z * posicion_ojo.z);
		distancia_plana = sqrt(posicion_ojo.x * posicion_ojo.x + posicion_ojo.y * posicion_ojo.y);
		angulo = atan2(posicion_ojo.z, distancia_plana);
		angulo_plano = atan2(posicion_ojo.y, posicion_ojo.x);
	}
}

void Vista::Inicializa()
{
	posicion_ojo.Set_vector(20, 10, 10);
	mira_ojo.Set_vector(0, 0, 5);

	distancia = sqrt(posicion_ojo.x * posicion_ojo.x + posicion_ojo.y * posicion_ojo.y + posicion_ojo.z * posicion_ojo.z);
	distancia_plana = sqrt(posicion_ojo.x * posicion_ojo.x + posicion_ojo.y * posicion_ojo.y);
	angulo = atan2(posicion_ojo.z, distancia_plana);
	angulo_plano = atan2(posicion_ojo.y, posicion_ojo.x);
}

//COLOCAR CAMARA

void Vista::Set_vista(float px, float py, float pz, float mx, float my, float mz)
{
	posicion_ojo.Set_vector(px, py, pz);
	mira_ojo.Set_vector(mx, my, mz);
}


//SITUA CAMARA

void Vista::Camara()
{
	gluLookAt(posicion_ojo.x, posicion_ojo.y, posicion_ojo.z,  // posicion del ojo
		mira_ojo.x, mira_ojo.y, mira_ojo.z,      // hacia que punto mira  (0,0,0) 
		0.0, 0.0, 1.0);      // definimos hacia arriba (eje z)
}

void Vista::Camara(int opt)
{
	if (opt == 0)
	{
		gluLookAt(130, 35, 60,  
		35, 35, 5.0,      
		0.0, 0.0, 1.0);      
	}
	if (opt == 1)
	{
		gluLookAt(-60, 35, 60,
			35, 35, 5.0,
			0.0, 0.0, 1.0);
	}	
}

//MOVIMIENTO DE CAMARA Y ZOOM
//no lo utilizamos en el programa fue una prueba para crear las piezas
void Vista::Mover(unsigned char key)
{
	if (key == 'a')
	{
		angulo_plano = angulo_plano - 0.05;
		posicion_ojo.x = distancia_plana * cos(angulo_plano);
		posicion_ojo.y = distancia_plana * sin(angulo_plano);
	}
	if (key == 'd')
	{
		angulo_plano = angulo_plano + 0.05;
		posicion_ojo.x = distancia_plana * cos(angulo_plano);
		posicion_ojo.y = distancia_plana * sin(angulo_plano);
	}
	if (key == 'w')
	{
		angulo = angulo + 0.05;
		distancia_plana = distancia * cos(angulo);
		posicion_ojo.x = distancia_plana * cos(angulo_plano);
		posicion_ojo.y = distancia_plana * sin(angulo_plano);
		posicion_ojo.z = distancia * sin(angulo);
	}
	if (key == 's')
	{
		angulo = angulo - 0.05;
		distancia_plana = distancia * cos(angulo);
		posicion_ojo.x = distancia_plana * cos(angulo_plano);
		posicion_ojo.y = distancia_plana * sin(angulo_plano);
		posicion_ojo.z = distancia * sin(angulo);
	}
	if(key=='+')
	{
		distancia = distancia - 0.25;
		distancia_plana = distancia * cos(angulo);
		posicion_ojo.x = distancia_plana * cos(angulo_plano);
		posicion_ojo.y = distancia_plana * sin(angulo_plano);
		posicion_ojo.z = distancia * sin(angulo);
	}
	if (key == '-')
	{
		distancia = distancia + 0.25;
		distancia_plana = distancia * cos(angulo);
		posicion_ojo.x = distancia_plana * cos(angulo_plano);
		posicion_ojo.y = distancia_plana * sin(angulo_plano);
		posicion_ojo.z = distancia * sin(angulo);
	}
	if (key == 'r')
	{
		mira_ojo.z = mira_ojo.z + 0.25;
	}
	if (key == 'f')
	{
		mira_ojo.z = mira_ojo.z - 0.25;
	}
}
