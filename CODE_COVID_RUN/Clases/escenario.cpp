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
	imagenPiso = al_load_bitmap("pisoCiudad.jpg");
}


int escenario::getlvlEscenario() {
	return lvlEscenario;
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
	if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT) && m == 2) {
		posX += desplazamiento;
		posXdef -= desplazamiento;
	}
	else if (al_key_down(&teclado, ALLEGRO_KEY_LEFT) && m == 1) {
		posX -= desplazamiento;
		posXdef += desplazamiento;
	}
	if (posX < 0) {
		if (vuelta == 0) {
			posX = 0;
			n = 1;
		}
	}
	if (posX < 460) { 
		if(vuelta>0) {
			posX2 = 3;
			posX3 = 460 - posX;
			posX4 = 3827 - posX3-1;
			if (posX < -340) {
				posX2 = 802;
				posX = 3027;
				vuelta--;
			}
		}
		
	}
	if (posX > 3027) {
		posX4 = 462;
		posX2 = 3827 - posX;
		posX3 = posX - 3027+10;
	}
	if (posX >= 3827) {
		vuelta += 1;
		posX = 460;
		posX2 = 802;
	}
	if (posXdef > 0) {
		posXdef = 0;
	}
	if (posXdef < -3827) {
		posXdef = -3827;
	}
	if (posX <= 3027 && posX >= 460) {
		posX3 = 0;
	}
	return n;
}
void escenario::pintar() {
	al_draw_bitmap_region(imagenFondoEscenario, posX, 0, 800, 600, 0, 0, 0);
	al_draw_bitmap_region(imagenFondoEscenario, posX4, 0, posX3, 600, posX2-2, 0, 0);
}