#pragma once
#include"ETSIDI.h"
#include"Partida.h"
#include"Vista.h"
#include"Visualizar_piezas.h"

class Coordinador_ajedrez
{
private:

	unsigned char pi;

protected:

	enum class Estado { PREINICIO, INICIO, PARTIDA_M, VISTA_PIEZA, CONTROLES, PAUSA, EXIT };
	Estado estado;

	Partida *partida;
	Visualizar_piezas* visualizarp;
	Vista vista;

public:

	Coordinador_ajedrez();
	~Coordinador_ajedrez();

	void Inicializa();
	void Dibuja();
	void Tecla(unsigned char key);
	void mueve();
};




