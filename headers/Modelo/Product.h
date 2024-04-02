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
    void show_product();
    void set_code();
    void set_name();
    void set_price();
    void set_stock();
    void set_date();
    int get_code();
    std::string get_name();
    double get_price();
    int get_stock();
    void get_date();

};

#endif //ALMACEN_DE_OBJETOS_APP_PRODUCT_H
