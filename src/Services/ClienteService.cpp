//
// Created by felip on 29/03/2024.
//
#include <chrono>
#include "../../headers/Services/ClienteService.h"
using namespace std;
vector<Cliente> ClienteService::Clientes;

void ClienteService::crearCliente() {
    int idCliente , day , month , year;
    string name;
    chrono::year_month_day fechaNacimiento;
    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;
    cout << "Ingrese el nombre del cliente: ";
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    getline(cin, name);
    cout << "Ingrese la fecha de nacimiento del cliente (Dia)";
    cin >> day;
    cout << "Ingrese la fecha de nacimiento del cliente (Mes)";
    cin >> month;
    cout << "Ingrese la fecha de nacimiento del cliente (Año)";
    chrono::system_clock::time_point fecha = chrono::system_clock::from_time_t(0);



}


void ClienteService::eliminarCliente() {
    int idCliente;
    cout << "\nIngrese el código del Cliente: ";
    cin >> idCliente;
    if (ClienteService::Clientes.empty()){
        cout << "No hay Clientes creados\n";
    }else{
        for (Cliente &f: Clientes) {
            if(f.getidCliente() == idCliente){

            }
            cout << "No se encontro un cliente con ese ID\n";
        }
    }
}