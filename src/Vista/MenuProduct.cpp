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
    int option;
    bool validacion = false;
    do {
        try {
            menu();
            cout << ">";
            cin >> option;
            if (cin.fail()){
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un numero entero");
            }
            switch(option){
                case 0:
                    cout << "Saliendo del programa..." << endl;
                    validacion = true;
                    break;
                case 1:
                    ProductService::crear_producto();
                    validacion = true;
                    break;
                case 2:
                    ProductService::buscar_producto();
                    validacion = true;
                    break;
                case 3:
                    ProductService::actualizar_producto();
                    validacion = true;
                    break;
                case 4:
                    ProductService::eliminar_producto();
                    validacion = true;
                    break;
                default:
                    throw invalid_argument("Error: Opcion Incorrecta");
            }
        }catch (invalid_argument &ex){
            cout << ex.what() << endl;
        }catch (...){
            cout << "Error: Entrada Invalida" << endl;
            cin.clear();
            cin.ignore();
        }
    } while(!validacion);
}