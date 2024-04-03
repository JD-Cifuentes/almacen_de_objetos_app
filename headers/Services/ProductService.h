#ifndef PROYECTO_PRODUCTSERVICE_H
#define PROYECTO_PRODUCTSERVICE_H

#include "../Modelo/Product.h"

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class ProductService {
public:
    static vector<Product> Productos;

    static void crear_producto();
    static void buscar_producto();
    static void actualizar_producto();
    static void eliminar_producto();
    static void mostrar_productos();

};

#endif //PROYECTO_PRODUCTSERVICE_H
