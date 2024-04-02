#include "../../headers/Modelo/Product.h"

void Product::show_product() {
    std::time_t date = std::chrono::system_clock::to_time_t(date_expiration);
    std::cout << "Codigo: " << code_item << std::endl;
    std::cout << "Nombre: " << name_item << std::endl;
    std::cout << "Precio: " << price_item << std::endl;
    std::cout << "Cantidad: " << num_stock << std::endl;
    std::cout << "Fecha de Vencimiento: "<< std::ctime(&date);
}

void Product::set_code() {
    int code_item;
    bool bandera = false;
    do{
        std::cout << "Ingrese Codigo Producto: ";
        std::cin >> code_item;

        if (code_item == 23) {
            std::cout << "Codigo Ya Existe" << std::endl;
        }else{
            bandera = true;
        }
    } while (!bandera);
}

void Product::set_name() {
    std::string name_item;
    std::cout << "Ingrese Nombre del Producto: ";
    std::cin.ignore();
    getline(std::cin, name_item);
}

void Product::set_price() {
    double price_item;
    std::cout << "Ingrese el Precio del Producto ";
    std::cin >> price_item;
}

void Product::set_stock() {
    int num_stock_item;
    std::cout << "Ingrese Cantidad Disponible del Producto: ";
    std::cin >> num_stock_item;
}

void Product::set_date() {
    int day, month, year;
    //  Verificación de Ingreso de Fecha
    //format_date(day, month, year);
    std::tm time = {};
    time.tm_mday = day;
    time.tm_mon = month - 1;  // tm_mon empieza desde 0
    time.tm_year = year - 1900; // tm_year es el año - 1900
    std::time_t date = std::mktime(&time);
    auto date_expiration = std::chrono::system_clock::from_time_t(date);
}

int Product::get_code() {
    return code_item;
}

std::string Product::get_name() {
    return name_item;
}

double Product::get_price() {
    return price_item;
}

int Product::get_stock() {
    return num_stock;
}

void Product::get_date() {

}
