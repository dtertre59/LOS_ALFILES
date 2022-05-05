#include"Visualizar_piezas.h"

//////////////////////
//FUNCION IDEPENDIENTE

void Gestor_dibuja(Pieza& p)
{
	p.Dibuja();
}


Visualizar_piezas::Visualizar_piezas()
{
	peon = new Peon;
	alfil = new Alfil;
	torre = new Torre;
}

void Visualizar_piezas::visualizar(unsigned char pi)
{
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

	}
	if (pi == 'A')
	{
		alfil->Dibuja();
	}
	if (pi == 'D')
	{

	}
	if (pi == 'R')
	{

	}

}