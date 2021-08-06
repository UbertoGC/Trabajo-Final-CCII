#ifndef __GENERADOR_H__
#define __GENERADOR_H__

#include "mascarilla.h"
#include "escudo.h"
#include "enfermo.h"
#include "estructura.h"
#include "Listaenlazada.h"

class generador {

private:
	int posX = 0;
	Listaenlazada<mascarilla> mascarillas;
	Listaenlazada<escudo> escudos;
	Listaenlazada<estructura> estructuras;
	Listaenlazada<enfermo> enfermos;
public:
	generador();
	void reinicioestruc();
	void reinicioescud();
	void reinicioenferm();
	void reiniciomasca();
	void reinicio();
	void cambioposiX();
	void cambios(player&, int, int,int);
	void pintar();
};
#endif
