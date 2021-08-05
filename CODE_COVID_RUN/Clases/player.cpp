#include "player.h"

void player::inicia(escenario _playerEscenario) {
    imgPlayer = al_load_bitmap("personaje.png");
    tiempoPaso = int(_playerEscenario.getFPS() / getMueve());
    tiempoCont = 0;
    posX = 100;
    posY = 380;
    direccion = 0;
    paso = 0;
}

void player::registrarColision(estructura _estructura) {
    colisiones.push_back(_estructura);
}

void player::hasColision() {
    for (int i = 0; i < colisiones.size(); i++) {
        if (posX + 30 >= colisiones[i].posX && posX <= colisiones[i].posX + 150) {
            if (posY + 48 >= colisiones[i].posY && posY <= colisiones[i].posY + 15) {
                solidGround = true;
            }
        }
    }
}

int player::teclas() {
    int m = 0;
    desplazamiento = 6;
    ALLEGRO_KEYBOARD_STATE teclado;
    al_get_keyboard_state(&teclado);
    this->hasColision();
    if (al_key_down(&teclado, ALLEGRO_KEY_UP) && solidGround) {
        velY = -jumpSpeed;
        solidGround = false;
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

    if (!solidGround)
        velY += gravity;
    else
        velY = 0;

    posY += velY;

    solidGround = (posY + 80 >= 560);

    if (solidGround)
        posY = 560 - 80;

    // limitadores
    if (posX < 200) {
        posX = 200;
        m = 1;
    }
    if (posX > 800 - 200) {
        posX = 800 - 200;
        m = 2;
    }

    if (posY < 0) posY = 0;
    if (posY > 600 - 48) posY = 600 - 48;

    if (tiempoCont > tiempoPaso) {
        paso++;
        tiempoCont = 0;
    }

    if (paso > 2) paso = 0;
    return m;
}

void player::cambio(int a) {
    if (a == 1) {
        estado[0] = true;
    }
    else if (a == 2) {
        estado[1] = true;
    }
    else if (a >= 3) {
        if (estado[1]) {
            estado[1] = false;
        }
        else {
            lifePoints -= 4;
            if (lifePoints <= 0) {
                lifePoints = 0;
            }
        }
    }
    al_destroy_bitmap(imgPlayer);
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

int& player::vida() {
    return lifePoints;
}

void player::contagio() {
    if (!estado[0] && lifePoints != 0) {
        lifePoints--;
    }
}

void player::pinta() {
    al_draw_bitmap_region(imgPlayer, paso * 48, direccion * 48, 48, 48, posX, posY, 0);
    for (int i = 0; i < colisiones.size(); i++) {
        colisiones[i].pinta();
    }
}

bool player::choquescud() {
    return choquescudo;
}
