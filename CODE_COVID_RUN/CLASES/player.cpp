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
    desplazamiento = 4;
    ALLEGRO_KEYBOARD_STATE teclado;
    al_get_keyboard_state(&teclado);

    if (al_key_down(&teclado, ALLEGRO_KEY_UP) && jump) {
        direccion = 3;
        cout << "JUMPING" << endl;
        velY = -jumpSpeed;
        jump = false;
    }
    else if (al_key_down(&teclado, ALLEGRO_KEY_DOWN)) {
        posY += desplazamiento;
        direccion = 0;
        tiempoCont++;
    }
    else if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)) {
        posX -= desplazamiento;
        direccion = 1;
        tiempoCont++;
    }

    else if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)) {
        posX += desplazamiento;
        direccion = 2;
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
    cout << posX << " " << posY << endl;
}

void player::pinta() {
    al_draw_bitmap_region(imgPlayer, paso * 48, direccion * 48, 48, 48, posX, posY, 0);
}
