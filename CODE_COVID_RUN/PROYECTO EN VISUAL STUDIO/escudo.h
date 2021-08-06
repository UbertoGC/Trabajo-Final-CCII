#ifndef __ESCUDO_H__
#define __ESCUDO_H__

#include "objeto.h"

class escudo : public objeto {

public:
    escudo() {}
    void reinicio(int, int);
    escudo(int);
    void efecto(player& _player) {
        if (_player.getposX() + 30 >= posX && _player.getposX() <= posX + 40 && _player.getposY() <= posY+56 && _player.getposY()+44>=posY) {
            _player.cambio(2);
            uso = true;
        }
    }
    void finalobj(player& _player) {
        _player.cambio(4);
    }
    escudo& operator=(escudo p) {
        this->tipo = p.tipo;
        this->duracion = p.duracion;
        this->posX = p.posX;
        this->posY = p.posY;
        this->uso = p.uso;
        this->desplazamiento = p.desplazamiento;
        this->imgobj = al_load_bitmap("escudo.png");
        return *this;
    }
    bool operator==(const escudo& p)const {
        return (this->tipo == p.tipo && (this->posX == p.posX && this->posY == p.posY));
    }
};
#endif
