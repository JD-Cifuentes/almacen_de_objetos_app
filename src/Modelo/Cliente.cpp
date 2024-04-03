//
// Created by juan- on 25/03/2024.
//

#include "../../headers/Modelo/Cliente.h"

using namespace std;



Cliente::Cliente(int idCliente,  string nameCliente, chrono::year_month_day fechaNacimiento) {
    Cliente::idCliente = idCliente;
    Cliente::nameCliente = nameCliente;
    Cliente::fechaNacimiento = chrono::year_month_day{chrono::year(year), chrono::month(month), chrono::day(day)};
}
void Cliente::show_Cliente() {
    cout << "ID cliente: " << idCliente << endl;
    cout << "Nombre del Cliente: " << nameCliente << endl;
    cout << "Fecha de Nacimiento: " << fechaNacimiento << endl;
}

void Cliente::setnameCliente(string nuevoName) {
    nameCliente = nuevoName;
}

void Cliente::setfechaNacimiento(chrono::year_month_day nuevafecha) {
    fechaNacimiento = nuevafecha;
}

int Cliente::getidCliente() {
    return idCliente;
}

string Cliente::getnameCliente() {
    return nameCliente;
}