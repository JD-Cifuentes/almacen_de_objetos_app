#include <iostream>
#include <chrono>
#include "./headers/Vista/MenuFactura.h"
#include "headers/Vista/MenuProduct.h"

using namespace std;


int main() {
/*
    cout << "Hello, World!" << endl;
    int year = 2022;
    int month = 3;
    int day = 24;
    chrono::year_month_day ymd = chrono::year_month_day(chrono::year(year),
                                                                  chrono::month(month),
                                                                  chrono::day(day));
    cout << ymd;

*/

   while(true){
        //MenuFactura::menuParaFacturas();
        MenuProduct::menu_product();
        break;
   }

    return 0;
}
