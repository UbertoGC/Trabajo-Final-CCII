//LIBRERIA ADICIONAL
#include <Windows.h>

//CLASES PRINCIPALES
#include "initializer.h"
#include "player.h"
#include "mascarilla.h"
#include "escudo.h"

//TEST
#include <string>
#include <iostream>
#include <vector>

//GLOBAL VARIABLES

int ANCHO = GetSystemMetrics(SM_CXSCREEN);
int ALTO = GetSystemMetrics(SM_CYSCREEN);

void pintaobj(player _player, objeto* _objetos[], int& _tamano) {
    for (int i = 0; i < _tamano; i++) {
        if (_objetos[i] != nullptr) {
            _objetos[i]->pinta();
        }
    }
}

void dibujarEscenarioBase(ALLEGRO_FONT* main_font, escenario mainEscenario, player _player, objeto *_objetos[], int &_tamano) {
    
    al_clear_to_color(mainEscenario.getColor());
    al_draw_bitmap(mainEscenario.getImagen(), 0, 0, 0);
    al_draw_text(main_font, al_map_rgb(0, 0, 0), 50, 520, 0, "COVID RUN 2021");

    _player.pinta();
    pintaobj(_player, _objetos, _tamano);
    al_flip_display();
}

void juegoPrincipal(ALLEGRO_FONT* mainFont, escenario mainEscenario, player _player, objeto* _objetos[], int& _tamano) {

    ALLEGRO_EVENT evento;

    bool repetir = true;
    bool dibujar = true;

    _player.inicia(mainEscenario);

    while (repetir) {

        //SE HACE LA PRIMERA PINCELADA SOBRE LA PANTALLA Y SE ESPERA ALGUN EVENTO
        if (dibujar && al_event_queue_is_empty(mainEscenario.getQueue())) {
            dibujarEscenarioBase(mainFont, mainEscenario, _player, _objetos, _tamano);
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
            for (int i = 0; i < _tamano; i++) {
                if (_objetos[i] != nullptr) {
                    if (_objetos[i]->efecto(_player) == 1) {
                        delete _objetos[i];
                        _objetos[i] = nullptr;
                    }
                }
            }
        }
    }

}

int menuDelJuego(ALLEGRO_BITMAP* menu_null, ALLEGRO_BITMAP* menu_start, ALLEGRO_BITMAP* menu_salir, escenario mainEscenario, player& _player) {
    int tamano = 4;
    objeto* objetos[4];
    objetos[0] = new mascarilla(480);
    objetos[1] = new mascarilla(800);
    objetos[2] = new mascarilla(1120);
    objetos[3] = new escudo(1600);
    int botones[] = { 0 };
    int posXMouse = -1;
    int posYMouse = -1;
    ALLEGRO_EVENT evento;
    bool repetir = true;
    ALLEGRO_SAMPLE* sound;
    al_reserve_samples(1);
    sound = al_load_sample("backgroundMusic.wav");
    al_play_sample(sound, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    while (repetir) {
        al_clear_to_color(al_map_rgb(255, 255, 255));
        if (botones[0] == 0)
            al_draw_bitmap(menu_null, 0, 0, 0);
        else if (botones[0] == 1)
            al_draw_bitmap(menu_start, 0, 0, 0);
        else
            al_draw_bitmap(menu_salir, 0, 0, 0);

        al_wait_for_event(mainEscenario.getQueue(), &evento);

        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                repetir = false;
            }
        }
        if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            posXMouse = evento.mouse.x;
            posYMouse = evento.mouse.y;
            if (posXMouse >= 381 && posXMouse <= 644 && posYMouse >= 264 && posYMouse <= 336) {
                botones[0] = 1;
                if (evento.mouse.button & 1)
                    juegoPrincipal(al_load_font("GAMERIA.ttf", 70, 0), mainEscenario, _player, objetos, tamano);
            }
            else if (posXMouse >= 393 && posXMouse <= 651 && posYMouse >= 428 && posYMouse <= 501) {
                botones[0] = 2;
                if (evento.mouse.button & 1) {
                    al_destroy_sample(sound);
                    return 1;
                }
            }
            else {
                botones[0] = 0;
            }
        }
        al_flip_display();
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
    al_install_mouse();
    al_install_audio();

    //CREACION DE LA VENTANA PRINCIPAL
    ALLEGRO_DISPLAY* mainVentana = al_create_display(800, 600);
    al_set_window_title(mainVentana, "COVID RUN ESCAPE NOW!");
    al_set_window_position(mainVentana, ANCHO / 2 - 800 / 2, ALTO / 2 - 600 / 2);

    //CREACION DEL ESCENARIO PRINCIPAL
    escenario mainEscenario;
    mainEscenario.defaultEscenario();

    //CREACION DEL PERSONAJE PRINCIPAL
    player mainPlayer;

    //OBJETO CREACION
    int tamano = 4;
    objeto* objetos[4];
    objetos[0] = new mascarilla(480);
    objetos[1] = new mascarilla(800);
    objetos[2] = new mascarilla(1120);
    objetos[3] = new escudo(1600);

    //TEMPORIZADOR QUE CONTROLA FRAMES DEL PERSONAJE
    ALLEGRO_TIMER* timerFramesPlayer = NULL;
    timerFramesPlayer = al_create_timer(1.0 / mainEscenario.getFPS());

    //REGISTRAR EVENTOS AL ESCENARIO PRINCIPAL
    al_register_event_source(mainEscenario.getQueue(), al_get_keyboard_event_source());
    al_register_event_source(mainEscenario.getQueue(), al_get_display_event_source(mainVentana));
    al_register_event_source(mainEscenario.getQueue(), al_get_timer_event_source(timerFramesPlayer));
    al_register_event_source(mainEscenario.getQueue(), al_get_mouse_event_source());
    al_start_timer(timerFramesPlayer);

    ALLEGRO_BITMAP* menu_null = al_load_bitmap("menu_null.png");
    ALLEGRO_BITMAP* menu_start = al_load_bitmap("menu_jugar.png");
    ALLEGRO_BITMAP* menu_salir = al_load_bitmap("menu_salir.png");

    menuDelJuego(menu_null, menu_start, menu_salir, mainEscenario, mainPlayer);


    al_destroy_display(mainVentana);
    al_destroy_font(mainFont);
    al_destroy_timer(timerFramesPlayer);

    return 0;
}