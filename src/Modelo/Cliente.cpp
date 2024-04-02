//
// Created by juan- on 25/03/2024.
//

#include "../../headers/Modelo/Cliente.h"

using namespace std;


int Cliente::getidCliente() const {
    return idCliente;
}


Cliente::Cliente(int idCliente, int year, int month, int day, string nameCliente, chrono::year_month_day fechaNacimiento) {
    Cliente::idCliente = idCliente;
    Cliente::nameCliente = nameCliente;
    Cliente::fechaNacimiento = chrono::year_month_day{chrono::year(year), chrono::month(month), chrono::day(day)};
}
