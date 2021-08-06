#include "enfermo.h"
void enfermo::reinicio(int x, bool _par1, bool _par2) {
	imgenemigo = al_load_bitmap("enfermo.png");
	tiempoPaso = int(60 / getMueve());
	tiempoCont = 0;
	posX = x;
	posY = 480;
	direccion = 0;
	paso = 1;
	movi[0] = _par1;
	movi[1] = _par2;
}
void enfermo::efecto(player& _player) {
	if (_player.getposX() + 30 >= posX && _player.getposX() <= posX + 30 && _player.getposY() + 40 >= posY && _player.getposY() <= posY + 40 && afeccion == 0) {
		_player.cambio(5);
		afeccion = 1;
	}
	else if (((_player.getposX() + 30 < posX || _player.getposX() > posX + 30) || (_player.getposY() + 40 < posY || _player.getposY() > posY + 40)) && afeccion == 1) {
		if (afeccion!=0){
			this->afeccion = 0;
		}
	}
}
void enfermo::movienf(int m, int n) {
	int desplazamiento = 6;
	ALLEGRO_KEYBOARD_STATE teclado;
	al_get_keyboard_state(&teclado);
	if (movi[0]) {
		if (movi[1]) {
			posX += movimiento;
			direccion = 2;
			tiempoCont++;
		}
		else {
			posX -= movimiento;
			direccion = 1;
			tiempoCont++;
		}
		if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT) && n!=2 && m == 2) {
			posX -= desplazamiento;
		}
		else if (al_key_down(&teclado, ALLEGRO_KEY_LEFT) && n != 1 && m == 1) {
			posX += desplazamiento;
		}
		if (tiempoCont > tiempoPaso) {
			paso++;
			tiempoCont = 0;
		}
		if (paso > 2) paso = 0;
	}
	else {
		direccion = 0;
		paso = 1;
		if (movi[1]) {
			if (jump2) {
				velY2 = -jumpSpeed2;
				jump2 = false;
			}
			if (!jump2)
				velY2 += gravity2;
			else
				velY2 = 0;

			posY += velY2;

			jump2 = (posY + 80 >= 560);

			if (jump2)
				posY = 560 - 80;
		}
		if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT) && n != 2 && m == 2) {
			posX -= desplazamiento;
		}
		else if (al_key_down(&teclado, ALLEGRO_KEY_LEFT) && n != 1 && m == 1) {
			posX += desplazamiento;
		}
	}

}
void enfermo::pinta() {
	al_draw_bitmap_region(imgenemigo, 48 * paso, 48 * direccion, 48, 48, posX, posY, 0);
}
enfermo& enfermo::operator=(enfermo p) {
	if (this != &p) {
		this->posX = p.posX;
		this->posY = 480;
		this->direccion = 0;
		this->movimiento = 2;
		this->imgenemigo = al_load_bitmap("enfermo.png");
		this->tiempoPaso = p.tiempoPaso;
		this->tiempoCont = 0;
		this->paso = 1;
		this->afeccion = 0;
		this->movi[0] = p.movi[0];
		this->movi[1] = p.movi[1];
		this->jump2 = false;
		this->velY2 = 0;
		this->jumpSpeed2 = 35;
	}
	return *this;
}
