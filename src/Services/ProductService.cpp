#include "../../headers/Services/ProductService.h"

#include <iostream>
#include <chrono>

//  Verificación de Ingreso de Fecha
void set_date_expiration(){
    fflush(stdin);
    bool date_correct = false;
    std::string date_str;
    while(!date_correct){
        std::cout << "Ingrese Fecha De Vencimiento (DD/MM/YYYY): ";
        std::getline(std::cin, date_str);

        std::tm tm = {};
        std::stringstream ss(date_str);
        char delimiter;
        ss >> tm.tm_mday >> delimiter >> tm.tm_mon >> delimiter >> tm.tm_year;
                if (tm.tm_mday <= 0 || tm.tm_mday > 31 || tm.tm_mon <= 0 || tm.tm_mon >12 || tm.tm_year <= 0 ||
                (tm.tm_mon == 2 && tm.tm_mday > 28) || (tm.tm_mon == 4 && tm.tm_mday > 30) ||
                (tm.tm_mon == 6 && tm.tm_mday > 30) || (tm.tm_mon == 9 && tm.tm_mday > 30) ||
                (tm.tm_mon == 11 && tm.tm_mday > 30)) {
            std::cout << "Formato de Fecha Incorrecto ";
            std::cout << "Por favor ingrese formato (DD/MM/YYYY)" << std::endl;
        } else {
            date_correct = true;
            tm.tm_year -= 1900; // Ajustar el año
            tm.tm_mon -= 1;     // Ajustar el mes
            std::cout << "Fecha de Vencimiento Ingresada: " << std::put_time(&tm, "%d/%m/%Y") << std::endl;
        }
    }
}

void ProductService::create_product(){
    int code;
    bool bandera;
    bandera = false;
    std::cout << "Create" << std::endl;
    do{
        std::cout << "Ingrese Codigo Producto: ";
        std::cin >> code;
        if (code == true) {
            std::cout << "Codigo Ya Existe" << std::endl;
        }else{
            bandera = true;
        }
    } while (!bandera);
    set_date_expiration();
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

