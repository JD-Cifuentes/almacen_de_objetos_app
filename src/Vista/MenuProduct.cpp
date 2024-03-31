#include "../../headers/Vista/MenuProduct.h"

void menu() {
    //system("cls");
    PrintUtils::printCenter("Bienvenido al Menu de Productos");
    PrintUtils::printCenter("Seleccione la Opcion Deseada");
    PrintUtils::printTabular("1. Registar Producto");
    PrintUtils::printTabular("2. Buscar Producto");
    PrintUtils::printTabular("3. Actualizar Producto");
    PrintUtils::printTabular("4. Eliminar Producto");
    PrintUtils::printTabular("0. Regresar al menu principal");
}
void MenuProduct :: menu_product(){
    int option = 0;/*
    PrintUtils::printCenter("Bienvenido al Menu de Productos");
    PrintUtils::printCenter("Seleccione la Opcion Deseada");
    PrintUtils::printTabular("1. Registar Producto");
    PrintUtils::printTabular("2. Buscar Producto");
    PrintUtils::printTabular("3. Actualizar Producto");
    PrintUtils::printTabular("4. Eliminar Producto");
    PrintUtils::printTabular("0. Regresar al menu principal");
*/
    /*std::cout << "Seleccione Una Opcion" << std::endl;
    std::cout << "1. Registrar Producto" << std::endl;
    std::cout << "2. Buscar Producto" << std::endl;
    std::cout << "3. Actualizar Producto" << std::endl;
    std::cout << "4. Eliminar Producto" << std::endl;
    std::cout << "0. Regresar" << std::endl;
     */
    do {
        menu();
        std::cout << ">";
        cin >> option;
        switch(option){
            case 1:
                ProductService::create_product();
                break;
            case 2:
                ProductService::search_product();
                break;
            case 3:
                ProductService::update_product();
                break;
            case 4:
                ProductService::delete_product();
                break;
            default:
                std::cout << "Opcion Incorrecta" << std::endl;
        }
    } while(option != 0);
}