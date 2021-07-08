#ifndef ENEMIGO_H
#define ENEMIGO_H

#include<iostream>
using namespace std;
class enemigo {
private:
    int niv;
public:
    enemigo(int);
    int devniv();
};
enemigo::enemigo(int b) {
    niv = b;
}
int enemigo::devniv() {
    return niv;
}
#endif

