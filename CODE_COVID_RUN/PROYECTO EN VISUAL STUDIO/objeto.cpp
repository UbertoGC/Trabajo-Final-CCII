#include "objeto.h"
void objeto::movi() {
    ALLEGRO_KEYBOARD_STATE teclado;
    al_get_keyboard_state(&teclado);

    if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)) {
        posX += desplazamiento;
    }
    else if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)) {
        posX -= desplazamiento;
    }
}
void objeto::pinta() {
    al_draw_bitmap(imgobj, posX, posY, 0);
}
int objeto::efecto(player &_player){
    return 0;
}
