#include "escudo.h"
escudo::escudo(int _posX) {
    imgobj = al_load_bitmap("escudo.png");
    posX = _posX;
    posY = 476;
    desplazamiento = 8;
}