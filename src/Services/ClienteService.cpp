//
// Created by felip on 29/03/2024.
//

#include "../../headers/Services/ClienteService.h"
using namespace std;
vector<Cliente> ClienteService::vecClientes;


void ClienteService::crearCliente() {
    int idCliente, day, month, year;
    string nameCliente;
    chrono::year_month_day fechaNacimiento;

    do {
        try {
            bool bandera = false;
            cout << "Ingrese el ID del cliente: ";
            cin >> idCliente;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un numero entero");
            }
            for (Cliente Cliente: vecClientes) {
                if (Cliente.getidCliente() == idCliente) {
                    cout << "Codigo de Cliente ya Existe" << endl;
                    bandera = true;
                    break;
                }
            }
            if (!bandera) {
                break;
            }
        } catch (runtime_error &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    } while (true);

    do {
        try {
            cout << "Ingrese el Nombre del Cliente: " << endl;
            cin.ignore();
            getline(cin, nameCliente);
            if (nameCliente.empty()) {
                throw invalid_argument("Error: El Nombre del Cliente no puede estar vacio");
            }
            break;
        } catch (runtime_error &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    } while (true);

    do {
        try {
            cout << "Ingrese la fecha de Nacmiento del Clientec(Dia): " << endl;
            cin >> day;
            if (cin.fail() || day <= 0 || day > 31) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un Dia Valido");
            }
            break;
        } catch (runtime_error &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    } while (true);

    do {
        try {
            cout << "Ingrese la fecha de Nacmiento del Clientec(Mes): " << endl;
            cin >> month;
            if (cin.fail() || month <= 0 || month > 12) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un Mes Valido");
            }
            break;
        } catch (runtime_error &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    } while (true);

    do {
        try {
            cout << "Ingrese la fecha de Nacmiento del Clientec(Año): " << endl;
            cin >> year;
            if (cin.fail() || year < 2023) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un Año Valido");
            }
            break;
        } catch (runtime_error &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    } while (true);

    fechaNacimiento = chrono::year_month_day(chrono::year(year), chrono::month(month), chrono::day(day));
    vecClientes.push_back(Cliente(idCliente, nameCliente, fechaNacimiento));
    cout<<"Cliente registrado"<<endl;
}

void ClienteService::eliminarCliente() {
    system("cls");
    bool bandera = false;
    int buscar;

    do{
        try{
            cout << "Ingrese el código a buscar: ";
            cin >> buscar;
            if (cin.fail() || buscar < 0){
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un numero entero");
            }
            break;
        } catch (invalid_argument &ex) {
        cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
            cin.clear();
            cin.ignore();
        }
    }while(true);

    int n = vecClientes.size();
    for(int i = 0; i < n; i++){
        if(vecClientes[i].getidCliente() == buscar){
            bandera = true;
            cout << "El cliente con el ID" << buscar<<"Ya no tiene datos registrados" << endl;
            vecClientes.erase(vecClientes.begin() + i);
            break;
        }
    }
    if(!bandera){
        cout << "El Cliente con ID " << buscar << " no existe" << endl << endl;
    }
}


void ClienteService::consultarTodosLosClientes() {
    for(Cliente Cliente:vecClientes){
        Cliente.show_Cliente();
    }
}

void ClienteService::consultarCliente() {
    cout<<"Ingresar el ID del cliente "<<endl;
}

void ClienteService::actualizarCliente() {

    }