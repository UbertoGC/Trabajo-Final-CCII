#include "generador.h"
generador::generador() {
	shared_ptr<Listaenlazada<mascarilla>> mascarillas2(new Listaenlazada<mascarilla>());
	shared_ptr<Listaenlazada<escudo>> escudos2(new Listaenlazada<escudo>());
	shared_ptr<Listaenlazada<estructura>> estructuras2(new Listaenlazada<estructura>());
	shared_ptr<Listaenlazada<enfermo>> enfermos2(new Listaenlazada<enfermo>());
	mascarillas = mascarillas2;
	escudos = escudos2;
	estructuras = estructuras2;
	enfermos = enfermos2;
	srand(time(NULL));
	int m = rand() % 2;
	this->reiniciomasca();
	this->reinicioenferm();
	if (m == 0) {
		this->reinicioescud();
	}
	else {
		this->reinicioestruc();
	}
}
void generador::reinicioestruc() {
	srand(time(NULL));
	int estrucant = rand() % 3;
	int estruc = 6 + rand() % 3;
	if (estrucant > 0) {
		int m = 300;
		for (int j = 0; j < estrucant; j++) {
			estructura* conjuntoest = new estructura[estruc];
			for (int i = 0; i < estruc; i++) {
				conjuntoest[i].initDefault(((j + 1) * 800) + (m * j));
			}
			for (int i = 0; i < estruc; i++) {
				estructuras->Anadir(conjuntoest[i]);
			}
		}
	}
}
void generador::reiniciomasca() {
	srand(time(NULL));
	int masca = 2 + rand() % 2;
	int genmas = 2400 / masca;
	if (masca>0) {
		int m2;
		int a, b;
		mascarilla *conjuntomas[3];
		for (int s = 0; s < masca; s++) {
			conjuntomas[s] = new mascarilla();
			m2 = rand() % 2;
			a = (s + 1) * genmas;
			b = 482 - (m2 * 80);
			conjuntomas[s]->reinicio(a, b);
		}
		for (int i = 0; i < masca; i++) {
			mascarillas->Anadir(*conjuntomas[i]);
		}
	}
}
void generador::reinicioescud() {
	srand(time(NULL));
	int escud = rand() % 4;
	if (escud != 0) {
		int genesc = 2400 / escud;
		escudo* conjunesc[3];
		for (int i = 0; i < escud; i++) {
			conjunesc[i] = new escudo();
			int m = rand() % 2;
			conjunesc[i]->reinicio(((i + 1) * genesc) + 300, 476 - (m * 80));
			escudos->Anadir(*conjunesc[i]);
		}
	}
}
void generador::reinicioenferm() {
	srand(time(NULL));
	int enfer = 3 + rand() % 2;
	enfermo *enferm[6];
	int genenf = 2100 / enfer;
	int m;
	for (int i = 0; i < enfer; i++) {
		enferm[i] = new enfermo();
		m = rand() % 4;
		switch (m)
		{
		case 0:
			enferm[i]->reinicio((i + 1) * genenf + 500, false, false);
			break;
		case 1:
			enferm[i]->reinicio(-50, true, false);
			break;
		case 2:
			enferm[i]->reinicio((i + 1) * genenf + 500, false, true);
			break;
		case 3:
			enferm[i]->reinicio((i + 1) * genenf + 500, true, true);
			break;
		}
		enfermos->Anadir(*enferm[i]);
	}
}
void generador::reinicio() {
	srand(time(NULL));
	posX = 0;
	shared_ptr<Listaenlazada<mascarilla>> mascarillas2(new Listaenlazada<mascarilla>());
	shared_ptr<Listaenlazada<escudo>> escudos2(new Listaenlazada<escudo>());
	shared_ptr<Listaenlazada<estructura>> estructuras2(new Listaenlazada<estructura>());
	shared_ptr<Listaenlazada<enfermo>> enfermos2(new Listaenlazada<enfermo>());
	mascarillas = mascarillas2;
	escudos = escudos2;
	estructuras = estructuras2;
	enfermos = enfermos2;
	int m = rand() % 2;
	this->reiniciomasca();
	this->reinicioenferm();
	this->reinicioescud();
	this->reinicioestruc();
}
int generador::cambioposiX() {
	return posX;
}
void generador::cambios(player&_player, int m, int n, int _contador) {
	if (posX < -3367) {
		this->reinicio();
	}
	ALLEGRO_KEYBOARD_STATE teclado;
	int desplazamiento = 6;
	al_get_keyboard_state(&teclado);
	if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT) && n != 2 && m == 2) {
		posX -= desplazamiento;
	}
	else if (al_key_down(&teclado, ALLEGRO_KEY_LEFT) && n != 1 && m == 1) {
		posX += desplazamiento;
	}
	if (estructuras->Size() != 0) {
		Iterator<estructura> i(estructuras->begin());
		for (; i != estructuras->end(); ++i) {
			i.posicion()->Devol2().movi(n, m);
			if (_player.getposX() + 30 >= i.posicion()->Devol2().posiX() && _player.getposX() <= i.posicion()->Devol2().posiX() + 150) {
				if (_player.getposY() + 48 >= i.posicion()->Devol2().posiY() && _player.getposY() <= i.posicion()->Devol2().posiY() + 15) {
					_player.hasColision();
				}
			}
		}
	}
	if (enfermos->Size()!=0) {
		Iterator<enfermo> j(enfermos->begin());
		for (; j != enfermos->end(); ++j) {
			enfermo* enf = &j.posicion()->Devol2();
			enf->movienf(m, n);
			enf->efecto(_player);
		}
	}
	if (mascarillas->Size() != 0) {
		Iterator<mascarilla> k(mascarillas->begin());
		for (; k != mascarillas->end(); ++k) {
			if (!k.posicion()->Devol2().usandose()&& k.posicion()->Devol2().durarest() != 0) {
				k.posicion()->Devol2().moviobj(n,m);
				k.posicion()->Devol2().efecto(_player);
			}
			else if(k.posicion()->Devol2().usandose() && k.posicion()->Devol2().durarest() != 0) {
				k.posicion()->Devol2().bajandotiem();
			}
			if (k.posicion()->Devol2().durarest() == 0) {
				k.posicion()->Devol2().finalobj(_player);
			}
		}
	}
	if (escudos->Size() != 0) {
		Iterator<escudo> k(escudos->begin());
		for (; k != escudos->end(); ++k) {
			if (!k.posicion()->Devol2().usandose() && k.posicion()->Devol2().durarest() != 0) {
				k.posicion()->Devol2().moviobj(n, m);
				k.posicion()->Devol2().efecto(_player);
			}
			else if (k.posicion()->Devol2().usandose() && k.posicion()->Devol2().durarest() != 0){
				k.posicion()->Devol2().bajandotiem();
				if (_player.choquescud()) {
					k.posicion()->Devol2().cambiodura(0);
				}
			}
			if (k.posicion()->Devol2().durarest() == 0) {
				k.posicion()->Devol2().finalobj(_player);
			}
		}
	}
}
void generador::pintar() {
	if (!(estructuras->Size() == 0)) {
		Iterator<estructura> j(estructuras->begin());
		for (; j != estructuras->end(); ++j) {
			j.posicion()->Devol2().pinta();
		}
	}
	if (!(enfermos->Size() == 0)) {
		Iterator<enfermo> j(enfermos->begin());
		for (; j != enfermos->end(); ++j) {
			j.posicion()->Devol2().pinta();
		}
	}
	if (!(mascarillas->Size() == 0)) {
		Iterator<mascarilla> k(mascarillas->begin());
		for (; k != mascarillas->end(); ++k) {
			if (!k.posicion()->Devol2().usandose()) {
				k.posicion()->Devol2().pinta();
			}		
		}
	}
	if (!(escudos->Size() == 0)) {
		Iterator<escudo> k(escudos->begin());
		for (; k != escudos->end(); ++k) {
			if (!k.posicion()->Devol2().usandose()) {
				k.posicion()->Devol2().pinta();
			}
		}
	}
	
}