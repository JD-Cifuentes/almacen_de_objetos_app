//
// Created by juan- on 26/03/2024.
//

#ifndef PROYECTO_FACTURA_H
#define PROYECTO_FACTURA_H
#include "../../utils/headers/PrintUtils.h"
#include "Product.h"
#include <chrono>
#include <vector>
#include <iostream>
using namespace std;

class Factura {
private:
    static int contadorIdFactura ;
    int idFactura;
    int idCliente;
    chrono::year_month_day fechaFactura;
    double totalFactura;
    vector<Product> productosFacturados;

public:
    Factura(int idCliente);

    void agregarProductoVendido(const Product& nuevoProducto);
    void descripcionFactura();

    void setTotalFactura (double nuevoMonto);
    double getTotalFactura();
    int getIdFactura() const;
    chrono::year_month_day getFechaFactura();

};


#endif //PROYECTO_FACTURA_H
