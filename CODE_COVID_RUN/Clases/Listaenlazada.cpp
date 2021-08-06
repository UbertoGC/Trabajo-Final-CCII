#include <iostream>
#include "Listaenlazada.h"
using namespace std;
int main(){
	//con strings
    Listaenlazada<string> a;
    a.Anadir("hola");
    a.Anadir("como");
    a.Anadir("estas");
    a.Anadir("amigo");
    a.Anadir("compa");
    a.Anadir("causa");
    Iterator<string> i(a.begin());
    for (;i!=a.end();++i){
        cout<<i<<" "<<i.ubicacion()<<endl;
    }
    cout<<endl;
    return 0;
}
