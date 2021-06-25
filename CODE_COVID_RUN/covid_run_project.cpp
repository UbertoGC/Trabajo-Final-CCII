//LIBRERIAS ESTANDAR
#include <iostream>
using namespace std;

//LIBRERIAS ADICIONALES
#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <Windows.h>
int main()
{
    if (!al_init()) {
        al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR: 001", "NO SE PUDO CARGAR LA LIBRERIA ALLEGRO!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    //INICIALIZACION DE FONT
    al_init_font_addon();
    al_init_ttf_addon();

    //CREACION DE VENTANA
    ALLEGRO_DISPLAY* ventana = al_create_display(800, 600);

    //CREACION DE FUENTES
    ALLEGRO_FONT* main_font = al_load_font("GAMERIA.ttf", 70, 0);

    int ANCHO = GetSystemMetrics(SM_CXSCREEN);
    int ALTO = GetSystemMetrics(SM_CYSCREEN);

    al_set_window_title(ventana, "MI JUEGO");
    al_set_window_position(ventana, ANCHO/2 - 800/2, ALTO/2 - 600/2);



    while (true){
        al_draw_text(main_font, al_map_rgb(255, 255, 255), 200, 200, NULL, "HOLA MUNDO");   
        al_flip_display();
    }

    /*
    al_install_keyboard();
    al_set_color_depth(32);
    al_set_gfx_mode(GFX_AUTODETECTED_WINDOWED, 740, 500, 0, 0);*/
    return 0;
}
