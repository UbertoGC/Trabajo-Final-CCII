#include "generador.h"
generador::generador(escenario _playerEscenario) {
	mascarilla* o0 = new mascarilla(1000);
	mascarilla* o1 = new mascarilla(500);
	mascarilla* o3 = new mascarilla(1500);
	mascarilla* o4 = new mascarilla(2000);
	escudo* o2 = new escudo(500);
	enfermo* s1 = new enfermo(_playerEscenario, false, false, 1000);
	enfermo* s2 = new enfermo(_playerEscenario, true, true, 500);
	enfermo* s3 = new enfermo(_playerEscenario, false, true, 500);
	enfermo* s4 = new enfermo(_playerEscenario, true, false, 500);

	srand(time(NULL));
	estructura* conjunto = new estructura[10];
	for (int i = 0; i < 9; i++) {
		conjunto[i].initDefault();
	}

}
void generador::reinicio() {
	estructuras.vaciar();
	enfermos.vaciar();
	mascarillas.vaciar();
	escudos.vaciar();
}
void generador::cambios(player&_player, int m, int n, int _contador) {
	if (estructuras.Size() != 0) {
		Iterator<estructura> i(estructuras.begin());
		for (; i != estructuras.end(); ++i) {
			i.posicion()->Devol2().movi(n, m);
			if (_player.getposX() + 30 >= i.posicion()->Devol2().posiX() && _player.getposX() <= i.posicion()->Devol2().posiX() + 150) {
				if (_player.getposY() + 48 >= i.posicion()->Devol2().posiY() && _player.getposY() <= i.posicion()->Devol2().posiY() + 15) {
					_player.hasColision();
				}
			}
		}
	}
	if (enfermos.Size()!=0) {
		Iterator<enfermo> j(enfermos.begin());
		for (; j != enfermos.end(); ++j) {
			enfermo* enf = &j.posicion()->Devol2();
			enf->movienf(m, n);
			enf->efecto(_player);
		}
	}
	if (mascarillas.Size() != 0) {
		int n2 = mascarillas.Size();
		int cont = 0;
		mascarilla* s2 = new mascarilla[n2];
		Iterator<mascarilla> k(mascarillas.begin());
		for (; k != mascarillas.end(); ++k) {
			if (!k.posicion()->Devol2().usandose()) {
				k.posicion()->Devol2().moviobj(n,m);
				k.posicion()->Devol2().efecto(_player);
			}
			else if(k.posicion()->Devol2().durarest() != 0) {
				k.posicion()->Devol2().bajandotiem();
			}
			if (k.posicion()->Devol2().durarest() == 0) {
				k.posicion()->Devol2().finalobj(_player);
				s2[cont] = k.posicion()->Devol2();
				cont++;
			}
		}
		k.~Iterator();
		if (cont <= n2 && cont != 0) {
			for (int i = 0; i < n2; i++) {
				mascarillas.Eliminar(s2[i]);
			}
		}
		delete[] s2;
	}
	if (escudos.Size() != 0) {
		int n2 = escudos.Size();
		int cont = 0;
		escudo* s2 = new escudo[n2];
		Iterator<escudo> k(escudos.begin());
		for (; k != escudos.end(); ++k) {
			if (!k.posicion()->Devol2().usandose()) {
				k.posicion()->Devol2().moviobj(n, m);
				k.posicion()->Devol2().efecto(_player);
			}
			else{
				k.posicion()->Devol2().bajandotiem();
				if (_player.choquescud()) {
					k.posicion()->Devol2().cambiodura(0);
				}
			}
			if (k.posicion()->Devol2().durarest() == 0) {
				k.posicion()->Devol2().finalobj(_player);
				s2[cont] = k.posicion()->Devol2();
				cont++;
			}
		}
		k.~Iterator();
		if (cont <= n2 && cont != 0) {
			for (int i = 0; i < n2; i++) {
				escudos.Eliminar(s2[i]);
			}
		}
		delete[] s2;
	}
}
void generador::pintar() {
	if (!(estructuras.Size() == 0)) {
		Iterator<estructura> j(estructuras.begin());
		for (; j != estructuras.end(); ++j) {
			j.posicion()->Devol2().pinta();
		}
	}
	if (!(enfermos.Size() == 0)) {
		Iterator<enfermo> j(enfermos.begin());
		for (; j != enfermos.end(); ++j) {
			j.posicion()->Devol2().pinta();
		}
	}
	if (!(mascarillas.Size() == 0)) {
		Iterator<mascarilla> k(mascarillas.begin());
		for (; k != mascarillas.end(); ++k) {
			if (!k.posicion()->Devol2().usandose()) {
				k.posicion()->Devol2().pinta();
			}		
		}
	}
	if (!(escudos.Size() == 0)) {
		Iterator<escudo> k(escudos.begin());
		for (; k != escudos.end(); ++k) {
			if (!k.posicion()->Devol2().usandose()) {
				k.posicion()->Devol2().pinta();
			}
		}
	}
	
}