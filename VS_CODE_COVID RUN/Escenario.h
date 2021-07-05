#ifndef ESCENARIO_H
#define ESCENARIO_H

#include<iostream>
using namespace std;

class escenario {
    private:
        int tipesc; //tipo escenario
    public:
        escenario(int);
        bool gameOver(int vida, float reco);
        int esce();
};
escenario::escenario(int b) {
    tipesc = b;
}
bool escenario::gameOver(int vida, float reco) {
    if (vida == 0) {
    }

}
int escenario::esce() {
    return tipesc;
}

#endif 