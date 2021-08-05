#include "estructura.h"

void estructura::initDefault() {
	image = al_load_bitmap("plataforma.png");

	posX = 200 * (1 + rand() % 3);
	posY = 120 * (1 + rand() % 3);
	cout << "Estructura generada en " << posX << " " << posY << endl;
}

void estructura::pinta() {
	al_draw_bitmap(image, posX, posY, 0);
}
