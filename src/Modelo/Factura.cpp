//
// Created by juan- on 26/03/2024.
//

#include "../../headers/Modelo/Factura.h"
int Factura::contadorIdFactura = 0;

Factura::Factura(int idFactura,
                 int idCliente,
                 std::chrono::year_month_day fechaFactura,
                 double totalFactura) {

}

std::string Factura::descripcionFactura() {
    return std::string();
}
