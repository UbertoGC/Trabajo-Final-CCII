#ifndef __ESCUDO_H__
#define __ESCUDO_H__

#include "objeto.h"

class escudo : public objeto {

public:
    escudo(int);
    int efecto(player& _player) {
        if (_player.posiX() + 24 >= posX && _player.posiX() <= posX + 46 && _player.posiY() -4 == posY) {
            _player.cambio(2);
            return 1;
        }
        else {
            return 0;
        }
    }

};
#endif
