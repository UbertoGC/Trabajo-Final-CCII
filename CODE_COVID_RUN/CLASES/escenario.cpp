#include "escenario.h"

bool escenario::gameOver(int _playerVida, bool _gameStarted) {
	if (_playerVida == 0 && _gameStarted)
		return true;
	else
		return false;
}
void escenario::defaultEscenario() {
	imagenFondoEscenario = al_load_bitmap("escenario.png");
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
