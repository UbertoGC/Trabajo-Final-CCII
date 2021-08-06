#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;
template<typename Tipo>
class Nodo{
    private:
    Tipo dato;
    Nodo<Tipo> *sig;
    public:
    Nodo(Tipo a);
    Nodo(Nodo<Tipo> &a);
    Nodo<Tipo> *&Devolver();
    Tipo &Devol2();
};
//Constructores
template<typename Tipo>
Nodo<Tipo>::Nodo(Tipo a){
    sig=nullptr;
    dato=a;
}
template<typename Tipo>
Nodo<Tipo>::Nodo(Nodo<Tipo> &a){
    this->dato=a.dato;
    if(a.sig==nullptr){
        this->sig=nullptr;
    }
    else{
        this->sig=new Nodo<Tipo>(a.sig->dato);
        Nodo<Tipo> *tmp;
        tmp=a.sig;
        Nodo<Tipo> *tmp2;
        tmp2=this->sig;
        while(tmp->sig!=nullptr){
            tmp2->sig=new Nodo<Tipo>(tmp->sig->dato);
            tmp=tmp->sig;
            tmp2=tmp2->sig;
        }
        tmp->sig=nullptr;
    }
}
//Métodos
template<typename Tipo>
Nodo<Tipo> *&Nodo<Tipo>::Devolver(){
    return sig;
}
template<typename Tipo>
Tipo &Nodo<Tipo>::Devol2(){
    return dato;
}
#endif