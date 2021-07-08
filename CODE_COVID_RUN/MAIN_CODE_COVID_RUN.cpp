//LIBRERIA ADICIONAL
#include <Windows.h>

//CLASES PRINCIPALES
#include "initializer.h"
#include "jugador.h"

void dibuja(ALLEGRO_FONT* main_font, escenario c_run, jugador player) {
    al_clear_to_color(c_run.get_fondo());
    al_draw_bitmap(c_run.get_img(), 0, 0, 0);
    al_draw_text(main_font, al_map_rgb(0, 0, 0), 50, 520, 0, "COVID RUN 2021");

    player.pinta();
    al_flip_display();
}

void juego(ALLEGRO_FONT* main_font, escenario c_run, jugador player) {

    ALLEGRO_EVENT evento;

    bool repetir = true;
    bool dibujar = true;

    player.inicia(c_run);
    while (repetir) {
        // Pinta si es dibuja y esta vacia la lista de eventos
        if (dibujar && al_event_queue_is_empty(c_run.get_queue())) {
            dibuja(main_font, c_run, player);
            dibujar = false;
        }

        // esperamos a que ocurra un evento
        al_wait_for_event(c_run.get_queue(), &evento);

        // se ha cerrado la ventana
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            repetir = false;
        }

        // se ha pulsado ESC
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                repetir = false;
            }
        }

        // pasa un tiempo determinado
        if (evento.type == ALLEGRO_EVENT_TIMER) {
            dibujar = true;
            player.teclas(evento);
        }
    }
    al_destroy_font(main_font);
}

int main()
{
    //INICIALIZACION DE ALLEGRO 5
    initializer start;
    start.inicializar_allegro();
    start.inicializar_modulos();
    

    //COMPROBAR INICIALIZACION
    if (!start.state_inicialization_allegro()) {
        al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR: 001", "NO SE PUDO CARGAR LA LIBRERIA ALLEGRO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //INICIALIZACION DE KEYBOARD
    al_install_keyboard();

    //CREACION DE VENTANA
    ALLEGRO_DISPLAY* ventana = al_create_display(800, 600);
    //VARIABLES DE LA VENTANA
    int ANCHO = GetSystemMetrics(SM_CXSCREEN);
    int ALTO = GetSystemMetrics(SM_CYSCREEN);
    //CONFIGURACION DE LA VENTANA
    al_set_window_title(ventana, "MI JUEGO");
    al_set_window_position(ventana, ANCHO / 2 - 800 / 2, ALTO / 2 - 600 / 2);

    //CREACION DE ESCENARIO
    escenario covid_run;

    //CREACION DE PERSONAJE
    jugador player;

    //CREACION DE TEMPORIZADOR
    ALLEGRO_TIMER* timer = NULL;

    //CREACION DE FUENTES
    ALLEGRO_FONT* main_font = al_load_font("GAMERIA.ttf", 70, 0);


    //CREACION DEL FONDO DEL JUEGO
    covid_run.set_img(al_load_bitmap("escenario.png"));
    covid_run.set_fondo(al_map_rgb(255,255,255));
    covid_run.set_fps(60);
    timer = al_create_timer(1.0 / covid_run.get_fps());

    //CREO LISTA DE EVENTOS
    covid_run.set_queue(al_create_event_queue());

    //ASIGNAR EVENTOS A LA LISTA
    al_register_event_source(covid_run.get_queue(), al_get_keyboard_event_source());
    al_register_event_source(covid_run.get_queue(), al_get_display_event_source(ventana));
    al_register_event_source(covid_run.get_queue(), al_get_timer_event_source(timer));
    al_start_timer(timer);

    juego(main_font, covid_run, player);
    al_destroy_display(ventana);
    return 0;
}