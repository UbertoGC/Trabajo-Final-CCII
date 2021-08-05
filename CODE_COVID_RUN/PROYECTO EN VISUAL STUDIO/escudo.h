#ifndef __ESCUDO_H__
#define __ESCUDO_H__

#include "objeto.h"

class escudo : public objeto {

public:
    escudo(int);
    void efecto(player& _player) {
        if (_player.getposX() + 30 >= posX && _player.getposX() <= posX + 40 && _player.getposY() - 4 == posY) {
            _player.cambio(2);
            uso = true;
        }
    }
    void finalobj(player& _player) {
        _player.cambio(4);
    }
};
#endif
