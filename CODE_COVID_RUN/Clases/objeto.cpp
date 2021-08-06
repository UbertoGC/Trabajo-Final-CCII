#include "objeto.h"

void objeto::moviobj(int n, int m) {
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
void objeto::pinta() {
	al_draw_bitmap(imgobj, posX, posY, 0);
}
void objeto::efecto(player& _player) {
}
void objeto::finalobj(player& player) {
}
bool objeto::usandose() {
	return uso;
}
int objeto::durarest() {
	return duracion;
}
void objeto::bajandotiem() {
	duracion--;
}
int objeto::tipoclase() {
	return tipo;
}
int objeto::posiX() {
	return posX;
}
void objeto::cambiodura(int a) {
	duracion = a;
}
bool objeto::operator==(objeto p) {
	return (this->tipo == p.tipo && this->posX == p.posX);
}
objeto& objeto::operator=(objeto p) {
	if (this != &p) {
		this->tipo = p.tipo;
		this->duracion = p.duracion;
		this->posX = p.posX;
		this->posY = p.posY;
		this->uso = p.uso;
		this->desplazamiento = p.desplazamiento;
		this->imgobj = p.imgobj;
	}
	return *this;
}