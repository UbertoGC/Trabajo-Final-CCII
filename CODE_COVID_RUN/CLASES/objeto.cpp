#include "objeto.h"
void objeto::pinta() {
    al_draw_bitmap(imgobj, posX, posY, 0);
}
int objeto::efecto(player &_player){
    return 0;
}
