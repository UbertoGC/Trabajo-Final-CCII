#include "mascarilla.h"
mascarilla::mascarilla(int _posX) {
    imgobj = al_load_bitmap("mascarilla.png");
    posX = _posX;
    posY = 482;
    desplazamiento = 8;
}