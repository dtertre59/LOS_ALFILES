#include"Coordinador_ajedrez.h"


Coordinador_ajedrez::Coordinador_ajedrez()
{
	estado = Estado::INICIO;
	partida = new Partida;
}


void Coordinador_ajedrez::Inicializa()
{
	partida->Inicializa();
	 
}

void Coordinador_ajedrez::Dibuja()
{
	if (estado == Estado::INICIO)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		/*
		vista.Set_vista(0, 7.5, 30, 0, 7.5, 0);
		vista.Camara();
		*/
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("AJEDREZ", -4, 13);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("PULSA -P- PARA EMPEZAR PARTIDA", -8, 8);
		ETSIDI::printxy("PULSA -E- PARA SALIR", -8, 6);


		Reina* r;
		r = new Reina;
		r->Dibuja();
	}
	else if (estado == Estado::JUEGO)
	{
		vista.Set_vista(140, 35, 40, 35, 35, 5);
		vista.Camara();
		partida->Dibuja();
	}
	else if (estado == Estado::EXIT)
	{
		exit(0);
	}
		

}

void Coordinador_ajedrez::Tecla(unsigned char key)
{
	if (key == 'p' || key == 'P')
	{
		estado = Estado::JUEGO;
	}
	if (key == 'e' || key == 'E')
	{
		estado = Estado::EXIT;
	}
}