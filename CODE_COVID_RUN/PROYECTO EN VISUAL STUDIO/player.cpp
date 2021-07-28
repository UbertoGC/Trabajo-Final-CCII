#include "player.h"

void player::inicia(escenario _playerEscenario) {
	imgPlayer = al_load_bitmap("personaje.png");
	tiempoPaso = int(_playerEscenario.getFPS() / getMueve());
	tiempoCont = 0;
	posX = 100;
	posY = 480;
	direccion = 0;
	paso = 0;
}

void player::teclas() {

    ALLEGRO_KEYBOARD_STATE teclado;
    al_get_keyboard_state(&teclado);

    if (al_key_down(&teclado, ALLEGRO_KEY_UP)) {
        posY -= desplazamiento;
        direccion = 3;
        tiempoCont++;
    }

    if (al_key_down(&teclado, ALLEGRO_KEY_DOWN)) {
        posY += desplazamiento;
        direccion = 0;
        tiempoCont++;
    }

    if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)) {
        posX -= desplazamiento;
        direccion = 1;
        tiempoCont++;
    }

    if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)) {
        posX += desplazamiento;
        direccion = 2;
        tiempoCont++;
    }

    // limitadores
    if (posX < 0) posX = 0;
    if (posX > 800 - 48) posX = 800 - 48;
    if (posY < 0) posY = 0;
    if (posY > 600 - 48) posY = 600 - 48;

    if (tiempoCont > tiempoPaso) {
        paso++;
        tiempoCont = 0;
    }

    if (paso > 2) paso = 0;
}

void player::pinta() {
    al_draw_bitmap_region(imgPlayer, paso * 48, direccion * 48, 48, 48, posX, posY, 0);
}
