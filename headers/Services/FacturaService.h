//
// Created by juan- on 28/03/2024.
//

#ifndef PROYECTO_FACTURASERVICE_H
#define PROYECTO_FACTURASERVICE_H
#include <vector>
#include <iostream>
#include "../Modelo/Factura.h"

class FacturaService {
public:
    static vector<Factura> Facturas;

    static void crearYGuardarFactura();
    static void consultarFactura();
    static void consultarTodasLasFactura();
    static void eliminarFactura();
};


#endif //PROYECTO_FACTURASERVICE_H
