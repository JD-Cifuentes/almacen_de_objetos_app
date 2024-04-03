#include <iostream>
#include <chrono>
#include "./headers/Vista/MenuFactura.h"
#include "./headers/Vista/MenuInicio.h"
using namespace std;

int main() {

    while(true){
        //MenuFactura::menuParaFacturas();
        MenuInicio::menuParaIniciar();
        break;
    }

    return 0;
}
