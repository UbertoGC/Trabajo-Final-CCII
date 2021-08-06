#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
#include "Iterator.h"
using namespace std;
template<typename Tipo>
class Listaenlazada{
    private:
        Nodo<Tipo> *head;
        int tama;
    public:
        Listaenlazada();
        Listaenlazada(Tipo a);
        int Size();
        void Anadir(Tipo a);
        void Eliminar(Tipo a);
        Nodo<Tipo>* begin();
        Nodo<Tipo>* end();
        void vaciar();
        ~Listaenlazada();
};
//Constructores
template<typename Tipo>
Listaenlazada<Tipo>::Listaenlazada(){
	head=nullptr;
    tama=0;
}
template<typename Tipo>
Listaenlazada<Tipo>::Listaenlazada(Tipo a){
    head=new Nodo<Tipo>(a);
    tama=1;
}
//Métodos
template<typename Tipo>
int Listaenlazada<Tipo>::Size(){
    return tama;
}
template<typename Tipo>
void Listaenlazada<Tipo>::Anadir(Tipo a){
    if (head==nullptr){
        head=new Nodo<Tipo>(a);
        tama++;
    }
    else{
        Nodo<Tipo> *tmp;
        tmp=head;
        while(tmp->Devolver()!=nullptr){
            tmp=tmp->Devolver();
        }
        tmp->Devolver() = new Nodo<Tipo>(a);
        tama++;
    }
}
template<typename Tipo>
void Listaenlazada<Tipo>::Eliminar(Tipo a){
    if (tama>0){
        if(a==head->Devol2()){
            if(tama>1){
                Nodo<Tipo> *tmp;
                tmp=new Nodo<Tipo>(*(head->Devolver()));
                delete head;
                head=tmp;
                tama--;
                cout << "Elemento eliminado" << endl;
            }
            else if(tama==1){
                delete head;
                head=nullptr;
                tama = 0;
                cout << "Elemento eliminado" << endl;
            }
        }
        else{
            Nodo<Tipo>* tmp;
            tmp = head;
            int cont=0;
            for (int i=0; i < tama ; i++) {
                if (tmp->Devolver() != nullptr) {
                    if (tmp->Devolver()->Devol2()==a) {
                        cont = 2;
                        break;
                    }
                    else {
                        tmp = tmp->Devolver();
                    }
                }
                else {
                    break;
                }
            }
            if (cont == 2) {
                if (tmp->Devolver()->Devolver() != nullptr) {
                    Nodo<Tipo>* tmp2;
                    tmp2 = new Nodo<Tipo>(*(tmp->Devolver()->Devolver()));
                    delete (tmp->Devolver());
                    tmp->Devolver() = tmp2;
                }
                else {
                    delete (tmp->Devolver());
                    tmp->Devolver() = nullptr;
                }
                tama--;
            }
            else {
                cout << "No hay el elemento en la lista";
            }
            
        }
    }
}
//Métodos relacionados con Iterator
template<typename Tipo>
Nodo<Tipo> *Listaenlazada<Tipo>::begin(){
    return head;
}
template<typename Tipo>
Nodo<Tipo> *Listaenlazada<Tipo>::end(){
    Nodo<Tipo> *tmp;
    if (tama==0) {
        tmp = nullptr;
    }
    else {
        tmp = head;
        for (int i = 0; i < tama - 1; i++) {
            tmp = tmp->Devolver();
        }
    }
    return tmp;
}
template<typename Tipo>
void Listaenlazada<Tipo>::vaciar(){
    if (head != nullptr) {
        delete head;
        tama = 0;
        head = nullptr;
    }
}
//Añadir
//Destructor
template<typename Tipo>
Listaenlazada<Tipo>::~Listaenlazada(){
    delete head;
}

#endif