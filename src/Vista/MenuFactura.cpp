//
// Created by juan- on 26/03/2024.
//

#include "../../headers/Vista/MenuFactura.h"


 void MenuFactura::menuParaFacturas() {
     PrintUtils::printCenter("Bienvenido al menu de facturas");
     PrintUtils::printCenter("A continuacion seleccione la opcion deseada");
     PrintUtils::printTabular("1 - Generar factura");
     PrintUtils::printTabular("2 - Consultar factura");
     PrintUtils::printTabular("3 - Eliminar producto de factura");
}
