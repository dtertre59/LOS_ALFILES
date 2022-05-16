#include"Coordinador_ajedrez.h"

//CONSTRUCTOR 

Coordinador_ajedrez::Coordinador_ajedrez()
{
	estado = Estado::INICIO;
	partida = new Partida;
	visualizarp = new Visualizar_piezas;


	pi = 'P';
}

//INICIALIZAR

void Coordinador_ajedrez::Inicializa()
{
	partida->Inicializa();
	visualizarp->Inicializa();

}

//DIBUJAR

void Coordinador_ajedrez::Dibuja()
{
	if (estado == Estado::INICIO)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
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
		partida->Dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
	
			ETSIDI::printxy("A", 78, 0);
			ETSIDI::printxy("B", 78, 10);
			ETSIDI::printxy("C", 78, 20);
			ETSIDI::printxy("D", 78, 30);
			ETSIDI::printxy("E", 78, 40);
			ETSIDI::printxy("F", 78, 50);
			ETSIDI::printxy("G", 78, 60);
			ETSIDI::printxy("H", 78, 70);
		
		ETSIDI::printxy("1", 70, -10);
		ETSIDI::printxy("2", 60, -10);
		ETSIDI::printxy("3", 50, -10);
		ETSIDI::printxy("4", 40, -10);
		ETSIDI::printxy("5", 30, -10);
		ETSIDI::printxy("6", 20, -10);
		ETSIDI::printxy("7", 10, -10);
		ETSIDI::printxy("8", 0, -10);
	}

	else if (estado == Estado::VISTA_PIEZA)
	{
		
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("Pulsa -ESC- para volver al inicio", -14, 16);
		ETSIDI::printxy("Pulsa -P- para ver peon", -13, 14);
		ETSIDI::printxy("Pulsa -T- para ver torre", -13, 13);
		ETSIDI::printxy("Pulsa -C- para ver caballo", -13, 12);
		ETSIDI::printxy("Pulsa -A- para ver alfil", -13, 11);
		ETSIDI::printxy("Pulsa -D- para ver dama", -13, 10);
		ETSIDI::printxy("Pulsa -R- para ver rey", -13, 9);

		
		// ver piezas 
		
		visualizarp->visualizar(pi);

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
		partida->Tecla(key);

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



void Coordinador_ajedrez::mueve()
{
	
	if (estado == Estado::VISTA_PIEZA)
	{
		visualizarp->Mover_vista();
	}
	if (estado == Estado::PARTIDA_M)
	{
		partida->Mueve();
	}
	
}