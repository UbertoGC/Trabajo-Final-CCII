#ifndef __ESTRUCTURAS_H__
#define __ESTRUCTURAS_H_

#include "base_game_CR.h"
#include "player.h"


class estructuras : public base_game_CR {
private:
	int posX;
	int posY;
	int velX;
	ALLEGRO_BITMAP* image;
	bool solid;
public:
	estructuras(int _initposX = 0, int _initposY = 0, int _initVelX = 5, ALLEGRO_BITMAP* _initImage = nullptr, bool _initSolid = false)
		: posX(_initposX), posY(_initposY), velX(_initVelX), image(_initImage), solid(_initSolid) {}
	void initDefault() {
		srand(time(NULL));
		posX = 1 + rand() % (750);
		posY = 83 + rand() % (565);
	}
	void pinta(int _posX) {
		//al_draw_bitmap();
	}

};

#endif
