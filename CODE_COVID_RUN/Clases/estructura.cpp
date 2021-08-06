#include "estructura.h"

void estructura::initDefault() {
	image = al_load_bitmap("plataforma.png");
	posX = 200 * (1 + rand() % 3);
	posY = 120 * (1 + rand() % 3);

}
void estructura::movi(int n, int m) {
	ALLEGRO_KEYBOARD_STATE teclado;
	al_get_keyboard_state(&teclado);
	int desplazamiento = 6;
	if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT) && n != 2 && m == 2) {
		posX -= desplazamiento;
	}
	else if (al_key_down(&teclado, ALLEGRO_KEY_LEFT) && n != 1 && m == 1) {
		posX += desplazamiento;
	}
}
int estructura::posiX() {
	return posX;
}
int estructura::posiY() {
	return posY;
}
void estructura::pinta() {
	al_draw_bitmap(image, posX, posY, 0);
}
