#ifndef ESCENARIO_H
#define ESCENARIO_H

#include<iostream>
#include "covid_run_game.h"
using namespace std;

class escenario : public covid_run_game {
private:
    int tipesc;

    int FPS;
    ALLEGRO_EVENT_QUEUE* Mis_eventos;
    ALLEGRO_COLOR* fondo;
    ALLEGRO_BITMAP* img;
public:
    explicit escenario(int _escenario = 0);
    bool gameOver(int vida, float reco);

    int esce();
    int get_fps();
    ALLEGRO_EVENT_QUEUE* get_queue();
    ALLEGRO_COLOR get_fondo();
    ALLEGRO_BITMAP* get_img();

    void set_queue(ALLEGRO_EVENT_QUEUE*);
    void set_fondo(ALLEGRO_COLOR);
    void set_img(ALLEGRO_BITMAP*);
    void set_fps(int);
};

#endif

