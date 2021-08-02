#include "player.h"

bool jump = false;
const float gravity = 4;
float velY = 0;
float jumpSpeed = 35;

void player::inicia(escenario _playerEscenario) {
	imgPlayer = al_load_bitmap("personaje.png");
	tiempoPaso = int(_playerEscenario.getFPS() / getMueve());
	tiempoCont = 0;
	posX = 100;
	posY = 380;
	direccion = 0;
	paso = 0;
}

void player::teclas() {
    desplazamiento = 6;
    ALLEGRO_KEYBOARD_STATE teclado;
    al_get_keyboard_state(&teclado);

    if (al_key_down(&teclado, ALLEGRO_KEY_UP) && jump) {
        velY = -jumpSpeed;
        jump = false;
    }
    else if (al_key_down(&teclado, ALLEGRO_KEY_DOWN)) {
        direccion = 0;
        tiempoCont++;
    }
    else if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)) {
        direccion = 1;
        posX -= desplazamiento;
        tiempoCont++;
    }

    else if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)) {
        direccion = 2;
        posX += desplazamiento;
        tiempoCont++;
    }

    if (!jump)
        velY += gravity;
    else
        velY = 0;
    
    posY += velY;   

    jump = (posY + 80 >= 560);

    if (jump)
        posY = 560 - 80;

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
int& player::posiX() {
    return posX;
}
int& player::posiY() {
    return posY;
}
void player::cambio(int a) {
    if (a == 1) {
        estado[0] = true;
    }
    else if (a == 2) {
        estado[1] = true;
    }
    if (estado[0] && estado[1]) {
        imgPlayer = al_load_bitmap("personaje(mascarilla-escudo).png");
    }
    else if (!estado[0] && estado[1]) {
        imgPlayer = al_load_bitmap("personaje(escudo).png");
    }
    else if (estado[0] && !estado[1]) {
        imgPlayer = al_load_bitmap("personaje(mascarilla).png");
    }
    else {
        imgPlayer = al_load_bitmap("personaje.png");
    }
}
int &player::vida() {
    return lifePoints;
}
void player::contagio() {
    if (!estado[0]) {
        lifePoints--;
    }
}
void player::pinta() {
    al_draw_bitmap_region(imgPlayer, paso * 48, direccion * 48, 48, 48, posX, posY, 0);
}


