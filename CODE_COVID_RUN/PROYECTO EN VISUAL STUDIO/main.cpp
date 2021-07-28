//LIBRERIA ADICIONAL
#include <Windows.h>

//CLASES PRINCIPALES
#include "initializer.h"
#include "player.h"

//TEST
#include <string>
#include <iostream>

//GLOBAL VARIABLES

int ANCHO = GetSystemMetrics(SM_CXSCREEN);
int ALTO = GetSystemMetrics(SM_CYSCREEN);

void dibujarEscenarioBase(ALLEGRO_FONT* main_font, escenario mainEscenario, player _player) {
    al_clear_to_color(mainEscenario.getColor());
    al_draw_bitmap(mainEscenario.getImagen(), 0, 0, 0);
    al_draw_text(main_font, al_map_rgb(0, 0, 0), 50, 520, 0, "COVID RUN 2021");

    _player.pinta();
    al_flip_display();
}

void juegoPrincipal(ALLEGRO_FONT* mainFont, escenario mainEscenario, player _player) {

    ALLEGRO_EVENT evento;

    bool repetir = true;
    bool dibujar = true;

    _player.inicia(mainEscenario);

    while (repetir) {

        //SE HACE LA PRIMERA PINCELADA SOBRE LA PANTALLA Y SE ESPERA ALGUN EVENTO
        if (dibujar && al_event_queue_is_empty(mainEscenario.getQueue())) {
            dibujarEscenarioBase(mainFont, mainEscenario, _player);
            dibujar = false;
        }

        // ESPERAMOS ALGUN EVENTOS
        al_wait_for_event(mainEscenario.getQueue(), &evento);

        // EN CASO SE CIERRE LA VENTANA SE TERMINA EL BUCLE
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            repetir = false;
        }

        // EN CASO SE PULSE LA TECLA ESC SE TERMINA EL BUCLE
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                repetir = false;
            }
        }

        // DESPUES DE UN DETERMINADO TIEMPO
        if (evento.type == ALLEGRO_EVENT_TIMER) {
            dibujar = true;
            _player.teclas();
        }
    }
    
}
int main() {

    //INICIALIZANDO ALLEGRO 5 Y SUS MODULOS
    initializer startGame;

    startGame.inicializar_allegro();
    startGame.inicializar_modulos();

    //COMPROBANDO INICIALIZACION
    if (!startGame.state_inicialization_allegro()) {
        al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR: 001", "NO SE PUDO CARGAR LA LIBRERIA ALLEGRO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //INICIALIZANDO FUENTE PRINCIPAL
    ALLEGRO_FONT* mainFont = al_load_font("GAMERIA.ttf", 70, 0);

    //INICIALIZACION DE CONTROLES EXTERNOS
    al_install_keyboard();

    //CREACION DE LA VENTANA PRINCIPAL
    ALLEGRO_DISPLAY* mainVentana = al_create_display(800, 600);
    al_set_window_title(mainVentana, "COVID RUN ESCAPE NOW!");
    al_set_window_position(mainVentana, ANCHO / 2 - 800 / 2, ALTO / 2 - 600 / 2);

    //CREACION DEL ESCENARIO PRINCIPAL
    escenario mainEscenario;
    mainEscenario.defaultEscenario();

    //CREACION DEL PERSONAJE PRINCIPAL
    player mainPlayer;

    //TEMPORIZADOR QUE CONTROLA FRAMES DEL PERSONAJE
    ALLEGRO_TIMER* timerFramesPlayer = NULL;
    timerFramesPlayer = al_create_timer(1.0/mainEscenario.getFPS());

    //REGISTRAR EVENTOS AL ESCENARIO PRINCIPAL
    al_register_event_source(mainEscenario.getQueue(), al_get_keyboard_event_source());
    al_register_event_source(mainEscenario.getQueue(), al_get_display_event_source(mainVentana));
    al_register_event_source(mainEscenario.getQueue(), al_get_timer_event_source(timerFramesPlayer));
    al_start_timer(timerFramesPlayer);

    juegoPrincipal(mainFont, mainEscenario, mainPlayer);
    
    al_destroy_display(mainVentana);
    al_destroy_font(mainFont);
    al_destroy_timer(timerFramesPlayer);
    return 0;
}