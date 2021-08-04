#include "escenario.h"

bool escenario::gameOver(int _playerVida, bool _gameStarted) {
	if (_playerVida == 0 && _gameStarted)
		return true;
	else
		return false;
}
void escenario::defaultEscenario() {
	imagenFondoEscenario = al_load_bitmap("manzana.jpg");
	colorFondoEscenario = al_map_rgb(255,255,255);
	FPSGame = 60;
	eventosEscenario = al_create_event_queue();
}
int escenario::getFPS() {
	return FPSGame;
}
ALLEGRO_EVENT_QUEUE* escenario::getQueue() {
	return eventosEscenario;
}
ALLEGRO_COLOR escenario::getColor() {
	return colorFondoEscenario;
}
ALLEGRO_BITMAP* escenario::getImagen() {
	return imagenFondoEscenario;
}
void escenario::setQueue(ALLEGRO_EVENT_QUEUE* _newQueue) {
	eventosEscenario = _newQueue;
}
void escenario::setFondo(ALLEGRO_COLOR _newColor) {
	colorFondoEscenario = _newColor;
}
void escenario::setImage(ALLEGRO_BITMAP* _newImage) {
	imagenFondoEscenario = _newImage;
}
void escenario::setFPS(int _newFPS) {
	FPSGame = _newFPS;
}
int escenario::limite() {
	return posXdef;
}
int escenario::teclas(int m) {
	int n = 0;
	int desplazamiento = 6;
	ALLEGRO_KEYBOARD_STATE teclado;
	al_get_keyboard_state(&teclado);
	if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)&&m==2) {
		posX += desplazamiento;
		posXdef -= desplazamiento;
	}
	else if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)&&m==1) {
		posX -= desplazamiento;
		posXdef += desplazamiento;
	}
	if (posX < 0) { posX = 0; n = 1; }
	if (posX > 400) { posX = 400; n = 2; }
	if (posXdef > 0) {
		posXdef = 0;
	}
	if (posX <-400) {
		posXdef = -400;
	}
	return n;
}
void escenario::pintar() {
	al_draw_bitmap_region(imagenFondoEscenario,posX,0,posX+800,600,0,0,0);
}
