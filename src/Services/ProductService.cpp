#include "../../headers/Services/ProductService.h"

//  Verificación de Ingreso de Fecha
void set_date_expiration(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    int code_item, num_stock_item;
    double price_item;
    bool bandera = false;
    std::string name_item;
    std::cout << "Create" << std::endl;
    do{
        std::cout << "Ingrese Codigo Producto: ";
        std::cin >> code_item;

        int item;

        if (code_item == item) {
            std::cout << "Codigo Ya Existe" << std::endl;
        }else{
            bandera = true;
        }
    } while (!bandera);
    std::cin.ignore();
    std::cout << "Ingrese Nombre del Producto: ";
    getline(std::cin, name_item);

    std::cin.ignore();
    std::cout << "Ingrese Cantidad Disponible del Producto: ";
    std::cin >> num_stock_item;

    std::cout << "Ingrese el Precio del Producto ";
    std::cin >> price_item;

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

