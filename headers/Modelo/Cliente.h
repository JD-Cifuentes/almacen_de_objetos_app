//
// Created by juan- on 25/03/2024.
//

#ifndef PROYECTO_CLIENTE_H
#define PROYECTO_CLIENTE_H
#include "../../utils/headers/PrintUtils.h"
#include <chrono>
#include <vector>
#include <iostream>
using namespace std;

class Cliente {

private:
    int idCliente;
    string nameCliente;
    int year;
    int month;
    int day;
    chrono::year_month_day fechaNacimiento = chrono::year_month_day(chrono::year(year),
                                                                    chrono::month(month),
                                                                    chrono::day(day));
public:
    Cliente(int idCliente , string nameCliente, chrono::year_month_day fechaNacimiento);
    int getidCliente();
    string getnameCliente();

    void show_Cliente();
    void setnameCliente(string nuevoName);
    void setfechaNacimiento(chrono::year_month_day nuevafecha);


};

#endif //PROYECTO_CLIENTE_H
