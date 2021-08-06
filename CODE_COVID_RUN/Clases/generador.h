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
	shared_ptr<Listaenlazada<mascarilla>> mascarillas;
	shared_ptr<Listaenlazada<escudo>> escudos;
	shared_ptr<Listaenlazada<estructura>> estructuras;
	shared_ptr<Listaenlazada<enfermo>> enfermos;
public:
	generador();
	void reinicioestruc();
	void reinicioescud();
	void reinicioenferm();
	void reiniciomasca();
	void reinicio();
	int cambioposiX();
	void cambios(player&, int, int,int);
	void pintar();
};
#endif
