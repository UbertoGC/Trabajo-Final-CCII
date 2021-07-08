#include "jugador.h"

jugador::jugador(){
    this->x = 0;
    this->y = 0;
    this->dir = 0;
    this->paso = 0;
    this->tiempoPaso = 0;
    this->tiempoCont = 0;
}
void jugador::inicia(escenario c_run)
{
	img = al_load_bitmap("personaje.png");
	tiempoPaso = int(c_run.get_fps() / getMueve());
    tiempoCont = 0;
    x = 100;
    y = 50;

    dir = 0;
    paso = 0;
}

void jugador::teclas(ALLEGRO_EVENT evento)
{
    ALLEGRO_KEYBOARD_STATE teclado;
    al_get_keyboard_state(&teclado);

    if (al_key_down(&teclado, ALLEGRO_KEY_UP)){
        y -= desplaza;
        dir = 3;
        tiempoCont++;
    }

    if (al_key_down(&teclado, ALLEGRO_KEY_DOWN)){
        y += desplaza;
        dir = 0;
        tiempoCont++;
    }

    if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)){
        x -= desplaza;
        dir = 1;
        tiempoCont++;
    }

    if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)){
        x += desplaza;
        dir = 2;
        tiempoCont++;
    }

    // limitadores
    if (x < 0) x = 0;
    if (x > 800 - 48) x = 800 - 48;
    if (y < 0) y = 0;
    if (y > 600 - 48) y = 600 - 48;
    if (tiempoCont > tiempoPaso){
        paso++;
        tiempoCont = 0;
    }

    if (paso > 2) paso = 0;

}

void jugador::pinta(){
    al_draw_bitmap_region(img, paso * 48, dir * 48, 48, 48, x, y, 0);
}
