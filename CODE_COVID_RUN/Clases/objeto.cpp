#include "objeto.h"

void objeto::moviobj(int n, int m) {
	int desplazamiento = 6;
	ALLEGRO_KEYBOARD_STATE teclado;
	al_get_keyboard_state(&teclado);
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
int objeto::efecto(player& _player) {
	return 0;
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
void objeto::cambiodura(int a) {
	duracion = a;
}
