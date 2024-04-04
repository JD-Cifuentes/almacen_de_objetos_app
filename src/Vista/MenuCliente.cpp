//
// Created by felip on 29/03/2024.
//

#include "../../headers/Vista/MenuCliente.h"

void MenuCliente::menuParaClientes() {
    PrintUtils::printCenter("Bienvenido al menu de Clientes");
    PrintUtils::printCenter("A continuacion seleccione la opcion deseada");
    PrintUtils::printTabular("1 - Añadir un cliente");
    PrintUtils::printTabular("2 - Consultar un cliente");
    PrintUtils::printTabular("3 - Consultar todas los clientes");
    PrintUtils::printTabular("4 - Eliminar un cliente");
    PrintUtils::printTabular("5 - Actualizar datos de un cliente");
    PrintUtils::printTabular("0 - Regresar al menu principal");

    int opcion = 0;
    do {
        cout << "\n\n";
        cin >> opcion;
        switch (opcion) {
            case 1:
                ClienteService::crearCliente();
                break;
            case 2:
                ClienteService::consultarCliente();
                break;
            case 3:
                ClienteService::consultarTodosLosClientes();
                break;
            case 4:
                ClienteService::eliminarCliente();
                break;
            case 5:
                ClienteService::actualizarCliente();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
        }

    } while (opcion != 0);
}
