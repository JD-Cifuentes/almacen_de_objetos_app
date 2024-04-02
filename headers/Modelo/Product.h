#ifndef ALMACEN_DE_OBJETOS_APP_PRODUCT_H
#define ALMACEN_DE_OBJETOS_APP_PRODUCT_H

#include "../Services/ProductService.h"

#include <iostream>
#include <chrono>

class Product {
private:
    int code_item, num_stock;
    std::string name_item;
    double price_item;
public:
    std::chrono::system_clock::time_point date_expiration;
    void get_product();
    void set_product();
};

#endif //ALMACEN_DE_OBJETOS_APP_PRODUCT_H
