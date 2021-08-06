#ifndef ITERATOR_H
#define ITERATOR_H
#include "Nodo.h"
template <typename Tipo>
class Iterator;
template <typename Tipo>
ostream& operator << (ostream &o, const Iterator<Tipo> &a);
template<typename Tipo>
class Iterator{
    private:
        int ubicar=0;
        Nodo<Tipo> *g;
    public:
        Iterator(Nodo<Tipo> *b);
        Nodo<Tipo> *posicion();
        int ubicacion();
        friend ostream& operator << <>(ostream &o, const Iterator<Tipo> &a);
        Iterator& operator ++();
        bool operator!=(Nodo<Tipo>*p);
        ~Iterator();
};
//Constructores
template<typename Tipo>
Iterator<Tipo>::Iterator(Nodo<Tipo> *b){
    if(b!=nullptr){
        g = b;
    }
    else {
        g = nullptr;
    }
}
//Funciones extra
template<typename Tipo>
Nodo<Tipo> *Iterator<Tipo>::posicion() {
    if (g != nullptr) {
        return g;
    }
    else {
        return nullptr;
    }
}
template<typename Tipo>
int Iterator<Tipo>::ubicacion() {
    return ubicar;
}
//Operadores
template<typename Tipo>
ostream& operator << (ostream &o, const Iterator<Tipo> &a){
    o<<a.g->Devol2();
    return o;
}
template<typename Tipo>
Iterator<Tipo>& Iterator<Tipo>::operator ++(){
    if(this->g->Devolver()==nullptr){
        ubicar = 0;
        this->g=nullptr;
    }
    else{
        ubicar++;
        this->g=this->g->Devolver();
    }
    return *this;
}
template<typename Tipo>
bool Iterator<Tipo>::operator!=(Nodo<Tipo>*p){
    if (p == nullptr||g==nullptr) {
        return false;
    }
    else {
        return this->g != p->Devolver();
    }
}
//Destructor
template<typename Tipo>
Iterator<Tipo>::~Iterator(){
}
#endif