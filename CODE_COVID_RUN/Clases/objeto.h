
#ifndef __OBJETO_H__
#define __OBJETO_H__
#include "player.h"

class objeto {

protected:
	//VARIABLES DEL OBJETO
	int tipo=0;
	int duracion=0;
	bool uso=false;
	int posX=0, posY=0;
	int desplazamiento=6;
	ALLEGRO_BITMAP* imgobj=nullptr;

public:
	void moviobj(int, int);
	void pinta();
	virtual void efecto(player&);
	virtual void finalobj(player&);
	bool usandose();
	int durarest();
	void bajandotiem();
	int tipoclase();
	int posiX();
	void cambiodura(int);
	bool operator==(objeto p);
	objeto& operator=(objeto p);
};
#endif

