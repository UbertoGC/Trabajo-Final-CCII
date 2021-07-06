#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include<iostream>
using namespace std;

class estructura {
private:
    int esc;
    int tipo;
    float ubi;
public:
    estructura(int, float, int);
    int devtipo();
    float ubicacion();
    int escena();
};
estructura::estructura(int a, float b, int c) {
    esc = a;
    ubi = b;
    tipo = c;
}
float estructura::ubicacion() {
    return ubi;
}
int estructura::devtipo() {
    return tipo;
}
int estructura::escena() {
    return esc;
}

#endif 
