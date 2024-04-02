#include "../../headers/Modelo/Product.h"

void Product::get_product() {
    std::time_t date = std::chrono::system_clock::to_time_t(date_expiration);
    std::cout << "Codigo: " << code_item << std::endl;
    std::cout << "Nombre: " << name_item << std::endl;
    std::cout << "Precio: " << price_item << std::endl;
    std::cout << "Cantidad: " << num_stock << std::endl;
    std::cout << "Fecha de Vencimiento: "<< std::ctime(&date);
}

void Product::set_product() {

}
