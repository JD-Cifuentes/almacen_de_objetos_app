#include "../../headers/Services/ProductService.h"

void set_date(int& _day, int& _month, int& _year) {
    bool correct = false;
    do{
        std::cout << "Ingrese Fecha De Vencimiento (DD MM YYYY): ";
        std::cin >> _day >> _month >> _year;
        if(_day <= 0 || _day > 31 || _month <= 0 || _month >12 || _year <= 0 ||
           (_month == 2 && _day > 28) || (_month == 4 && _day > 30) || (_month == 6 && _day > 30) ||
           (_month == 9 && _day > 30) || (_month == 11 && _day > 30)){
            std::cout << "Fecha Incorrecta " << std::endl;
            std::cout << "Por favor ingrese formato (DD MM YYYY)" << std::endl;
        }else{
            correct = true;
        }
    }while(!correct);
}

void ProductService::create_product(){
    int code_item, num_stock_item;
    double price_item;
    bool bandera = false;
    std::string name_item;

    int day, month, year;
    bool correct = false;

    std::cout << "Create" << std::endl;
    do{
        std::cout << "Ingrese Codigo Producto: ";
        std::cin >> code_item;

        for (const auto& vec : Productos) {
            if (!vec.empty() && vec[0].getId() == entero) {
                // El primer elemento del vector actual es igual al entero
                // Realiza aquí las acciones que deseas realizar si la comparación es verdadera
                std::cout << "El primer elemento del vector es igual a " << entero << std::endl;
            } else {
                // Realiza aquí las acciones que deseas realizar si la comparación es falsa
                std::cout << "El primer elemento del vector no es igual a " << entero << std::endl;
            }
        }

        if (code_item == Productos[0]) {
            std::cout << "Codigo Ya Existe" << std::endl;
        }else{
            bandera = true;
        }
    } while (!bandera);
    std::cout << "Ingrese Nombre del Producto: ";
    std::cin.ignore();
    getline(std::cin, name_item);

    std::cout << "Ingrese el Precio del Producto ";
    std::cin >> price_item;

    std::cout << "Ingrese Cantidad Disponible del Producto: ";
    std::cin >> num_stock_item;

    //  Verificación de Ingreso de Fecha
    set_date(day, month, year);
    std::tm time = {};
    time.tm_mday = day;
    time.tm_mon = month - 1;  // tm_mon empieza desde 0
    time.tm_year = year - 1900; // tm_year es el año - 1900
    std::time_t date = std::mktime(&time);
    auto date_expiration = std::chrono::system_clock::from_time_t(date);
    //Productos.push_back(Product(code_item, name_item, price_item, num_stock_item, date);

}

void ProductService::search_product(){
    std::cout << "Search" << std::endl;
}

void ProductService::update_product(){
    std::cout << "Update" << std::endl;
}

void ProductService::delete_product(){
    std::cout << "Delete" << std::endl;
}
