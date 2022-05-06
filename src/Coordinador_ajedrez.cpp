#include"Coordinador_ajedrez.h"


//CONSTRUCTOR 

Coordinador_ajedrez::Coordinador_ajedrez()
{
	estado = Estado::INICIO;
	partida = new Partida;

	pi = 'P';
}

//INICIALIZAR

void Coordinador_ajedrez::Inicializa()
{
	partida->Inicializa();
}

//DIBUJAR

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
		ETSIDI::printxy("PULSA -ESC- PARA SALIR", -8, 2);

	}

	else if (estado == Estado::PARTIDA_M)
	{
		vista.Set_vista(140, 35, 40, 35, 35, 5);
		vista.Camara();
		partida->Dibuja();
	}

	else if (estado == Estado::VISTA_PIEZA)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		/*
		vista.Set_vista(0, 7.5, 30, 0, 7.5, 0);
		vista.Camara();
		*/
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("Pulsa -ESC- para volver al inicio", -10, 14);
		ETSIDI::printxy("Pulsa -P- para ver peon", -10, 12);
		ETSIDI::printxy("Pulsa -T- para ver torre", -10, 11);
		ETSIDI::printxy("Pulsa -C- para ver caballo", -10, 10);
		ETSIDI::printxy("Pulsa -A- para ver alfil", -10, 9);


		
		vista.Set_vista(10, 5,10, 0, 0, 2);
		vista.Camara();
		
	//////////////////////

		Visualizar_piezas vi;
		vi.visualizar(pi);

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
		ETSIDI::printxy("PULSA -ESC- PARA VOLVER al inicio", -8, 8);		
	}

	else if (estado == Estado::PAUSA)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)


		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("PULSA -I- PARA VOLVER al inicio", -8, 8);
		ETSIDI::printxy("PULSA -C- PARA  continuar la partida", -8, 6);
		

	}

	else if (estado == Estado::EXIT)
	{
		exit(0);
	}
		

}


//TECLADO

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

		if (key == 27)
		{
			estado = Estado::EXIT;
		}
	}

	if (estado == Estado::PARTIDA_M)
	{
		if (key == 27)
		{
			estado = Estado::PAUSA;
		}

	}

	if (estado == Estado::VISTA_PIEZA)
	{
		if (key == 27)
		{
			estado = Estado::INICIO;
		}
		else if (key == 'p' || key == 'P')
			pi = 'P';
		else if (key == 't' || key == 'T')
			pi = 'T';
		else if (key == 'c' || key == 'C')
			pi = 'C';
		else if (key == 'a' || key == 'A')
			pi = 'A';
		else if (key == 'd' || key == 'D')
			pi = 'D';
		else if (key == 'r' || key == 'R')
			pi = 'R';
	}

	if (estado == Estado::CONTROLES)
	{
		if (key == 27)
		{
			estado = Estado::INICIO;
		}
		
	}


	if (estado == Estado::PAUSA)
	{
		if (key == 'i' || key == 'I')
		{
			estado = Estado::INICIO;
		}
		if (key == 'c' || key == 'C')
		{
			estado = Estado::PARTIDA_M;
		}
	}
	
}


