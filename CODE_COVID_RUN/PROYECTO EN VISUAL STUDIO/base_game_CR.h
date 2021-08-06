#ifndef __COVID_RUN_GAME__
#define __COVID_RUN_GAME__

#include <iostream>
using namespace std;

//DEPENDENCIAS ALLEGRO

#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include<stdlib.h>
#include<time.h>

class base_game_CR {
protected:
	string gameName;
	float gameVersion;
	string gameContacto;
public:
	//CONSTRUCTOR
	base_game_CR();

	//GET_METHODS
	string getName();
	string getContacto();
	float getVersion();

	void getInfoGame();
};
#endif