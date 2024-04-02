//
// Created by felip on 29/03/2024.
//

#ifndef PROYECTO_CLIENTESERVICE_H
#define PROYECTO_CLIENTESERVICE_H
#include <vector>
#include <iostream>
#include <chrono>
#include "../Modelo/Cliente.h"

class ClienteService {
public:
    static vector<Cliente> Clientes;

    static void crearCliente();
    static void consultarCliente();
    static void consultarTodosLosClientes();
    static void eliminarCliente();

};


#include "../Modelo/Factura.h"

#endif //PROYECTO_CLIENTESERVICE_H
