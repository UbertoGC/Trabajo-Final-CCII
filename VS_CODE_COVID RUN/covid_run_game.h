#ifndef __COVID_RUN_GAME__
#define __COVID_RUN_GAME__

//LIBRERIAS BASICAS
#include <iostream>
using namespace std;

//LIBRERIAS DE ALLEGRO
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

class covid_run_game
{
protected:
	string gameName;
	float gameVersion;
	string gameContacto;
public:
	covid_run_game();
	string getName();
	string getContacto();
	float getVersion();
	void getInfoGame();
};

#endif
