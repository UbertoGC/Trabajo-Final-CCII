#include "initializer.h"

initializer::initializer() {
    initialization = false;
    initialization_modules = false;
}
void initializer::inicializar_allegro() {
    al_init();
    initialization = true;
}
void initializer::inicializar_modulos() {
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    initialization_modules = true;
}
bool initializer::state_inicialization_allegro()
{
    if (al_init())
        return true;
    else
        return false;
}
