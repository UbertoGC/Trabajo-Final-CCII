#include "mascarilla.h"
mascarilla::mascarilla(int _posX) {
    imgobj = al_load_bitmap("mascarilla.png");
    posX = _posX;
    posY = 482;
    desplazamiento = 6;
    duracion = 6*60;
    tipo = 1;
}
void mascarilla::reinicio(int _posx,int _posy) {
    this->posX = _posx;
    this->posY = _posy;
    this->desplazamiento = 6;
    this->duracion = 6 * 60;
    this->tipo = 1;
}
