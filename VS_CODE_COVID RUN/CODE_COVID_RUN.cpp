//LIBRERIAS ESTANDAR
#include <iostream>
using namespace std;

//LIBRERIAS ADICIONALES
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <Windows.h>
int main()
{
    al_init();
    if (!al_init()) {
        al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR: 001", "NO SE PUDO CARGAR LA LIBRERIA ALLEGRO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    //INICIALIZACION DE FONT
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();

    //INICIALIZACION DE KEYBOARD
    al_install_keyboard();

    //CREACION DE VENTANA
    ALLEGRO_DISPLAY* ventana = al_create_display(800, 600);

    //CREACION DE FUENTES
    ALLEGRO_FONT* main_font = al_load_font("GAMERIA.ttf", 70, 0);

    //CREACUION DE PERSONAJE
    ALLEGRO_BITMAP* prota = al_load_bitmap("personaje.png");

    //CREACION DE LISTA DE EVENTOS
    ALLEGRO_EVENT_QUEUE* Mis_eventos;
    ALLEGRO_EVENT evento;

    //CREACION DE EVENTOS
    Mis_eventos = al_create_event_queue();


    //ASIGNACION DE EVENTOS A LA LISTA
    al_register_event_source(Mis_eventos, al_get_keyboard_event_source());
    al_register_event_source(Mis_eventos, al_get_display_event_source(ventana));

    //TECLADO
    ALLEGRO_KEYBOARD_STATE teclado;

    bool salir;
    int x, y;
    int desplaza;
    int paso;
    int dir;


    // INICIALIZACION VARIABLES DE MOV

    x = 10;
    y = 10;

    desplaza = 4;

    paso = 0;
    dir = 0;

    salir = false;


    int ANCHO = GetSystemMetrics(SM_CXSCREEN);
    int ALTO = GetSystemMetrics(SM_CYSCREEN);

    al_set_window_title(ventana, "MI JUEGO");
    al_set_window_position(ventana, ANCHO / 2 - 800 / 2, ALTO / 2 - 600 / 2);



    while (!salir) {
        al_draw_text(main_font, al_map_rgb(255, 255, 255), 200, 200, NULL, "HOLA MUNDO");
        al_clear_to_color(al_map_rgb(120, 90, 90));
        al_draw_bitmap_region(prota, paso * 48, dir * 48, 48, 48, x * desplaza, y * desplaza, 0);
        al_flip_display();
        al_wait_for_event(Mis_eventos, &evento);
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            salir = true;
        }

        al_get_keyboard_state(&teclado);

        if (al_key_down(&teclado, ALLEGRO_KEY_UP)){
            y--;
            dir = 3;
            paso++;

        }

        if (al_key_down(&teclado, ALLEGRO_KEY_DOWN)){
            y++;
            dir = 0;
            paso++;
        }

        if (al_key_down(&teclado, ALLEGRO_KEY_LEFT))
        {
            x--;
            dir = 1;
            paso++;
        }

        if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT))
        {
            x++;
            dir = 2;
            paso++;
        }

        // LIMITADORES


        if (x < 0) x = 0;
        if (x > 800 - 48) x = 800 - 48;
        if (y < 0) y = 0;
        if (y > 600 - 48) y = 600 - 48;
        if (paso > 2) paso = 0;

        if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE)) {
            salir = true;

        }


    }



    // destroy_bitmap(prota);

    al_destroy_bitmap(prota);


    // destroy_display(pantalla);

    al_destroy_display(ventana);

    return 0;
}
