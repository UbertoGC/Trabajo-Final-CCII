#ifndef __ESTRUCTURA_H__
#define __ESTRUCTURA_H__

#include "base_game_CR.h"
#include "player.h"

class estructura : public base_game_CR {
	friend class player;
protected:
	int posX;
	int posY;
	int velX;
	ALLEGRO_BITMAP* image;
	bool solid;
public:
	explicit estructura(int _initposX = 0, int _initposY = 0, int _initVelX = 5, ALLEGRO_BITMAP* _initImage = nullptr, bool _initSolid = false)
		: posX(_initposX), posY(_initposY), velX(_initVelX), image(_initImage), solid(_initSolid) {}
	void initDefault();
	void pinta();
};

#endif
