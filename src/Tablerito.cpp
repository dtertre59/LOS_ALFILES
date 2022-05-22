#include "Tablerito.h"
#include "Interaccion.h"

//CONSTRUCTOR
Tablerito::Tablerito()
{
	tablerito = new string * [8];
	for (int i = 0; i < 8; i++)
	{
		tablerito[i] = new string[8];
	}
}

//DESTRUCTOR
Tablerito::~Tablerito()
{
	for (int f = 0; f < 8; f++) {
		delete[] tablerito[f];
	}
	delete[] tablerito;
}


void Tablerito::Inicializa()
{
	for (int i = 0; i < 8; i++)   //flias
	{
		for (int j = 0; j < 8; j++)  //coliunns
		{
			tablerito[i][j] = "00000";  //FILA I , COLUMNA J
		}
	}

	//FIGURAS NEGRAS

	tablerito[0][0] = "NT18A"; //LA FILA 8 ES EN X=0; LA COLUMNA A ES EN Y=0;
	tablerito[0][1] = "NC18B";
	tablerito[0][2] = "NA18C";
	tablerito[0][3] = "ND18D";
	tablerito[0][4] = "NR18E";
	tablerito[0][5] = "NA28F";
	tablerito[0][6] = "NC28G";
	tablerito[0][7] = "NT28H";

	//PEONES NEGROS

	for (int i = 0; i < 8; i++)
	{
		tablerito[1][i] = "NP000";
		tablerito[1][i][2] = 49 + i;
		tablerito[1][i][3] = '7';
		tablerito[1][i][4] = 65 + i;
	}

	//PEONES BLANCOS

	for (int i = 0; i < 8; i++)
	{
		tablerito[6][i] = "BP000";
		tablerito[6][i][2] = 49 + i;
		tablerito[6][i][3] = '2';
		tablerito[6][i][4] = 65 + i;
	}

	//FIGURAS BLACAS

	tablerito[7][0] = "BT11A";
	tablerito[7][1] = "BC11B";
	tablerito[7][2] = "BA11C";
	tablerito[7][3] = "BD11D";
	tablerito[7][4] = "BR11E";
	tablerito[7][5] = "BA21F";
	tablerito[7][6] = "BC21G";
	tablerito[7][7] = "BT21H";
}


//sobrecarga de la funcion localizar pieza 
//te dice que pieza hay en la posicion. Devuelve el dni de la pieza

string Tablerito::Localizar_pieza(int x, int y)  //con la nomenclatura de la matriz
{
	int fila = x / 10;
	int columna = y / 10;

	return tablerito[fila][columna];
}

string Tablerito::Localizar_pieza(char x, char y) //con la nomenclaturadel tablero
{
	int fila;
	for (int i = 0, j = 7; i < 8; i++, j--)
	{
		if (x == 49 + i)
			fila = j;
	}
	int columna = y - 65;
	return tablerito[fila][columna];
}

string Tablerito::Localizar_pieza(Vector3d& mov)  //con la nomnclatura de la matriz
{
	int fila = mov.x / 10;
	int columna = mov.y / 10;

	return tablerito[fila][columna];
}

//COMPROBAR MOVIMIENTO, TE DEVUELVE UN NUMERO SEGUN LO QUE HAY EN LA CASILLA A DONDE MUEVAS

int Tablerito::Comprobar_posicion_movimiento(Pieza& pieza, Vector3d move)  //METR POSICION DE diosita
{

	char turno = pieza.dni[0];

	int fila = move.x / 10;
	int columna = move.y / 10;

	if (tablerito[fila][columna][0] == '0')
	{
		return 0;	//si no hay fichas
	}
	else if (((turno == 'B' && tablerito[fila][columna][0] == 'N') || (turno == 'N' && tablerito[fila][columna][0] == 'B')) && tablerito[fila][columna][1] != 'R') //si la ficha que hay es blanca
	{
		return 1;	//donde muevas va a comer una ficha del rival que no es el rey
	}
	else if (tablerito[fila][columna][1] == 'R')
	{
		return 2;	//si te comes el rey
	}
	else
		return 3; //no entra en ninguno
}

//COMPROBAR CAMINO

int Tablerito::Comprobar_camino(Pieza& pieza, Vector3d move)
{
	Vector3d pos_pieza = pieza.Get_pos();
	int pos_pieza_x = pos_pieza.x / 10;
	int pos_pieza_y = pos_pieza.y / 10;

	int pos_diosita_x = move.x / 10;
	int pos_diosita_y = move.y / 10;

	int dif_pos_x = pos_diosita_x - pos_pieza_x;
	int dif_pos_y = pos_diosita_y - pos_pieza_y;

	int flag = 1;


		if (pieza.dni[1] == 'C' || pieza.dni[1] == 'R')      //no importa el camino
			return 1; //pueden pasar

		else if (pieza.dni[1] == 'T')
		{


			if ((dif_pos_x > 0) && (dif_pos_y == 0))//hacia abajo
			{
				for (int i = pos_pieza_x + 1; i < pos_diosita_x; i++)
				{
					if (tablerito[i][pos_pieza_y][0] != '0')
						flag = 0;
				}
			}
			if (flag == 1)
			{
				for (int i = pos_pieza_x - 1; i > pos_diosita_x; i--)
				{
					if (tablerito[i][pos_pieza_y][0] != '0')
					{
						flag = 0;
					}
				}
			}
			else if ((dif_pos_y > 0) && (dif_pos_x == 0))//hacia ->
			{
				for (int i = pos_pieza_y + 1; i < pos_diosita_y; i++)
				{
					if (tablerito[pos_pieza_x][i][0] != '0')
					{
						flag = 0;
					}
				}
			}
			else if ((dif_pos_y < 0) && (dif_pos_x == 0))//hacia <-
			{
				for (int i = pos_pieza_y - 1; i > pos_diosita_y; i--)
				{
					if (tablerito[pos_pieza_x][i][0] != '0')
					{
						flag = 0;
					}
				}
			}
			if (flag == 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		else if (pieza.dni[1] == 'A')
		{
			if (dif_pos_x < 0 && dif_pos_y>0)//arriba ->
			{
				int d = 1;
				for (int i = pos_pieza_x - 1; i > pos_diosita_x; i--)
				{

					if (tablerito[i][pos_pieza_y + d][0] != '0')
					{

						flag = 0;
					}
					d++;
				}
			}
			else if (dif_pos_x < 0 && dif_pos_y < 0)//arriba <-
			{
				int d = 1;
				for (int i = pos_pieza_x - 1; i > pos_diosita_x; i--)
				{

					if (tablerito[i][pos_pieza_y - d][0] != '0')
					{

						flag = 0;
					}
					d++;
				}
			}
			else if (dif_pos_x > 0 && dif_pos_y > 0)//abajo ->
			{
				int d = 1;
				for (int i = pos_pieza_x + 1; i < pos_diosita_x; i++)
				{

					if (tablerito[i][pos_pieza_y + d][0] != '0')
					{

						flag = 0;
					}
					d++;
				}
			}
			else if (dif_pos_x > 0 && dif_pos_y < 0)//abajo <-
			{
				int d = 1;
				for (int i = pos_pieza_x + 1; i < pos_diosita_x; i++)
				{

					if (tablerito[i][pos_pieza_y - d][0] != '0')
					{

						flag = 0;
					}
					d++;
				}
			}
			if (flag == 1)
			{
				return 1;
			}
			else { return 0; }
		}

		else if (pieza.dni[1] == 'D')
		{
			//mov torre
			if ((dif_pos_x > 0) && (dif_pos_y == 0))//hacia abajo
			{
				for (int i = pos_pieza_x + 1; i < pos_diosita_x; i++)
				{
					if (tablerito[i][pos_pieza_y][0] != '0')
					{
						flag = 0;
					}
				}
			}
			else if ((dif_pos_x < 0) && (dif_pos_y == 0))//hacia arriiba
			{
				for (int i = pos_pieza_x - 1; i > pos_diosita_x; i--)
				{
					if (tablerito[i][pos_pieza_y][0] != '0')
					{
						flag = 0;
					}
				}
			}
			else if ((dif_pos_y > 0) && (dif_pos_x == 0))//hacia ->
			{
				for (int i = pos_pieza_y + 1; i < pos_diosita_y; i++)
				{
					if (tablerito[pos_pieza_x][i][0] != '0')
					{
						flag = 0;
					}
				}
			}
			else if ((dif_pos_y < 0) && (dif_pos_x == 0))//hacia <-
			{
				for (int i = pos_pieza_y - 1; i > pos_diosita_y; i--)
				{
					if (tablerito[pos_pieza_x][i][0] != '0')
					{
						flag = 0;
					}
				}
			}
			//mov alfil
			else if (dif_pos_x < 0 && dif_pos_y>0)//arriba ->
			{
				int d = 1;
				for (int i = pos_pieza_x - 1; i > pos_diosita_x; i--)
				{

					if (tablerito[i][pos_pieza_y + d][0] != '0')
					{

						flag = 0;
					}
					d++;
				}
			}
			else if (dif_pos_x < 0 && dif_pos_y < 0)//arriba <-
			{
				int d = 1;
				for (int i = pos_pieza_x - 1; i > pos_diosita_x; i--)
				{

					if (tablerito[i][pos_pieza_y - d][0] != '0')
					{

						flag = 0;
					}
					d++;
				}
			}
			else if (dif_pos_x > 0 && dif_pos_y > 0)//abajo ->
			{
				int d = 1;
				for (int i = pos_pieza_x + 1; i < pos_diosita_x; i++)
				{

					if (tablerito[i][pos_pieza_y + d][0] != '0')
					{

						flag = 0;
					}
					d++;
				}
			}
			else if (dif_pos_x > 0 && dif_pos_y < 0)//abajo <-
			{
				int d = 1;
				for (int i = pos_pieza_x + 1; i < pos_diosita_x; i++)
				{

					if (tablerito[i][pos_pieza_y - d][0] != '0')
					{

						flag = 0;
					}
					d++;
				}
			}
			//mov alfil
			if (flag == 1)
			{
				return 1;
			}
			else { return 0; }//return 0; //si no puede pasar

		}
		else if (pieza.dni[1] == 'P')
		{
			if (tablerito[pos_pieza_x][pos_pieza_y][3] == '7' && tablerito[pos_pieza_x][pos_pieza_y][0]=='B')
			{
				if (tablerito[pos_pieza_x - 1][pos_pieza_y][0] != '0')
				{
					flag = 0;
				}
			}
			else if (tablerito[pos_pieza_x][pos_pieza_y][3] == '2' && tablerito[pos_pieza_x][pos_pieza_y][0] == 'N')
			{
				if (tablerito[pos_pieza_x + 1][pos_pieza_y][0] != '0')
				{
					flag = 0;
				}
			}
		}

		if (flag == 1)
		{
			return 1;
		}
		else { return 0; }
		
		
}



//COMPROBAR TODOS LOS TIPOS DE MOVIMIENTO, VER SI SE PUEDE MOVER, ver aquin COMER y si se come al REY

int Tablerito::Comprobar_movimiento_completo(Pieza& pieza, Vector3d move)
{
	char turno = pieza.dni[0]; //te dice si es blaca B o negra N el turno

	int flag_posicion_movimiento = Tablerito::Comprobar_posicion_movimiento(pieza, move); //te dice que hay en la casilla a donde te mueves

	int flag_camino = Tablerito::Comprobar_camino(pieza, move);  //te dice si esta permitido el camino

	if (flag_camino == 0)
	{
		return 0; //no se puede pasar y se debe volver a seleccionar la casilla a donde vas a mover
	}
	else if (flag_camino == 1) //si se puede mover tode menosla excepcion del peon
	{
		
		if (pieza.Movimiento(move) && flag_posicion_movimiento == 0) //si se puede mover, comprobar camino
		{
			if (pieza.dni[1] == 'P')
			{
				if (move.y == pieza.posicion.y)
				{
					return 1;
				}
				else
					return 0; //no mover
			}
			else
			{
				return 1;
			}
		}
		else if (pieza.Movimiento(move) && flag_posicion_movimiento == 1) //si donde mueves come
		{
			if (pieza.dni[1] == 'P')
			{
				if (move.y != pieza.posicion.y)
				{
					return 2;
				}
				else
					return 0;
			}
			else
			{
				return 2; //donde se mueva COME
			}			
		}
		else if (pieza.Movimiento(move) && flag_posicion_movimiento == 2) //COME REY
		{
			return 4; //come rey, jaque
		}
		
		else if (pieza.Movimiento(move) && flag_posicion_movimiento == 3) 
		{
			return 0; 
		}		
	}
}


//MOVER FICHA EN TABLERITO, te cambia el dni de la pieza

void Tablerito::Mover(string& pieza, char x, char y)
{
	//a donde mueves
	int fila;
	for (int i = 0, j = 7; i < 8; i++, j--)
	{
		if (x == 49 + i)
			fila = j;
	}
	int columna = y - 65;

	//cambiar el tablerito con la pieza movida
	tablerito[fila][columna] = pieza;
	tablerito[fila][columna][3] = x;
	tablerito[fila][columna][4] = y;


	//poner a 0 en tablerito la posicion pasada

	char fila_anterior = pieza[3];
	char columna_anterior = pieza[4];
	int fila_ant = 0;
	int columna_ant = 0;

	for (int i = 0, j = 7; i < 8; i++, j--)
	{
		if (fila_anterior == 49 + i)
			fila_ant = j; //bien
		if (columna_anterior == 65 + i)
			columna_ant = i;
	}

	//cambiar el dni de la pieza
	pieza[3] = tablerito[fila][columna][3] = x;
	pieza[4] = tablerito[fila][columna][4] = y;

	tablerito[fila_ant][columna_ant] = "00000";
}



void Tablerito::Mover(Pieza& pieza, Vector3d diosita_pos)
{
	//a donde mueves

	int x = diosita_pos.x / 10;
	int y = diosita_pos.y / 10;

	char fila = '0';

	//cambiar el tablerito con la pieza movida
	tablerito[x][y] = pieza.dni;


	for (int i = 0, j = 8; i < 8; i++, j--) //para la fila, que va al reves
	{
		if (x == i)
			fila = j + 48;
	}

	tablerito[x][y][3] = fila;
	tablerito[x][y][4] = y + 65;

	//poner a 0 en tablerito la posicion pasada

	char fila_anterior = pieza.dni[3];
	char columna_anterior = pieza.dni[4];
	int fila_ant = 0;
	int columna_ant = 0;

	for (int i = 0, j = 7; i < 8; i++, j--)
	{
		if (fila_anterior == 49 + i)
			fila_ant = j; //bien
		if (columna_anterior == 65 + i)
			columna_ant = i;
	}

	//cambiar el dni de la pieza
	pieza.dni = tablerito[x][y];

	tablerito[fila_ant][columna_ant] = "00000";
}


//IMPRESION POR PANTALLA DE LA MATRIZ TABLERITO

ostream& Tablerito::to_string(ostream& o)
{
	for (int i = 0; i < 8; i++)   //flias
	{
		for (int j = 0; j < 8; j++)  //coliunns
		{
			o << tablerito[i][j] << " ";
		}
		o << endl;
	}
	return o;

}