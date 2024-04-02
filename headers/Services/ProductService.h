#ifndef PROYECTO_PRODUCTSERVICE_H
#define PROYECTO_PRODUCTSERVICE_H

#include "../Modelo/Product.h"

#include <iostream>
#include <vector>
#include <chrono>

class ProductService {
private:
    std::chrono::system_clock::time_point date_expiration;
public:

    static std::vector<Product> Productos;
    static void create_product();
    static void search_product();
    static void update_product();
    static void delete_product();
    //void get_date();
    //void set_date();
};

#endif //PROYECTO_PRODUCTSERVICE_H
