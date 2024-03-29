//
// Created by juan- on 26/03/2024.
//

#ifndef PROYECTO_FACTURA_H
#define PROYECTO_FACTURA_H

#include <chrono>
#include <vector>
#include <iostream>
using namespace std;

class Factura {
private:
    static int contadorIdFactura ;
    int idFactura;
    int idCliente;
    std::chrono::year_month_day fechaFactura;
    double totalFactura;
    std::vector<std::vector<int>> productosFacturados;
public:
    Factura(int idFactura,
            int idCliente,
            std::chrono::year_month_day fechaFactura,
            double totalFactura);

    //agregarProductoVendido(Producto nuevoProducto);

    string descripcionFactura();
};


#endif //PROYECTO_FACTURA_H
