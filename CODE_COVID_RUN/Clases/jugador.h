#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "character.h"
#include "escenario.h"

class jugador : public character {
protected:
	int x, y;
	int dir;
	int paso;
	int tiempoPaso;
	int tiempoCont;
	ALLEGRO_BITMAP* img;
public:
	jugador();
	void inicia(escenario);
	void teclas(ALLEGRO_EVENT);
	void pinta();

};
#endif