//
// Created by San on 29/03/2024.
//

#ifndef PROYECTO_PRODUCTSERVICE_H
#define PROYECTO_PRODUCTSERVICE_H
#include <iostream>
#include <vector>
#include "../Modelo/Product.h"


class ProductService {
public:
    static std::vector<Product> Productos;
    static void create_product();
    static void search_product();
    static void update_product();
    static void delete_product();
};


#endif //PROYECTO_PRODUCTSERVICE_H
