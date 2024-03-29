//
// Created by juan- on 26/03/2024.
//

#include "../../headers/Modelo/Factura.h"


int Factura::contadorIdFactura = 0;

Factura::Factura(int idCliente) {
    auto actual = chrono::system_clock::now();
    Factura::idCliente = idCliente;
    Factura::idFactura = Factura::contadorIdFactura;
    Factura::fechaFactura = chrono::year_month_day(chrono::floor<chrono::days>(actual));
    Factura::contadorIdFactura++;
}

void Factura::descripcionFactura() {
    /*////////////////////*/
    PrintUtils::printDosColumnas("Factura ID", idFactura);
    PrintUtils::printDosColumnas("Cliente ID", idCliente);
    PrintUtils::printDosColumnas("Fecha de compra", fechaFactura);
    PrintUtils::printDosColumnas("Total de la compra", totalFactura);
// Factura ID
    for(vector<int> productoFacturado : productosFacturados){

    }
}

int Factura::getIdFactura() {
    return idFactura;
}


