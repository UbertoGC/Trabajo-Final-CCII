#ifndef __MASCARILLA_H__
#define __MASCARILLA_H__

#include "objeto.h"

class mascarilla : public objeto {

public:
    mascarilla(int);
    int efecto(player& _player) {
        if (_player.getposX() + 24 >= posX && _player.getposX() <= posX + 24 && _player.getposY() + 2 == posY) {
            _player.cambio(1);
            return 1;
        }
        else {
            return 0;
        }
    }

};
#endif

