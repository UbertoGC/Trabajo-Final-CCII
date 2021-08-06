#include "escudo.h"
escudo::escudo(int _posX) {
    imgobj = al_load_bitmap("escudo.png");
    posX = _posX;
    posY = 476;
    desplazamiento = 8;
    duracion = 20*60;
    tipo = 2;
}
