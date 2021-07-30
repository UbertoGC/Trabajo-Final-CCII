#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "character.h"
#include "escenario.h"

class player : public character {

protected:
	//VARIABLES DEL JUGADOR
	int posX, posY;
	int direccion;
	int paso;
	int tiempoPaso;
	int tiempoCont;
	ALLEGRO_BITMAP* imgPlayer;

	//VARIABLE DE INTERACCION CON EL ESCENARIO
	bool mayJumpAgain = false;
	bool isOnSolidGround = false;

public:
	player(int _initX = 100, int _initY = 480, int _initDirec = 0, int _initPaso = 0, int _initTiempoPaso = 0, int _initTiempoCont = 0, ALLEGRO_BITMAP* initImg = nullptr) :
		posX(_initX), posY(_initY), direccion(_initDirec), paso(_initPaso), tiempoPaso(_initTiempoPaso), tiempoCont(_initTiempoCont), imgPlayer(initImg) {}
	void inicia(escenario);
	void teclas();
	void cambio();
	void pinta();
	int posiX();
	int posiY();
};

#endif