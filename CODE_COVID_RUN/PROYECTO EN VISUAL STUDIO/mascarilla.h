#ifndef __MASCARILLA_H__
#define __MASCARILLA_H__

#include "objeto.h"

class mascarilla : public objeto {

public:
    mascarilla() {}
    void reinicio(int,int);
    mascarilla(int);
    void efecto(player& _player) {
        if (_player.getposX() + 24 >= posX && _player.getposX() <= posX + 24 && _player.getposY() + 2 >= posY&&_player.getposY()-2<=posY+40) {
            _player.cambio(1);
            uso = true;
        }
    }
    void finalobj(player& _player) {
        _player.cambio(3);
    }
    mascarilla& operator=(mascarilla p) {
        if (this != &p) {
            this->tipo = p.tipo;
            this->duracion = p.duracion;
            this->posX = p.posX;
            this->posY = p.posY;
            this->uso = p.uso;
            this->desplazamiento = p.desplazamiento;
            this->imgobj = al_load_bitmap("mascarilla.png");
        }
        return *this;
    }
    bool operator==(const mascarilla &p)const {
        return (this->posX == p.posX && this->posY == p.posY);
    }
};
#endif