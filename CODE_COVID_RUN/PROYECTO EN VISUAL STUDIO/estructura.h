#ifndef __ESTRUCTURA_H__
#define __ESTRUCTURA_H__

#include "base_game_CR.h"

class estructura : public base_game_CR {
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
	void movi(int,int);
	int posiX();
	int posiY();
	void pinta();
    estructura& operator=(estructura p) {
        if (this != &p) {
			this->velX = p.velX;
            this->posX = p.posX;
            this->posY = p.posY;
            this->image = al_load_bitmap("plataforma.png");
        }
        return *this;
    }
    bool operator==(const estructura& p)const {
        return (this->posY == p.posY && this->posX == p.posX);
    }
};

#endif
