#ifndef __INITIALIZER_H__
#define __INITIALIZER_H__

//CLASE BASE
#include "base_game_CR.h"

class initializer : public base_game_CR {
private:
	bool initialization;
	bool initialization_modules;
public:
	//CONSTRUCTOR
	initializer();

	//FUNCTIONS
	void inicializar_allegro();
	void inicializar_modulos();

	//GET_METHODS
	bool state_inicialization_allegro();
	bool state_inicialization_modules();
};

#endif