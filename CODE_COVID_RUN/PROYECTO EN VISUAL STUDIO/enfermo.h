#ifndef __ENFERMO_H__
#define __ENFERMO_H__

#include "player.h"
#include "escenario.h"
#include <string>

class enfermo:public character {

protected:
	//VARIABLES DEL JUGADOR
	int posX, posY;
	int direccion;
	int movimiento = 2;
	ALLEGRO_BITMAP* imgenemigo;
	int tiempoPaso;
	int tiempoCont = 0;
	int paso=1;
	int afeccion = 0;
	bool movi[2];
	bool jump2 = false;
	const float gravity2 = 4;
	float velY2 = 0;
	float jumpSpeed2 = 35;

public:
	enfermo(escenario _playerEscenario, bool _par1, bool _par2, int _initX){
		imgenemigo = al_load_bitmap("enfermo.png");
		tiempoPaso = int(_playerEscenario.getFPS() / getMueve());
		tiempoCont = 0;
		posX = _initX;
		posY = 480;
		direccion = 0;
		paso = 1;
		movi[0] = _par1;
		movi[1] = _par2;
	}
	void efecto(player&);
	int posiX() { return posX; }
	void movienf(int, int);
	void pinta();
};
#endif