//
// Created by juan- on 26/03/2024.
//

#ifndef PROYECTO_FACTURA_H
#define PROYECTO_FACTURA_H
#include "../../utils/headers/PrintUtils.h"
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
    vector<vector<int>> productosFacturados;

public:
    Factura(int idCliente);

    //agregarProductoVendido(Producto nuevoProducto);

    void descripcionFactura();

    int getIdFactura();

};


#endif //PROYECTO_FACTURA_H
