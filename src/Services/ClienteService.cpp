//
// Created by felip on 29/03/2024.
//

#include "../../headers/Services/ClienteService.h"
using namespace std;
vector<Cliente> ClienteService::Clientes;

void ClienteService::crearCliente() {
    int idCliente , day , month , year;
    string nameCliente;
    chrono::year_month_day fechaNacimiento ;

    cout << "Ingrese el ID del cliente: ";
    cin >> idCliente;
    cout << "Ingrese el nombre del cliente: ";
    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
    getline(cin, nameCliente);
    cout << "Ingrese la fecha de nacimiento del cliente (Dia)";
    cin >> day;
    cout << "Ingrese la fecha de nacimiento del cliente (Mes)";
    cin >> month;
    cout << "Ingrese la fecha de nacimiento del cliente (Año)";
    cin >> year;
    fechaNacimiento = chrono::year_month_day(chrono::year(year), chrono::month(month), chrono::day(day));
    Clientes.push_back(Cliente(idCliente, nameCliente, fechaNacimiento));
}


void ClienteService::eliminarCliente() {
    system("cls");
    bool bandera = false;
    int buscar;
    cout<<"Ingrese el codigo a buscar: ";
    cin>>buscar;
    Cliente Auxiliar;
    int n = Clientes.size();
    for(int i = 0; i < n; i++){
        Auxiliar = Clientes[i];
        if(Auxiliar.getidCliente() == buscar){
            bandera = true;
            cout<<"El cliente con el ID"<<endl;
            cout<<Auxiliar.getidCliente()<<endl;
            cout<<"Ya no tiene datos registrados";
            Clientes.erase(Clientes.begin()+i);
            break;
        }
    }
    if(!bandera){
        cout<<"El Cliente con ID "<<buscar<<
            " no existe"<<endl<<endl;
    }
}



