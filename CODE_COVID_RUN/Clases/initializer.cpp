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
    al_init_native_dialog_addon();
    al_init_acodec_addon();

    initialization_modules = true;
}
bool initializer::state_inicialization_allegro() {
    return initialization;
}
bool initializer::state_inicialization_modules() {
    return initialization_modules;
}
