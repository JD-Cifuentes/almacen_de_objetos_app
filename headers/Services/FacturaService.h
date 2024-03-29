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

// static vector<nombre_vector> nombre_vector;
//define que el vector va a trabajar con elementos vector
// static porque permite acceder al error sin necesidad de instanciar la clase
//cuando se declara algo statico es porque se puede acceder desde cualquier parte sin objetos

#endif //PROYECTO_FACTURASERVICE_H
