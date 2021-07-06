#ifndef __INITIALIZER_H__
#define __INITIALIZER_H__

//CLASE BASE
#include "covid_run_game.h"

class initializer : public covid_run_game{
private:
    bool initialization;
	bool initialization_modules;
public:
	initializer();
	void inicializar_allegro();
	void inicializar_modulos();

	bool state_inicialization_allegro();
};

#endif
