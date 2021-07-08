#include "escenario.h"

escenario::escenario(int _escenario)
    : tipesc{ _escenario } {}

bool escenario::gameOver(int vida, float reco) {
    if (vida == 0) {
        return true;
    }
}
int escenario::esce() {
    return tipesc;
}

int escenario::get_fps()
{
    return FPS;
}

ALLEGRO_EVENT_QUEUE* escenario::get_queue()
{
    return Mis_eventos;
}

ALLEGRO_COLOR escenario::get_fondo()
{
    return *fondo;
}

ALLEGRO_BITMAP* escenario::get_img()
{
    return img;
}

void escenario::set_fondo(ALLEGRO_COLOR _color)
{
    this->fondo = &_color;
}

void escenario::set_img(ALLEGRO_BITMAP* _img)
{
    this->img = _img;
}

void escenario::set_queue(ALLEGRO_EVENT_QUEUE* _queue)
{
    this->Mis_eventos = _queue;
}
void escenario::set_fps(int _fps)
{
    this->FPS = _fps;
}
