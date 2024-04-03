#include "../../headers/Vista/MenuProduct.h"

void menu() {
    PrintUtils::printCenter("Bienvenido al Menu de Productos");
    PrintUtils::printCenter("Seleccione la Opcion Deseada");
    PrintUtils::printTabular("1. Registar Producto");
    PrintUtils::printTabular("2. Buscar Producto");
    PrintUtils::printTabular("3. Actualizar Producto");
    PrintUtils::printTabular("4. Eliminar Producto");
    PrintUtils::printTabular("0. Regresar al menu principal");
}

void MenuProduct :: menu_product(){
    int option = 0;
    do {
        menu();
        cout << ">";
        cin >> option;
        switch(option){
            case 1:
                ProductService::crear_producto();
                break;
            case 2:
                ProductService::buscar_producto();
                break;
            case 3:
                ProductService::actualizar_producto();
                break;
            case 4:
                ProductService::eliminar_producto();
                break;
            default:
                cout << "Opcion Incorrecta" << endl;
        }
    } while(option != 0);
}