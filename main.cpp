#include <iostream>
#include <chrono>
#include "./headers/Vista/MenuFactura.h"

using namespace std;

int main() {
/*
    std::cout << "Hello, World!" << std::endl;
    int year = 2022;
    int month = 3;
    int day = 24;
    std::chrono::year_month_day ymd = std::chrono::year_month_day(std::chrono::year(year),
                                                                  std::chrono::month(month),
                                                                  std::chrono::day(day));
    std::cout << ymd;

*/

   // while(true){
        MenuFactura::menuParaFacturas();

   // }

    return 0;
}
