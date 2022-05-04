#include "caja.h"

caja::caja()
{
	suelo.setColor(31, 199, 33);
	suelo.setPos(-10.0f, 80.0f, 80.0f, 80.0f);

	techo.setColor(0,255,255);
	techo.setPos(80.0f, -10.0f, -10.0f, -10.0f);
	
	pared_dcha.setColor(0,100,255);
	pared_dcha.setPos(-10.0f, -10.0f, -10.0f, 80.0f);

	pared_izq.setColor(0,100,255);
	pared_izq.setPos(80.0f, -10.0f, 80.0f, 80.0f);

	
}
void caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_dcha.dibuja();
	//pared_izq.dibuja();
}