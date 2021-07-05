#ifndef JUGADOR_H
#define JUGADOR_H

#include<iostream>
using namespace std;

class jugador {
    private:
        int vida;
        float recorrido;
    public:
        int devvida();
        void aumvida(int);
        float devrecorrido();
};
int jugador::devvida() {
    return vida;
}
void jugador::aumvida(int b) {
    vida = vida + b;
}
float jugador::devrecorrido() {
    return recorrido;
}

#endif