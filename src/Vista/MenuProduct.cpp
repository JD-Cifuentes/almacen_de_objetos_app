#include "../../headers/Vista/MenuProduct.h"

void menu() {
    cout << "\n";
    PrintUtils::printCenter("Bienvenido al Menu de Productos");
    PrintUtils::printCenter("Seleccione la Opcion Deseada");
    cout << "\n";
    PrintUtils::printTabular("1. Registar Producto");
    PrintUtils::printTabular("2. Buscar Producto");
    PrintUtils::printTabular("3. Actualizar Producto");
    PrintUtils::printTabular("4. Eliminar Producto");
    PrintUtils::printTabular("0. Regresar al menu principal");
}

void MenuProduct ::menuParaProductos() {
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
                    cout << "Saliendo del Menu para Productos" << endl;
                    validacion = true;
                    break;
                case 1:
                    ProductService::crearProducto();
                    break;
                case 2:
                    ProductService::buscarProducto();
                    break;
                case 3:
                    ProductService::actualizarProducto();
                    break;
                case 4:
                    ProductService::eliminarProducto();
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