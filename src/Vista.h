#pragma once
#include"Vector3d.h"

class Vista 
{
	private:
		Vector3d posicion_ojo;
		Vector3d mira_ojo;
		float distancia;
		float distancia_plana;
		float angulo;
		float angulo_plano;

	public:
		Vista();
		Vista(int v);
		void Inicializa();
		void Set_vista(float px, float py, float pz, float mx, float my, float mz);
		void Camara();
		void Camara(int opt);
		void Mover(unsigned char key);
};