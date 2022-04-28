#include"Coordinador_ajedrez.h"


Coordinador_ajedrez::Coordinador_ajedrez()
{
	estado = Estado::INICIO;
	partida = new Partida;

	peon = new Peon;
	
}


void Coordinador_ajedrez::Inicializa()
{
	partida->Inicializa();


	peon->Inicializa('b');
	 
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
		ETSIDI::setFont("fuentes/fast99.ttf", 20);
		ETSIDI::printxy("AJEDREZ", -4, 13);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("PULSA -P- PARA EMPEZAR PARTIDA MULTIJUGADOR", -8, 8);
		ETSIDI::printxy("PULSA -V- PARA VER PIEZAS", -8, 6);
		ETSIDI::printxy("PULSA -C- PARA VER CONTOLES", -8, 4);
		ETSIDI::printxy("PULSA -E- PARA SALIR", -8, 2);

	}

	else if (estado == Estado::PARTIDA_M)
	{
		vista.Set_vista(140, 35, 40, 35, 35, 5);
		vista.Camara();
		partida->Dibuja();
	}

	else if (estado == Estado::VISTA_PIEZA)
	{
		vista.Set_vista(20, 20, 10, 0, 0, 5);
		vista.Camara();

		//Dibuja();


	}

	else if (estado == Estado::CONTROLES)
	{

		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/fast99.ttf", 20);
		ETSIDI::printxy("CONTROLES", -4, 13);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("PULSA -V- PARA VOLVER", -8, 8);		
	}

	else if (estado == Estado::PAUSA)
	{
		

	}

	else if (estado == Estado::EXIT)
	{
		exit(0);
	}
		

}

void Coordinador_ajedrez::Tecla(unsigned char key)
{
	if (estado == Estado::INICIO)
	{

		if (key == 'p' || key == 'P')
		{
			estado = Estado::PARTIDA_M;
		}

		if (key == 'v' || key == 'V')
		{
			estado = Estado::VISTA_PIEZA;
		}

		if (key == 'c' || key == 'C')
		{
			estado = Estado::CONTROLES;
		}

		if (key == 'e' || key == 'E')
		{
			estado = Estado::EXIT;
		}
	}

	if (estado == Estado::PARTIDA_M)
	{

	}

	if (estado == Estado::VISTA_PIEZA)
	{

	}

	if (estado == Estado::CONTROLES)
	{
		if (key == 'v' || key == 'V')
		{
			estado = Estado::INICIO;
		}
		
	}


	if (estado == Estado::PAUSA)
	{

	}
	
}