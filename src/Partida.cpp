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

	flag = 'w';
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

	p.Inicializa('b');
	
	flag = 'w';
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
	p.Dibuja();
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
					//peon[3].Mover(1,-1);

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
					//peon[5].Mover(1,0);

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
					//peon[5].Mover(0,0);

					movdatos = MovDatos::M_ESPERA;
					introdatos = IntroDatos::EJE_X;
					turno = Turno::NEGRAS;
				}
			}
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
					//peon[13].Mover(2,0);

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
					//peon[11].Mover(1, 0);

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
					//peon[3].Mover(1);

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
					//peon[3].Mover(1);

					movdatos = MovDatos::M_ESPERA;
					introdatos = IntroDatos::EJE_X;
					turno = Turno::BLANCAS;
				}
			}
		}
	}
}




//MOVIMIENTOS DE PARTIDFA

void Partida::Mueve()
{
	if (turno == Turno::BLANCAS && introdatos == IntroDatos::ESPERA)
	{
		if (flag == 'w')
		{
			Interaccion::Seleccionar(*diosita, p);
			flag = 's';
		}
		if (flag == 's')
		{
			Interaccion::Desplazar(*diosita, p);
			flag = 'w';
		}
	}
}
