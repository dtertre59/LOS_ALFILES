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
		
		//fondo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/inicio.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-25, 30, -5);
		glTexCoord2d(1, 1); glVertex3f(20, 30, -5);
		glTexCoord2d(1, 0); glVertex3f(  20, -10, -5);
		glTexCoord2d(0, 0); glVertex3f(-25, -10, -5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		/// 
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/fast99.ttf", 28);
		ETSIDI::printxy("AJEDREZ", -4, 11);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/White On Black.ttf", 15);
		ETSIDI::printxy("PULSA -P- PARA EMPEZAR PARTIDA MULTIJUGADOR", -12, 7.5);
		ETSIDI::printxy("PULSA -V- PARA VER PIEZAS", -12, 5.5);
		ETSIDI::printxy("PULSA -C- PARA VER CONTOLES", -12, 2.5);
		ETSIDI::printxy("PULSA -ESC- PARA SALIR", -12, 1.5);
		
	}

	else if (estado == Estado::PARTIDA_M)
	{	
		partida->Dibuja();
		// pared fondo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-8, -18, -5);
		glTexCoord2d(1, 1); glVertex3f(-8, 87, -5);
		glTexCoord2d(1, 0); glVertex3f(-8, 87, 37);
		glTexCoord2d(0, 0); glVertex3f(-8, -18, 37);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//pared lado <-
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/madera.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(80, -15, -5);
		glTexCoord2d(1, 1); glVertex3f(-8, -15, -5);
		glTexCoord2d(1, 0); glVertex3f(-8, -15, 40);
		glTexCoord2d(0, 0); glVertex3f(80, -15, 40);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//pared lado->
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pared.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-8, 85, -5);
		glTexCoord2d(1, 1); glVertex3f(80, 85, -5);
		glTexCoord2d(1, 0); glVertex3f(80, 85, 40);
		glTexCoord2d(0, 0); glVertex3f(-8, 85, 40);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//suelo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/madera.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-8, 85, -1);
		glTexCoord2d(1, 1); glVertex3f(80, 85, -1);
		glTexCoord2d(1, 0); glVertex3f(80, -15, -1);
		glTexCoord2d(0, 0); glVertex3f(-8, -15, -1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

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
		partida->Dibuja();
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
		//fondo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/inicio.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-25, 30, -5);
		glTexCoord2d(1, 1); glVertex3f(20, 30, -5);
		glTexCoord2d(1, 0); glVertex3f(20, -10, -5);
		glTexCoord2d(0, 0); glVertex3f(-25, -10, -5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/fast99.ttf", 20);
		ETSIDI::printxy("CONTROLES", -4, 13);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("PULSA -ESC- PARA VOLVER al inicio", -13, 10);
		ETSIDI::printxy("Por TECLADO introduzca primero NUMERO y despues LETRA ", -13, 8);
		ETSIDI::printxy("de la ubicacion de la pieza que desee mover ", -13, 7);
		ETSIDI::printxy("Presione RETURN para cambiar la pieza seleccioanda ", -13, 5);
		ETSIDI::printxy("Presione ESPACIO para cambiar de turno ", -13, 4);
		ETSIDI::printxy("Despues, introduzca la POSICION a la que desees MOVER la pieza ", -13, 2);
		ETSIDI::printxy("indicando primero NUMERO y luego LETRA ", -13, 1); 

	}

	else if (estado == Estado::PAUSA)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/inicio.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-25, 30, -5);
		glTexCoord2d(1, 1); glVertex3f(20, 30, -5);
		glTexCoord2d(1, 0); glVertex3f(20, -10, -5);
		glTexCoord2d(0, 0); glVertex3f(-25, -10, -5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

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