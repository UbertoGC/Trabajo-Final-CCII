#include "escudo.h"
escudo::escudo(int _posX) {
    imgobj = al_load_bitmap("escudo.png");
    posX = _posX;
    posY = 476;
    desplazamiento = 6;
    duracion = 6*60;
    tipo = 2;
}
void escudo::reinicio(int x, int y) {
    if (imgobj != nullptr) {
        al_destroy_bitmap(imgobj);
    }
    imgobj = al_load_bitmap("escudo.png");
    posX = x;
    posY = y;
    desplazamiento = 6;
    duracion = 6 * 60;
    tipo = 1;
}
