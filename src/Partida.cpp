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
	tablerito = new Tablerito;


	turno = Turno::BLANCAS;
	introdatos = IntroDatos::EJE_X;
	movdatos = MovDatos::M_ESPERA;



	pieza_selec = "00";
	dni_pieza_selec = "00000";

	control_selccion_pieza = 0;

	flag_seleccion_pieza = 0;
	flag_numero_pieza = 0;
	
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
	tablerito->Inicializa();


	pieza_selec = "00";
	dni_pieza_selec = "00000";

	control_selccion_pieza = 0;
	posicion_pieza_seleccionada.Set_vector(0, 0, 0);
}

void Partida::Dibuja()
{

	if (turno == Turno::BLANCAS)
		vista.Camara(0);
	else if (turno == Turno::NEGRAS)
		vista.Camara(0);//vista.Camara(1);
	else if (turno== Turno::CAMBIO)
		vista.Camara(0);
	else if (turno == Turno::CAMBIO2)
		vista.Camara(0);
	else 
		vista.Camara(0);

	//dibujar tablero
	tablero->Dibuja();

	//dibujar DIOSITA
	diosita->Dibuja();

	//dibujar  peones
	for (int i = 0; i < 16; i++) //poner 16 en el for
	{
		peon[i].Dibuja();
	}

	//dibujar damas y reyes
	for (int i = 0; i < 2; i++)
	{
		dama[i].Dibuja();
		rey[i].Dibuja();
	}

	//dibujar torres, caballos y alfiles
	for (int i = 0; i < 4; i++)
	{
		caballo[i].Dibuja();
		alfil[i].Dibuja();
		torre[i].Dibuja();	
	}
}



void Partida::Tecla(unsigned char c)
{
	if (turno == Turno::BLANCAS)
	{
		
		if (c == 8)
		{
			
			pieza_selec = "00";
			dni_pieza_selec = "00000";


			control_selccion_pieza = 0;
			posicion_pieza_seleccionada.Set_vector(0.0, 0.0, 0.0);

			flag_seleccion_pieza = 0;
			flag_numero_pieza = 0;

			diosita->Set_color('v');
			for (int i = 0; i < 8; i++)
			{
				peon[i].Set_color('b');
				if (i < 2)
				{
					caballo[i].Set_color('b');
					torre[i].Set_color('b');
					alfil[i].Set_color('b');
				}
				if (i < 1)
				{
					rey[i].Set_color('b');
					dama[i].Set_color('b');
				}
			}

			turno = Turno::BLANCAS;
			introdatos = IntroDatos::EJE_X;
			movdatos = MovDatos::M_ESPERA;


		}
		
		//METER POSICION DE LA PIEZA QUE QUIERES MOVER
		if (control_selccion_pieza == 0 && pieza_selec == "00")
		{
			if (introdatos == IntroDatos::EJE_X && movdatos == MovDatos::M_ESPERA)
			{
				control_selccion_pieza = 0;

				diosita->Set_color('v');
				for (int i = 0, j = 7; i < 8; i++, j--)
				{
					if (c == 49 + i)
					{
						diosita->SetPosX(j * 10);

						introdatos = IntroDatos::EJE_Y;
					}
				}
			}

			if (introdatos == IntroDatos::EJE_Y && movdatos == MovDatos::M_ESPERA)
			{
				

				for (int i = 0; i < 8; i++)
				{
					if (c == 97 + i)
					{
						diosita->SetPosY(i * 10);

						//AQUI YA TENEMOS LA POSICION DE DIOSITA PARA SELECCIONAR PIEZAS



						//PIEZAS BLANCAS EN EL TABLERO---->COMPARARLAS CON DIOSITA PARA SABER CUAL ES LA SELECCIONADA
						if (flag_seleccion_pieza == 0 )
						{
							int w = 0;
							do
							{
								//diosita->Set_color('n');

								if (diosita->Get_pos() == peon[w].Get_pos())
								{
									peon[w].Set_color('v'); //para ambiarle el color al peon si es el sdeleccionado. luego faltaria quitarselo cuando terminas de mover

									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada); //BP1

									//BP saber que es el peon blanco
									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;  //saber que hemos seleccionado una pieza
									flag_numero_pieza = w;     //saber que numero de pieza hemos seleccionado

								}

								else if (diosita->Get_pos() == rey[0].Get_pos())
								{
									rey[0].Set_color('v');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									//BR saber que es el REY blanco
									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;  //saber que hemos seleccionado una pieza
									flag_numero_pieza = 0;     //el rey 0 es el blanco
								}
								else if (diosita->Get_pos() == alfil[w].Get_pos() && w < 2)
								{
									alfil[w].Set_color('v');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;
									flag_numero_pieza = w;
								}

								else if (diosita->Get_pos() == torre[w].Get_pos() && w < 2)
								{
									torre[w].Set_color('v');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;
									flag_numero_pieza = w;
								}
								else if (diosita->Get_pos() == caballo[w].Get_pos() && w < 2)
								{
									caballo[w].Set_color('v');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;
									flag_numero_pieza = w;
								}
								else if (diosita->Get_pos() == dama[0].Get_pos())
								{
									dama[0].Set_color('v');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;
									flag_numero_pieza = 0;
								}
								w++;
							} while (w < 8 && flag_seleccion_pieza != 1);
							
							if (flag_seleccion_pieza==0)
							{
								introdatos = IntroDatos::EJE_X;
								diosita->Set_color('a'); //diosita se pone de color azul si no seleccionas ninguna casilla con pieza
							}						
						}											
					}
				}
			}
		}

		//METER POSICION DE DONDE QUIERES MOVER LA PIEZA

		if (control_selccion_pieza == 1)
		{

			if (movdatos == MovDatos::M_EJE_X && introdatos == IntroDatos::ESPERA)
			{
				diosita->Set_color('c');

				for (int i = 0, j = 7; i < 8; i++, j--)
				{
					if (c == 49 + i)
					{
						diosita->SetPosX(j * 10);

						movdatos = MovDatos::M_EJE_Y;
					}
				}
			}

			if (movdatos == MovDatos::M_EJE_Y && introdatos == IntroDatos::ESPERA)
			{
				for (int i = 0; i < 8; i++)
				{
					if (c == 97 + i)
					{
						diosita->SetPosY(i * 10);
						//con esto ya tendriamos la posicion del movimiento con diosita
						//ahora tenemos que comprobar si es posible el movimiento con la pieza seleccionada anteriormente





							//////////////////////////////////////////////////////////////////////////////////////////
						

							//poner el flag geberal de reestriccion de movimientos y comidas

							//flag_a_donde_movemos = tablerito->Comprobar_posicion_movimiento(diosita->Get_pos());



					
						//SEGUN COMO QUE DEL FLAG DE TODO ARRIBA HACEMOS UNA COSA U OTRA. EN EL FLAG HAY Q METRLE TAMBIEN LA PIEZA SELECCIONADA
						//NO HARIA FALTA TODO LO DE ABAJO

						//if (pieza_selec == "BP" && Interaccion::Comprobar_movimiento(*diosita, peon[flag_numero_pieza]))//si se cumple la condicion 
						if(pieza_selec == "BP" && tablerito->Comprobar_movimiento_completo(peon[flag_numero_pieza],diosita->Get_pos())!=0)
						{

							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							//{
							
							if (tablerito->Comprobar_movimiento_completo(peon[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('b');
								peon[flag_numero_pieza].Set_color('b');

								tablerito->Mover(peon[flag_numero_pieza], diosita->Get_pos());

								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							if (tablerito->Comprobar_movimiento_completo(peon[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
								

							
							/*
						}
						else
						{

							diosita->Set_color('m');
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
							turno = Turno::BLANCAS;
							ETSIDI::play("sonidos/disparo.wav");
						}
						*/
						}

						


						else if (pieza_selec == "BR" && tablerito->Comprobar_movimiento_completo(rey[flag_numero_pieza], diosita->Get_pos())!=0)//si se cumple la condicion //se podria poner rey[flag_numero_pieza
						{
							if (tablerito->Comprobar_movimiento_completo(rey[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('b');
								rey[flag_numero_pieza].Set_color('b');
								tablerito->Mover(rey[flag_numero_pieza], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							if (tablerito->Comprobar_movimiento_completo(rey[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[0]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[1]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[2]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[4])&&Interaccion::Comprobar_choque_piezas(*diosita,peon[6])&&Interaccion::Comprobar_choque_piezas(*diosita,peon[7]))
							//{
							
							/*
						}
						else
						{
							diosita->Set_color('m');
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
							turno = Turno::BLANCAS;
							ETSIDI::play("sonidos/disparo.wav");
						}
						*/
						}

						else if (pieza_selec == "BA" && tablerito->Comprobar_movimiento_completo(alfil[flag_numero_pieza], diosita->Get_pos()) != 0)//si se cumple la condicion 
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							//{
							if (tablerito->Comprobar_movimiento_completo(alfil[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('b');
								alfil[flag_numero_pieza].Set_color('b');
								tablerito->Mover(alfil[flag_numero_pieza], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							if (tablerito->Comprobar_movimiento_completo(alfil[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}

							/* }
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
							*/
						}
						/*
						else if (pieza_selec == "a1" && Interaccion::Comprobar_movimiento(*diosita, alfil[1]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							{
								diosita->Set_color('b');
								alfil[1].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						*/
						else if (pieza_selec == "BT" && tablerito->Comprobar_movimiento_completo(torre[flag_numero_pieza], diosita->Get_pos()) != 0)//si se cumple la condicion 
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[1])&&Interaccion::Comprobar_choque_piezas(*diosita,alfil[0])&&Interaccion::Comprobar_choque_piezas(*diosita, alfil[1])&& Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0])&& Interaccion::Comprobar_choque_piezas(*diosita, peon[3])&& Interaccion::Comprobar_choque_piezas(*diosita, peon[5])&& Interaccion::Comprobar_choque_piezas(*diosita,caballo[0])&& Interaccion::Comprobar_choque_piezas(*diosita,caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							//{
							if (tablerito->Comprobar_movimiento_completo(torre[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('b');
								torre[flag_numero_pieza].Set_color('b');
								tablerito->Mover(torre[flag_numero_pieza], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							if (tablerito->Comprobar_movimiento_completo(torre[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
							/*
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
							*/

						}
						/*
						else if (pieza_selec == "t1" && Interaccion::Comprobar_movimiento(*diosita, torre[1]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							{
								diosita->Set_color('b');
								torre[1].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						*/

						else if (pieza_selec == "BD" && tablerito->Comprobar_movimiento_completo(dama[0], diosita->Get_pos()) != 0)//si se cumple la condicion 
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							//{
							if (tablerito->Comprobar_movimiento_completo(dama[0], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('b');
								dama[0].Set_color('b');
								tablerito->Mover(dama[0], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							if (tablerito->Comprobar_movimiento_completo(dama[0], diosita->Get_pos()) == 2)
							{
								//comer
							}
								
						}
						/*
						else
						{
							diosita->Set_color('m');
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
							turno = Turno::BLANCAS;
							ETSIDI::play("sonidos/disparo.wav");
						}
						*/

						else if (pieza_selec == "BC" && tablerito->Comprobar_movimiento_completo(caballo[flag_numero_pieza], diosita->Get_pos()) != 0)//si se cumple la condicion 
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							//{
							if (tablerito->Comprobar_movimiento_completo(caballo[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('b');
								caballo[flag_numero_pieza].Set_color('b');
								tablerito->Mover(caballo[flag_numero_pieza], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							if (tablerito->Comprobar_movimiento_completo(caballo[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
							/*
							}

							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
							*/


						}


						/*
						else if (pieza_selec == "c1" && Interaccion::Comprobar_movimiento(*diosita, caballo[1]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							{
								diosita->Set_color('b');
								caballo[1].Set_color('b');

								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						*/

						//si no se ha puesto una posicion alcanzable
						else //retrocedemos para volver a poner el sitio donde decimos a donde queremos mover la pieza
						{
							diosita->Set_color('m');
							ETSIDI::play("sonidos/disparo.wav");
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
							turno = Turno::BLANCAS;
						}
					}
				}
			}
		}
	}


	if (turno == Turno::CAMBIO)
	{
		if (c == 32)
		{
			//RESETEAMOS LOS FLAGS Y LAS VARIABLES PARA PODER CAMBIAR DE TURNO

			pieza_selec = "00";
			dni_pieza_selec = "00000";


			control_selccion_pieza = 0;
			posicion_pieza_seleccionada.Set_vector(0.0, 0.0, 0.0);

			flag_seleccion_pieza = 0;
			flag_numero_pieza = 0;

			diosita->Set_color('r');

			turno = Turno::NEGRAS;
			introdatos = IntroDatos::EJE_X;
			movdatos = MovDatos::M_ESPERA;
			
		}
	}


	if (turno == Turno::CAMBIO2)
	{
		if (c == 32)
		{
			//RESETEAMOS LOS FLAGS Y LAS VARIABLES PARA PODER CAMBIAR DE TURNO

			pieza_selec = "00";
			dni_pieza_selec = "00000";


			control_selccion_pieza = 0;
			posicion_pieza_seleccionada.Set_vector(0.0, 0.0, 0.0);

			flag_seleccion_pieza = 0;
			flag_numero_pieza = 0;

			diosita->Set_color('v');

			turno = Turno::BLANCAS;
			introdatos = IntroDatos::EJE_X;
			movdatos = MovDatos::M_ESPERA;
			
		}
	}


	if (turno == Turno::NEGRAS)
	{
		if (c == 8)
		{

			pieza_selec = "00";
			dni_pieza_selec = "00000";


			control_selccion_pieza = 0;
			posicion_pieza_seleccionada.Set_vector(0.0, 0.0, 0.0);

			flag_seleccion_pieza = 0;
			flag_numero_pieza = 0;

			diosita->Set_color('r');
			for (int i = 0; i < 8; i++)
			{
				peon[i+8].Set_color('n');
				if (i < 2)
				{
					caballo[i+2].Set_color('n');
					torre[i+2].Set_color('n');
					alfil[i+2].Set_color('n');
				}
				if (i < 1)
				{
					rey[i+1].Set_color('n');
					dama[i+1].Set_color('n');
				}
			}

			turno = Turno::NEGRAS;
			introdatos = IntroDatos::EJE_X;
			movdatos = MovDatos::M_ESPERA;


		}
		//METER POSICION DE LA PIEZA QUE QUIERES MOVER
		if (control_selccion_pieza == 0 && pieza_selec == "00")
		{
			if (introdatos == IntroDatos::EJE_X && movdatos == MovDatos::M_ESPERA)
			{
				control_selccion_pieza = 0;

				for (int i = 0, j = 7; i < 8; i++, j--)
				{
					if (c == 49 + i)
					{
						diosita->SetPosX(j * 10);

						introdatos = IntroDatos::EJE_Y;
					}
				}
			}

			if (introdatos == IntroDatos::EJE_Y && movdatos == MovDatos::M_ESPERA)
			{


				for (int i = 0; i < 8; i++)
				{
					if (c == 97 + i)
					{
						diosita->SetPosY(i * 10);

						//AQUI YA TENEMOS LA POSICION DE DIOSITA PARA SELECCIONAR PIEZAS



						//PIEZAS NEGERAS EN EL TABLERO---->COMPARARLAS CON DIOSITA PARA SABER CUAL ES LA SELECCIONADA
						if (flag_seleccion_pieza == 0)
						{
							int w = 8;
							int p = 2;
							do
							{
								if (diosita->Get_pos() == peon[w].Get_pos())
								{
									peon[w].Set_color('r'); //para ambiarle el color al peon si es el sdeleccionado. luego faltaria quitarselo cuando terminas de mover

									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada); //NP1

									//NP saber que es el peon NEGRO
									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;  //saber que hemos seleccionado una pieza
									flag_numero_pieza = w;     //saber que numero de pieza hemos seleccionado

								}

								else if (diosita->Get_pos() == rey[1].Get_pos())
								{
									rey[1].Set_color('r');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									//BR saber que es el REY blanco
									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;  //saber que hemos seleccionado una pieza
									flag_numero_pieza = 1;     //el rey 1 es negro
								}
								else if (diosita->Get_pos() == alfil[p].Get_pos() && p < 4)
								{
									alfil[p].Set_color('r');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;
									flag_numero_pieza = p;
								}

								else if (diosita->Get_pos() == torre[p].Get_pos() && p < 4)
								{
									torre[p].Set_color('r');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;
									flag_numero_pieza = p;
								}
								else if (diosita->Get_pos() == caballo[p].Get_pos() && p < 4)
								{
									caballo[p].Set_color('r');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;
									flag_numero_pieza = p;
								}
								else if (diosita->Get_pos() == dama[1].Get_pos())
								{
									dama[1].Set_color('r');
									posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
									dni_pieza_selec = tablerito->Localizar_pieza(posicion_pieza_seleccionada);

									pieza_selec[0] = dni_pieza_selec[0];
									pieza_selec[1] = dni_pieza_selec[1];

									introdatos = IntroDatos::ESPERA;
									movdatos = MovDatos::M_EJE_X;

									flag_seleccion_pieza = 1;
									flag_numero_pieza = 1;
								}
								p++;
								w++;
							} while (w < 16 && flag_seleccion_pieza != 1);

							if (flag_seleccion_pieza == 0)
							{
								introdatos = IntroDatos::EJE_X;
								diosita->Set_color('a'); //diosita se pone de color azul si no seleccionas ninguna casilla con pieza
							}
						}
					}
				}
			}
		}



		//METER POSICION DE DONDE QUIERES MOVER LA PIEZA

		if (control_selccion_pieza == 1)
		{

			if (movdatos == MovDatos::M_EJE_X && introdatos == IntroDatos::ESPERA)
			{
				diosita->Set_color('c');

				for (int i = 0, j = 7; i < 8; i++, j--)
				{
					if (c == 49 + i)
					{
						diosita->SetPosX(j * 10);

						movdatos = MovDatos::M_EJE_Y;
					}
				}
			}

			if (movdatos == MovDatos::M_EJE_Y && introdatos == IntroDatos::ESPERA)
			{
				for (int i = 0; i < 8; i++)
				{
					if (c == 97 + i)
					{
						diosita->SetPosY(i * 10);
						//con esto ya tendriamos la posicion del movimiento con diosita
						//ahora tenemos que comprobar si es posible el movimiento con la pieza seleccionada anteriormente





							//////////////////////////////////////////////////////////////////////////////////////////


							//poner el flag geberal de reestriccion de movimientos y comidas

							//flag_a_donde_movemos = tablerito->Comprobar_posicion_movimiento(diosita->Get_pos());




						//SEGUN COMO QUE DEL FLAG DE TODO ARRIBA HACEMOS UNA COSA U OTRA. EN EL FLAG HAY Q METRLE TAMBIEN LA PIEZA SELECCIONADA
						//NO HARIA FALTA TODO LO DE ABAJO

						if (pieza_selec == "NP" && Interaccion::Comprobar_movimiento(*diosita, peon[flag_numero_pieza])!=0)//si se cumple la condicion 
						{

							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							//{
							if (tablerito->Comprobar_movimiento_completo(peon[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('n');
								peon[flag_numero_pieza].Set_color('n');

								tablerito->Mover(peon[flag_numero_pieza], diosita->Get_pos());

								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO2;
							}
							if (tablerito->Comprobar_movimiento_completo(peon[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
							/*
						}
						else
						{

							diosita->Set_color('m');
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
							turno = Turno::BLANCAS;
							ETSIDI::play("sonidos/disparo.wav");
						}
						*/
						}

						//SE PODRIA BORRAR
						/*
						else if (pieza_selec == "p1" && Interaccion::Comprobar_movimiento(*diosita, peon[1]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							{
								diosita->Set_color('b');
								peon[1].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						else if (pieza_selec == "p2" && Interaccion::Comprobar_movimiento(*diosita, peon[2]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							{
								diosita->Set_color('b');
								peon[2].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						else if (pieza_selec=="p3"&&Interaccion::Comprobar_movimiento(*diosita, peon[3]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0])&&Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0])&& Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1])&& Interaccion::Comprobar_choque_piezas(*diosita,peon[0])&& Interaccion::Comprobar_choque_piezas(*diosita,peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita,peon[2]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[4])&&Interaccion::Comprobar_choque_piezas(*diosita,peon[6])&&Interaccion::Comprobar_choque_piezas(*diosita,peon[7]))
							{
								diosita->Set_color('b');
								peon[3].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;

							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						else if (pieza_selec == "p4" && Interaccion::Comprobar_movimiento(*diosita, peon[4]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							{
								diosita->Set_color('b');
								peon[4].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						else if (pieza_selec == "p5"&&Interaccion::Comprobar_movimiento(*diosita, peon[5]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							{
								diosita->Set_color('b');
								peon[5].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						else if (pieza_selec == "p6" && Interaccion::Comprobar_movimiento(*diosita, peon[6]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							{
								diosita->Set_color('b');
								peon[6].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						else if (pieza_selec == "p7" && Interaccion::Comprobar_movimiento(*diosita, peon[7]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]))
							{
								diosita->Set_color('b');
								peon[7].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						*/



						else if (pieza_selec == "NR" && Interaccion::Comprobar_movimiento(*diosita, rey[flag_numero_pieza]))//si se cumple la condicion //se podria poner rey[flag_numero_pieza
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[0]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[1]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[2]) &&Interaccion::Comprobar_choque_piezas(*diosita,peon[4])&&Interaccion::Comprobar_choque_piezas(*diosita,peon[6])&&Interaccion::Comprobar_choque_piezas(*diosita,peon[7]))
							//{
							if (tablerito->Comprobar_movimiento_completo(rey[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('n');
								rey[flag_numero_pieza].Set_color('n');
								tablerito->Mover(rey[flag_numero_pieza], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO2;
							}
							if (tablerito->Comprobar_movimiento_completo(rey[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
							/*
						}
						else
						{
							diosita->Set_color('m');
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
							turno = Turno::BLANCAS;
							ETSIDI::play("sonidos/disparo.wav");
						}
						*/
						}

						else if (pieza_selec == "NA" && Interaccion::Comprobar_movimiento(*diosita, alfil[flag_numero_pieza])!=0)//si se cumple la condicion 
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							//{
							if (tablerito->Comprobar_movimiento_completo(alfil[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('n');
								alfil[flag_numero_pieza].Set_color('n');
								tablerito->Mover(alfil[flag_numero_pieza], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO2;
							}
							if (tablerito->Comprobar_movimiento_completo(alfil[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
							/* }
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
							*/
						}
						/*
						else if (pieza_selec == "a1" && Interaccion::Comprobar_movimiento(*diosita, alfil[1]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							{
								diosita->Set_color('b');
								alfil[1].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						*/
						else if (pieza_selec == "NT" && Interaccion::Comprobar_movimiento(*diosita, torre[flag_numero_pieza])!=0)//si se cumple la condicion 
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[1])&&Interaccion::Comprobar_choque_piezas(*diosita,alfil[0])&&Interaccion::Comprobar_choque_piezas(*diosita, alfil[1])&& Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0])&& Interaccion::Comprobar_choque_piezas(*diosita, peon[3])&& Interaccion::Comprobar_choque_piezas(*diosita, peon[5])&& Interaccion::Comprobar_choque_piezas(*diosita,caballo[0])&& Interaccion::Comprobar_choque_piezas(*diosita,caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))
							//{
							if (tablerito->Comprobar_movimiento_completo(torre[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('n');
								torre[flag_numero_pieza].Set_color('n');
								tablerito->Mover(torre[flag_numero_pieza], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO2;
							}
							if (tablerito->Comprobar_movimiento_completo(torre[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
							/*
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
							*/

						}
						/*
						else if (pieza_selec == "t1" && Interaccion::Comprobar_movimiento(*diosita, torre[1]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							{
								diosita->Set_color('b');
								torre[1].Set_color('b');
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						*/

						else if (pieza_selec == "ND" && Interaccion::Comprobar_movimiento(*diosita, dama[1])!=0)//si se cumple la condicion 
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							//{
							if (tablerito->Comprobar_movimiento_completo(dama[1], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('n');
								dama[1].Set_color('n');
								tablerito->Mover(dama[1], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO2;
							}
							if (tablerito->Comprobar_movimiento_completo(dama[1], diosita->Get_pos()) == 2)
							{
								//comer
							}
						}
						/*
						else
						{
							diosita->Set_color('m');
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
							turno = Turno::BLANCAS;
							ETSIDI::play("sonidos/disparo.wav");
						}
						*/

						else if (pieza_selec == "NC" && Interaccion::Comprobar_movimiento(*diosita, caballo[flag_numero_pieza])!=0)//si se cumple la condicion 
						{
							//if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							//{
							if (tablerito->Comprobar_movimiento_completo(caballo[flag_numero_pieza], diosita->Get_pos()) == 1)
							{
								diosita->Set_color('n');
								caballo[flag_numero_pieza].Set_color('n');
								tablerito->Mover(caballo[flag_numero_pieza], diosita->Get_pos());
								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO2;
							}
							if (tablerito->Comprobar_movimiento_completo(caballo[flag_numero_pieza], diosita->Get_pos()) == 2)
							{
								//comer
							}
							/*
							}

							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
							*/


						}


						/*
						else if (pieza_selec == "c1" && Interaccion::Comprobar_movimiento(*diosita, caballo[1]))//si se cumple la condicion
						{
							if (Interaccion::Comprobar_choque_piezas(*diosita, torre[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[1]) && Interaccion::Comprobar_choque_piezas(*diosita, rey[0]) && Interaccion::Comprobar_choque_piezas(*diosita, alfil[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[5]) && Interaccion::Comprobar_choque_piezas(*diosita, torre[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[3]) && Interaccion::Comprobar_choque_piezas(*diosita, dama[0]) && Interaccion::Comprobar_choque_piezas(*diosita, caballo[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[0]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[1]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[2]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[4]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[6]) && Interaccion::Comprobar_choque_piezas(*diosita, peon[7]))

							{
								diosita->Set_color('b');
								caballo[1].Set_color('b');

								introdatos = IntroDatos::EJE_X;
								movdatos = MovDatos::M_ESPERA;
								turno = Turno::CAMBIO;
							}
							else
							{
								diosita->Set_color('m');
								introdatos = IntroDatos::ESPERA;
								movdatos = MovDatos::M_EJE_X;
								turno = Turno::BLANCAS;
								ETSIDI::play("sonidos/disparo.wav");
							}
						}
						*/

						//si no se ha puesto una posicion alcanzable
						else //retrocedemos para volver a poner el sitio donde decimos a donde queremos mover la pieza
						{
							diosita->Set_color('m');
							ETSIDI::play("sonidos/disparo.wav");
							introdatos = IntroDatos::ESPERA;
							movdatos = MovDatos::M_EJE_X;
							turno = Turno::NEGRAS;
						}
					}
				}
			}
		}
	}
}




//MOVIMIENTOS DE PARTIDFA

void Partida::Mueve()
{
	//PARA CONOCER LA POSICION DE LA PIEZA QUE QUEREMOS MOVER

	if (turno == Turno::BLANCAS && introdatos == IntroDatos::ESPERA && movdatos == MovDatos::M_EJE_X  && control_selccion_pieza == 0)
	{
		posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);

		control_selccion_pieza = 1;
	}

	if (turno == Turno::NEGRAS && introdatos == IntroDatos::ESPERA && movdatos == MovDatos::M_EJE_X && control_selccion_pieza==0)
	{
		posicion_pieza_seleccionada = Interaccion::Seleccionar(*diosita);
		control_selccion_pieza = 1;//creemos que esto deberia ir aqui
	}


	//PARA MOVER LA PIEZA QUE ESTABA EN LA POSICION DE ANTES DONDE HAYAMOS MOVIDO A DIOSITA

	if (turno == Turno::CAMBIO)
	{
		control_selccion_pieza = 0;

		//se puede hacer con un for
		if (posicion_pieza_seleccionada == peon[0].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[0]);
		}
		if (posicion_pieza_seleccionada == peon[1].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[1]);
		}
		if (posicion_pieza_seleccionada == peon[2].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[2]);
		}
		if (posicion_pieza_seleccionada == peon[3].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[3]);
		}
		if (posicion_pieza_seleccionada == peon[4].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[4]);
		}
		if (posicion_pieza_seleccionada == peon[5].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[5]);
		}
		if (posicion_pieza_seleccionada == peon[6].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[6]);
		}
		if (posicion_pieza_seleccionada == peon[7].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[7]);
		}

		if (posicion_pieza_seleccionada == rey[0].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, rey[0]);
		}
		if (posicion_pieza_seleccionada == alfil[0].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, alfil[0]);
		}
		if (posicion_pieza_seleccionada == alfil[1].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, alfil[1]);
		}

		if (posicion_pieza_seleccionada == torre[0].Get_pos()) //&& Interaccion::Comprobar_movimiento(*diosita, torre[0])) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, torre[0]);
			
		}
		if (posicion_pieza_seleccionada == torre[1].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, torre[1]);
		}

		if (posicion_pieza_seleccionada == dama[0].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, dama[0]);
		}
		if (posicion_pieza_seleccionada == caballo[0].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, caballo[0]);
		}
		if (posicion_pieza_seleccionada == caballo[1].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, caballo[1]);
		}
	}



	if (turno == Turno::CAMBIO2)
	{

		control_selccion_pieza = 0;

		//mover negras
		if (posicion_pieza_seleccionada == peon[8].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[8]);
		}
		if (posicion_pieza_seleccionada == peon[9].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[9]);
		}
		if (posicion_pieza_seleccionada == peon[10].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[10]);
		}
		if (posicion_pieza_seleccionada == peon[11].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[11]);
		}
		if (posicion_pieza_seleccionada == peon[12].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[12]);
		}
		if (posicion_pieza_seleccionada == peon[13].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[13]);
		}
		if (posicion_pieza_seleccionada == peon[14].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[14]);
		}
		if (posicion_pieza_seleccionada == peon[15].Get_pos()) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, peon[15]);
		}

		if (posicion_pieza_seleccionada == rey[1].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, rey[1]);
		}
		if (posicion_pieza_seleccionada == alfil[2].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, alfil[2]);
		}
		if (posicion_pieza_seleccionada == alfil[3].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, alfil[3]);
		}

		if (posicion_pieza_seleccionada == torre[2].Get_pos()) //&& Interaccion::Comprobar_movimiento(*diosita, torre[0])) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, torre[2]);
		}
		if (posicion_pieza_seleccionada == torre[3].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, torre[3]);
		}

		if (posicion_pieza_seleccionada == dama[1].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, dama[1]);
		}
		if (posicion_pieza_seleccionada == caballo[2].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, caballo[2]);
		}
		if (posicion_pieza_seleccionada == caballo[3].Get_pos())// && Interaccion::Comprobar_movimiento(rey[0]) //con sobrecarga del operador == para comparar Vector3d
		{
			Interaccion::Desplazar(*diosita, caballo[3]);
		}
	}
}
