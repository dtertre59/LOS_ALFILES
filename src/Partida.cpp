#include"Partida.h"

Partida::Partida()
{
	tablero = new Tablero;
	peon = new Peon[16];
	caballo = new Caballo[4];
	alfil = new Alfil[4];
	torre = new Torre[4];
	dama = new Dama[2];
	rey = new Rey[2];

	diosita = new DIOSITA;

	pieza_seleccionada = 'w'; //w es wait espera a que sle ponfa el primer valor
}

void Partida::Inicializa()
{
	tablero->Inicializa();

	//inicializar peones
	for (int i = 0; i < 16; i++)
	{
		if (i < 8) {
			peon[i].Inicializa('b', 6 * 10, i * 10, 0);
		}
		else {
			peon[i].Inicializa('n', 10, (i - 8) * 10, 0);
		}
	}
	//inicliazar caballo, torre y alfil
	
	caballo[0].Inicializa('b', 70, 10, 0);
	caballo[1].Inicializa('b', 70, 60, 0);
	caballo[2].Inicializa('n', 0, 10, 0);
	caballo[3].Inicializa('n', 0, 60, 0);

	alfil[0].Inicializa('b', 70, 20, 0);
	alfil[1].Inicializa('b', 70, 50, 0);
	alfil[2].Inicializa('n', 0, 20, 0);
	alfil[3].Inicializa('n', 0, 50, 0);

	torre[0].Inicializa('b', 70, 0, 0);
	torre[1].Inicializa('b', 70, 70, 0);
	torre[2].Inicializa('n', 0, 0, 0);
	torre[3].Inicializa('n', 0, 70, 0);

	for (int i = 0; i < 2; i++)
	{
		if (i < 1)
		{
			dama[i].Inicializa('b', 70, 30, 0);
			rey[i].Inicializa('b', 70, 40, 0);
		}
		else
		{
			dama[i].Inicializa('n', 0, 30, 0);
			rey[i].Inicializa('n', 0, 40, 0);
		}
		
	}

	turno = Turno::BLANCAS;
	introdatos = IntroDatos::EJE_X;
	movdatos = MovDatos::M_ESPERA;

	vista.Set_vista(140, 35, 40, 35, 35, 5);

	//diosita->Inicializa();

	
	pieza_seleccionada = 'w';
	aux.Set_vector(0, 0, 0);
}

void Partida::Dibuja()
{
	if (turno == Turno::BLANCAS)
		vista.Camara(0);
	else
		vista.Camara(0);//vista.Camara(1);

	//dibujar tablero
	tablero->Dibuja();

	//dibujar DIOSITA
	diosita->Dibuja();

	//dibujar  peones
	for (int i = 0; i < 16; i++) //poner 16 en el for
	{
		
		if(i == 3)
			peon[i].Dibuja();
		if (i == 5)
			peon[i].Dibuja();
		if (i == 11)
			peon[i].Dibuja();
		if (i == 13)
			peon[i].Dibuja();
			
	}

	//dibujar damas y reyes
	for (int i = 0; i < 2; i++)
	{
		//ALGO.dIBUJA
		//dama[i].Dibuja();
		rey[i].Dibuja();
	}

	//dibujar torres, caballos y alfiles
	for (int i = 0; i < 4; i++)
	{
		//caballo[i].Dibuja();
		//alfil[i].Dibuja();
		//torre[i].Dibuja();
		//los dibuja de torres, caballos y alfiles
	}
}

void Partida::Tecla(unsigned char c)
{
	if (turno == Turno::BLANCAS)
	{
		
	//	do {
			if (introdatos == IntroDatos::EJE_X)
			{
				for (int i = 0, j = 7; i < 8; i++, j--)
				{
					if (c == 49 + i)
					{
						diosita->SetPosX(j * 10);
						
						introdatos = IntroDatos::EJE_Y;
					}
				}
			}

			if (introdatos == IntroDatos::EJE_Y)
			{
				for (int i = 0; i < 8; i++)
				{
					if (c == 97 + i)
					{
						diosita->SetPosY(i * 10);
						
						introdatos = IntroDatos::ESPERA;
						movdatos = MovDatos::M_EJE_X;
					}
				}
			}
		//} while (diosita->flagA == 0);

			if (movdatos == MovDatos::M_EJE_X)
			{
				for (int i = 0, j = 7; i < 8; i++, j--)
				{
					if (c == 49 + i)
					{
						diosita->SetPosX(j * 10);
						diosita->ColPieza();
						
						movdatos = MovDatos::M_ESPERA;
						movdatos = MovDatos::M_EJE_Y;
					}
				}
			}

			if (movdatos == MovDatos::M_EJE_Y)
			{
				for (int i = 0; i < 8; i++)
				{
					if (c == 97 + i)
					{
						diosita->SetPosY(i * 10);
						diosita->ColPieza();
					

						movdatos = MovDatos::M_ESPERA;
						introdatos = IntroDatos::EJE_X;
						turno = Turno::CAMBIO;
					}
				}
			}
		
	}
	if (turno == Turno::CAMBIO)
	{
		if (c == 32)
		{
			turno = Turno::NEGRAS;
			diosita->Set_color('r');
		}
	}
	if (turno == Turno::CAMBIO2)
	{
		if (c == 32)
		{
			turno = Turno::BLANCAS;
			diosita->Set_color('v');
		}
	}


	if (turno == Turno::NEGRAS)
	{

		if (introdatos == IntroDatos::EJE_X)
		{
			for (int i = 0, j = 7; i < 8; i++, j--)
			{
				if (c == 49 + i)
				{
					diosita->SetPosX(j * 10);
					

					introdatos = IntroDatos::EJE_Y;
				}
			}
		}

		if (introdatos == IntroDatos::EJE_Y)
		{
			
			for (int i = 0; i < 8; i++)
			{
				if (c == 97 + i)
				{
					diosita->SetPosY(i * 10);
					

					introdatos = IntroDatos::ESPERA;
					movdatos = MovDatos::M_EJE_X;
				}
			}
		}

		if (movdatos == MovDatos::M_EJE_X)
		{
			for (int i = 0, j = 7; i < 8; i++, j--)
			{
				if (c == 49 + i)
				{
					diosita->SetPosX(j * 10);
					

					movdatos = MovDatos::M_EJE_Y;
				}
			}
		}

		if (movdatos == MovDatos::M_EJE_Y)
		{
			for (int i = 0; i < 8; i++)
			{
				if (c == 97 + i)
				{
					diosita->SetPosY(i * 10);
					

					movdatos = MovDatos::M_ESPERA;
					introdatos = IntroDatos::EJE_X;
					turno = Turno::CAMBIO2;
				}
			}
		}
		
	}
}




//MOVIMIENTOS DE PARTIDFA

void Partida::Mueve()
{
	if (turno == Turno::BLANCAS && introdatos == IntroDatos::ESPERA && movdatos == MovDatos::M_EJE_X)
	{
		aux = Interaccion::Seleccionar(*diosita);

		/*
			if (pieza_seleccionada == 'w'|| pieza_seleccionada == '0')
			{
				pieza_seleccionada = Interaccion::Seleccionar(*diosita, *tablero);
			}
			else {
				Interaccion::Desplazar(*diosita, p);
			}
			*/
	}

	if (turno==Turno::CAMBIO)
	{
		if (aux.x==rey[0].devPosx() && aux.y == rey[0].devPosy())
			Interaccion::Desplazar(*diosita, rey[0]);

		if (aux.x == peon[3].devPosx() && aux.y == peon[3].devPosy())
			Interaccion::Desplazar(*diosita, peon[3]);



		
		//rey[0].Inicializa('b', 70, 40, 0);
	}
}
