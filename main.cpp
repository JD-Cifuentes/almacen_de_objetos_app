#include <iostream>
#include <chrono>
#include "./headers/Vista/MenuFactura.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    int year = 2022;
    int month = 3;
    int day = 24;
    chrono::year_month_day ymd = chrono::year_month_day(chrono::year(1995),
                                                      chrono::month(4),
                                                      chrono::day(2));
    cout << ymd;


   /*while(true){
        MenuFactura::menuParaFacturas();
        break;
   }

    return 0;*/
}
