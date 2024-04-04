//
// Created by juan- on 28/03/2024.
//

#ifndef PROYECTO_FACTURASERVICE_H
#define PROYECTO_FACTURASERVICE_H
#include <vector>
#include <iostream>
#include "../Modelo/Factura.h"
#include "../../headers/Services/ClienteService.h"
#include "../../headers/Services/ProductService.h"
#include "../../headers/Modelo/Cliente.h"
#include "../../headers/Modelo/Product.h"

class FacturaService {
public:
    static vector<Factura> Facturas;

    static void crearYGuardarFactura();
    static void consultarFactura();
    static void consultarTodasLasFactura();
    static void eliminarFactura();
};

#endif //PROYECTO_FACTURASERVICE_H
