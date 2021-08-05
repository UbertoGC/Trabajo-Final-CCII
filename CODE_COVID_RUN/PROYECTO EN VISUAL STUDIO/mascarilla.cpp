#include "mascarilla.h"
mascarilla::mascarilla(int _posX) {
    imgobj = al_load_bitmap("mascarilla.png");
    posX = _posX;
    posY = 482;
    desplazamiento = 8;
    duracion = 15;
    tipo = 1;
}
