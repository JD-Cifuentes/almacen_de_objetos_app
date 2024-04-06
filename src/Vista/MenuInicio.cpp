//
// Created by felip on 29/03/2024.
//


#include "../../headers/Vista/MenuInicio.h"


void menuInicio(){
    cout << "\n";
    PrintUtils::printCenter("Bienvenido al Super Market");
    PrintUtils::printCenter("A continuacion seleccione la opcion deseada");
    cout << "\n";
    PrintUtils::printTabular("1 - Ir apartado Clientes");
    PrintUtils::printTabular("2 - Ir apartado de Productos");
    PrintUtils::printTabular("3 - Ir apartado de Facturas");
    PrintUtils::printTabular("0 - Cerrar Programa");
}


void MenuInicio::menuParaIniciar() {
/*    PrintUtils::printCenter("Bienvenido al Super Market");
    PrintUtils::printCenter("A continuacion seleccione la opcion deseada");
    PrintUtils::printTabular("1 - Ir apartado Clientes");
    PrintUtils::printTabular("2 - Ir apartado de Productos");
    PrintUtils::printTabular("3 - Ir apartado de Facturas");
    PrintUtils::printTabular("0 - Cerrar Programa");*/


    int opcion = 0;
    do {
        menuInicio();
        cout << "\n>";
        cin >> opcion;
        switch (opcion) {
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            case 1:
                MenuCliente::menuParaClientes();
                break;
            case 2:
                MenuProduct::menuParaProductos();
                break;
            case 3:
                MenuFactura::menuParaFacturas();
                break;
            default:
                cout << "Opcion no valida" << std::endl;
        }
    } while (opcion != 0);
}