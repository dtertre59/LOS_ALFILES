#include"Visualizar_piezas.h"
#include"freeglut.h"

//////////////////////
//FUNCION IDEPENDIENTE

void Gestor_dibuja(Pieza& p)
{
	p.Dibuja();
}


Visualizar_piezas::Visualizar_piezas()
{
	peon = new Peon;
	torre = new Torre;
	caballo = new Caballo;
	alfil = new Alfil;
	dama = new Dama;
	rey = new Rey;
	
}

void Visualizar_piezas::visualizar(unsigned char pi)
{
	vista.Camara();

	//vista.Camara();
	
	if (pi == 'P')
	{
		peon->Dibuja();
	}
	if (pi == 'T')
	{
		torre->Dibuja();
	}
	if (pi == 'C')
	{
		caballo->Dibuja();
	}
	if (pi == 'A')
	{
		alfil->Dibuja();
	}
	if (pi == 'D')
	{
		dama->Dibuja();
	}
	if (pi == 'R')
	{
		rey->Dibuja();
	}

}

void Visualizar_piezas::Mover_vista()
{
	vista.Mover('d');
}


void Visualizar_piezas::Inicializa()
{
	vista.Inicializa();

}