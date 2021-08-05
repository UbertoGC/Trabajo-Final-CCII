
#ifndef __OBJETO_H__
#define __OBJETO_H__

#include "player.h"

class objeto {

protected:
	//VARIABLES DEL OBJETO
	int tipo;
	int duracion;
	bool uso=false;
	int posX, posY;
	int desplazamiento;
	ALLEGRO_BITMAP* imgobj;

public:
	void moviobj(int, int);
	void pinta();
	virtual void efecto(player&);
	virtual void finalobj(player&);
	bool usandose();
	int durarest();
	void bajandotiem();
	int tipoclase();
	void cambiodura(int);
};
#endif

