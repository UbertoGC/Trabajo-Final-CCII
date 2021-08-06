
//LIBRERIA ADICIONAL
#include <Windows.h>

//CLASES PRINCIPALES
#include "initializer.h"
#include "generador.h"

//TEST
#include <string>
#include <iostream>
//FUNCIONES PARA SIMPLIFICAR
void vidalife(int& _lifePoints, ALLEGRO_FONT* _vidfuent, ALLEGRO_BITMAP* _vidimg) {
    int m = 256 - (2 * _lifePoints + 26);
    int n = 2 * _lifePoints + 30;
    ALLEGRO_COLOR vidcolor = al_map_rgb(m, n, 80);
    al_draw_text(_vidfuent, vidcolor, 70, 5, 0, (to_string(_lifePoints) + "+").c_str());
    al_draw_bitmap(_vidimg, 0, 0, 0);
}

//GLOBAL VARIABLES
int ANCHO = GetSystemMetrics(SM_CXSCREEN);
int ALTO = GetSystemMetrics(SM_CYSCREEN);
int continuejuego = 2;

void dibujarEscenarioBase(ALLEGRO_FONT* main_font, escenario& mainEscenario, player& _player, generador &_generacion, ALLEGRO_BITMAP* _vidimg) {
    al_clear_to_color(mainEscenario.getColor());
    mainEscenario.pintar();
    _generacion.pintar();
    _player.pinta();
    vidalife(_player.vida(), main_font, _vidimg);
    al_flip_display();
}

void juegoPrincipal(ALLEGRO_FONT* mainFont, escenario &mainEscenario, player &_player, generador &_generacion, ALLEGRO_BITMAP *_vidimg) {
    ALLEGRO_EVENT evento;
    bool repetir = true;
    bool dibujar = true;
    int contador = 0;
    int n, m;
    while (repetir) {
        //SE HACE LA PRIMERA PINCELADA SOBRE LA PANTALLA Y SE ESPERA ALGUN EVENTO
        if (dibujar && al_event_queue_is_empty(mainEscenario.getQueue())) {
            dibujarEscenarioBase(mainFont, mainEscenario, _player, _generacion, _vidimg);
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
            contador++;
            if (contador == 60) {
                _player.contagio();
                contador = 0;
            }
            m = _player.teclas();
            n = mainEscenario.teclas(m);
            _generacion.cambios(_player,m,n,contador);
        }
    }
}

int menuDelJuego(ALLEGRO_BITMAP* menu_null, ALLEGRO_BITMAP* menu_start, ALLEGRO_BITMAP* menu_salir, escenario &mainEscenario, player& _player) {
    ALLEGRO_BITMAP* vidimg = al_load_bitmap("corazon.png");
    _player.inicia(mainEscenario);
    generador generacion(mainEscenario);
    int botones[] = { 0 };
    int posXMouse = -1;
    int posYMouse = -1;
    ALLEGRO_EVENT evento;
    bool repetir = true;
    ALLEGRO_SAMPLE* sound;
    ALLEGRO_FONT* fuente = al_load_font("GAMERIA.ttf", 50, 0);
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
                    juegoPrincipal(fuente, mainEscenario, _player, generacion, vidimg);
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