#ifndef __OBJETO_H__
#define __OBJETO_H__

#include "player.h"

class objeto {

protected:
	//VARIABLES DEL OBJETO
	int posX, posY;
	int desplazamiento;
	ALLEGRO_BITMAP* imgobj;

public:
	void pinta();
	virtual int efecto(player&);
};
#endif