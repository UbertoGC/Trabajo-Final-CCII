#ifndef __MASCARILLA_H__
#define __MASCARILLA_H__

#include "objeto.h"

class mascarilla : public objeto {

public:
    mascarilla(int);
    void efecto(player& _player) {
        if (_player.getposX() + 24 >= posX && _player.getposX() <= posX + 24 && _player.getposY() + 2 == posY) {
            _player.cambio(1);
            uso = true;
        }
    }
    void finalobj(player& _player) {
        _player.cambio(3);
    }

};
#endif