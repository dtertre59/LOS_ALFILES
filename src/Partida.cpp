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

	turno = Turno::BLANCAS;
	introdatos = IntroDatos::EJE_X;
	movdatos = MovDatos::M_ESPERA;
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
	posicion_pieza_seleccionada.Set_vector(0, 0, 0);
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


						//PIEZAS BLANCAS EN EL TABLERO---->COMPARARLAS CON DIOSITA PARA SABER CUAL ES LA SELECCIONADA

						if (diosita->Get_pos() == peon[3].Get_pos())
						{
							peon[3].Set_color('v'); //para ambiarle el color al peon si es el sdeleccionado. luego faltaria quitarselo cuando terminas de mover

							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
						}
						else if (diosita->Get_pos() == peon[5].Get_pos())
						{
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
						}
						else if (diosita->Get_pos() == rey[0].Get_pos())
						{
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
						}
	
						else //si no has seleccionado ninguna tienes que repietir. meter eje x y luego y
						{
							introdatos = IntroDatos::EJE_X;
							diosita->Set_color('a'); //diosita se pone de color azul si no seleccionas ninguna casilla con pieza
						}
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
						//diosita->ColPieza();
						
						//movdatos = MovDatos::M_ESPERA;
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
						//diosita->ColPieza();
						
						if (Interaccion::Comprobar_movimiento(*diosita, peon[3]))//si se cumple la condicion 
						{
							introdatos = IntroDatos::EJE_X;
							movdatos = MovDatos::M_ESPERA;
							turno = Turno::CAMBIO;
						}
						else //retrocedemos para volver a poner el sitio donde decimos a donde queremos mover la pieza
						{
							diosita->Set_color('m');
							movdatos = MovDatos::M_EJE_X;
						}
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
	//PARA CONOCER LA POSICION DE LA PIEZA QUE QUEREMOS MOVER

	if (turno == Turno::BLANCAS && introdatos == IntroDatos::ESPERA && movdatos == MovDatos::M_EJE_X)
	{
		posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);

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

	if (turno == Turno::NEGRAS && introdatos == IntroDatos::ESPERA && movdatos == MovDatos::M_EJE_X)
	{
		posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
	}


	//PARA MOVER LA PIEZA QUE ESTABA EN LA POSICION DE ANTES DONDE HAYAMOS MOVIDO A DIOSITA

	if (turno==Turno::CAMBIO)
	{
		if (posicion_pieza_seleccionada==rey[0].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
			Interaccion::Desplazar(*diosita, rey[0]);



		//mover BLANCAS


		//mover rey
		//if (posicion_pieza_seleccionada.x == rey[0].devPosx() && posicion_pieza_seleccionada.y == rey[0].devPosy())
			//Interaccion::Desplazar(*diosita, rey[0]);
		//mover dama
		if (posicion_pieza_seleccionada.x == dama[0].devPosx() && posicion_pieza_seleccionada.y == dama[0].devPosy())
			Interaccion::Desplazar(*diosita, dama[0]);

		for (int i = 0; i < 8; i++)
		{
			//mover peon
			if (posicion_pieza_seleccionada.x == peon[i].devPosx() && posicion_pieza_seleccionada.y == peon[i].devPosy())
				Interaccion::Desplazar(*diosita, peon[i]);

			//mover caballo,torre,alfil
			if (i < 4)
			{
				if (posicion_pieza_seleccionada.x == torre[i].devPosx() && posicion_pieza_seleccionada.y == torre[i].devPosy())
					Interaccion::Desplazar(*diosita, torre[i]);

			//	if (aux.x == caballo[i].devPosx() && aux.y == caballo[i].devPosy())
			//		Interaccion::Desplazar(*diosita, caballo[i]);

				if (posicion_pieza_seleccionada.x == alfil[i].devPosx() && posicion_pieza_seleccionada.y == alfil[i].devPosy())
					Interaccion::Desplazar(*diosita, alfil[i]);
			}
		}

	}
	if (turno == Turno::CAMBIO2)
	{
		//mover negras
		
		//mover rey
		if (posicion_pieza_seleccionada.x == rey[1].devPosx() && posicion_pieza_seleccionada.y == rey[1].devPosy())
			Interaccion::Desplazar(*diosita, rey[1]);
		//mover dama
		if (posicion_pieza_seleccionada.x == dama[1].devPosx() && posicion_pieza_seleccionada.y == dama[1].devPosy())
			Interaccion::Desplazar(*diosita, dama[1]);

		for (int i = 0; i < 8; i++)
		{
			//mover peon
			int j = i + 7;
			if (posicion_pieza_seleccionada.x == peon[j].devPosx() && posicion_pieza_seleccionada.y == peon[j].devPosy())
				Interaccion::Desplazar(*diosita, peon[j]);

			//mover caballo,torre,alfil
			if (i >= 4)
			{
				if (posicion_pieza_seleccionada.x == torre[i].devPosx() && posicion_pieza_seleccionada.y == torre[i].devPosy())
					Interaccion::Desplazar(*diosita, torre[i]);

				//	if (aux.x == caballo[i].devPosx() && aux.y == caballo[i].devPosy())
				//		Interaccion::Desplazar(*diosita, caballo[i]);

				if (posicion_pieza_seleccionada.x == alfil[i].devPosx() && posicion_pieza_seleccionada.y == alfil[i].devPosy())
					Interaccion::Desplazar(*diosita, alfil[i]);
			}
		}
	}



}
