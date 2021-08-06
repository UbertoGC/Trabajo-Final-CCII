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
	bool salto=true;
	// VARIABLES DE INTERACCION CON EL ESCENARIO
	bool goBack = false;
	bool solidGround = false;
	const float gravity = 3.5;
	float velY = 0;
	float jumpSpeed = 35;
	ALLEGRO_BITMAP* imgPlayer;

	//VARIABLE DE INTERACCION CON OBJETOS
	bool estado[2] = { false,false };
	bool choquescudo = false;

public:
	player(int _initX = 100, int _initY = 480, int _initDirec = 0, int _initPaso = 0, int _initTiempoPaso = 0, int _initTiempoCont = 0, ALLEGRO_BITMAP* _initImg = nullptr) :
		posX(_initX), posY(_initY), direccion(_initDirec), paso(_initPaso), tiempoPaso(_initTiempoPaso), tiempoCont(_initTiempoCont), imgPlayer(_initImg) {}

	void inicia(escenario);
	// void teclas();
	int teclas();
	int getposX() { return posX; }
	int getposY() { return posY; }
	void cambio(int);
	void pinta();
	void contagio();
	void hasColision();
	int& vida();
	bool choquescud();
};

#endif