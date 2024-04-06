//
// Created by juan- on 26/03/2024.
//

#include "../../headers/Vista/MenuFactura.h"

void MenuFactura::menuParaFacturas() {


    int opcion = 0;
    do {
        cout << "\n\n";
        PrintUtils::printCenter("Bienvenido al menu de facturas");
        PrintUtils::printCenter("A continuacion seleccione la opcion deseada");
        PrintUtils::printTabular("1 - Generar factura");
        PrintUtils::printTabular("2 - Consultar factura");
        PrintUtils::printTabular("3 - Consultar todas las facturas");
        PrintUtils::printTabular("4 - Eliminar factura");
        PrintUtils::printTabular("0 - Regresar al menu principal");
        cin >> opcion;
        switch (opcion) {
            case 1:
                FacturaService::crearYGuardarFactura();
                break;
            case 2:
                FacturaService::consultarFactura();
                break;
            case 3:
                FacturaService::consultarTodasLasFactura();
                break;
            case 4:
                FacturaService::eliminarFactura();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
        }

    } while (opcion != 0);
}