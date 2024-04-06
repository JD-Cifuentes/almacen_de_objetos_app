#ifndef PROYECTO_PRODUCTSERVICE_H
#define PROYECTO_PRODUCTSERVICE_H

#include "../Modelo/Product.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <stdexcept>
#include <limits>

using namespace std;

class ProductService {
public:
    static vector<Product> Productos;

    static void crearProducto();
    static void buscarProducto();
    static void actualizarProducto();
    static void eliminarProducto();
    static void mostrarProductos();

};

#endif //PROYECTO_PRODUCTSERVICE_H
