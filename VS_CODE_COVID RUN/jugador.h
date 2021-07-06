#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "character.h"
class jugador : public character{
protected:
	int x=0, y=0;
	int dir=0;
	int paso=0;
	int tiempoPaso=0;
	int tiempoCont=0;
public:
	ALLEGRO_BITMAP* img;
	int desplaza = 2;
	int mueve = 18;
	void inicial();
	void teclas(ALLEGRO_EVENT);
	void pinta();
	struct {
		int FPS;
		ALLEGRO_EVENT_QUEUE* Mis_eventos;
		ALLEGRO_COLOR fondo;
	} sistema;

}jugador;

#endif

