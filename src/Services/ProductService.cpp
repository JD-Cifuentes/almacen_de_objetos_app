#include "../../headers/Services/ProductService.h"
vector<Product> ProductService::Productos;

void format_date(int& _day, int& _month, int& _year) {
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
    int day, month, year;


    //  Verificación de Ingreso de Fecha
    format_date(day, month, year);
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

bool available(){
    int num_stock;

    auto now = std::chrono::system_clock::now();
    auto date_exp = now + std::chrono::hours(24);

    if(num_stock<1 || (now > date_exp)){
        std::cout << "No hay Cantidades Disponibles" << std::endl;
    }




    int year;
    int month;
    int day;
    std::chrono::year_month_day ymd = std::chrono::year_month_day(std::chrono::year(year),
                                                                  std::chrono::month(month),
                                                                  std::chrono::day(day));

    return true;
}

