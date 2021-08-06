#ifndef ESCENARIO_H
#define ESCENARIO_H

#include "base_game_CR.h"
class escenario : public base_game_CR {
protected:
	int lvlEscenario;
	int FPSGame;
	int posX2 = 802;
	int posX3 = 460;
	int posX4=0;
	int vuelta = 0;
	int posX = 0;
	int posXdef = 0;
	ALLEGRO_EVENT_QUEUE* eventosEscenario;
	ALLEGRO_COLOR colorFondoEscenario;
	ALLEGRO_BITMAP* imagenFondoEscenario;
	ALLEGRO_BITMAP* imagenPiso;
public:
	//CONSTRUCTOR
	explicit escenario(int _lvlInit = 1, int _fpsInit = 60, ALLEGRO_EVENT_QUEUE* _initEvent = nullptr,
		ALLEGRO_COLOR _initColor = al_map_rgb(255,255,255), ALLEGRO_BITMAP* _initEscenario = nullptr,
		int init_posX = 0, int init_posY=0, ALLEGRO_BITMAP* _initPiso = nullptr)
		: lvlEscenario(_lvlInit), FPSGame(_fpsInit), eventosEscenario(_initEvent),
		colorFondoEscenario(_initColor), imagenFondoEscenario(_initEscenario), posX(init_posX), imagenPiso(_initPiso){
	}

	//FUNCTIONS
	bool gameOver(int, bool);
	void defaultEscenario();
	// void pintar(int);

	//GET_METHODS
	int getlvlEscenario();
	int getFPS();
	ALLEGRO_EVENT_QUEUE* getQueue();
	ALLEGRO_COLOR getColor();
	ALLEGRO_BITMAP* getImagen();

	//SET_FUNCTIONS
	void setQueue(ALLEGRO_EVENT_QUEUE*);
	void setFondo(ALLEGRO_COLOR);
	void setImage(ALLEGRO_BITMAP*);
	void setFPS(int);

	int limite();
	int teclas(int);
	int vueltas();
	void pintar();
};
#endif
