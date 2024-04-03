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
            cout << "Ingrese la fecha de Nacmiento del Cliente (Año): " << endl;
            cin >> year;
            if (cin.fail()) {
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
    do {
        try {
            int buscarCliente;
            cout << "Ingrese el ID del cliente: ";
            cin >> buscarCliente;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un número entero");
            }
            bool encontrado = false;
            for (Cliente cliente : vecClientes) {
                if (cliente.getidCliente() == buscarCliente) {
                    cliente.show_Cliente();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "No se encontró ningún cliente con el ID " << buscarCliente << endl;
            }
            break;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Ocurrió un error inesperado" << endl;
        }
    } while (true);
}


void ClienteService::actualizarCliente() {
    system("cls");
    bool encontrado = false;
    int idCliente;
    string opcion;

    // Solicitar al usuario el ID del cliente a actualizar
    do {
        try {
            cout << "Ingrese el ID del cliente a actualizar: ";
            cin >> idCliente;
            if (cin.fail() || idCliente <= 0) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un ID de cliente válido");
            }
            break;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Inválida" << endl;
            cin.clear();
            cin.ignore();
        }
    } while(true);

    // Buscar el cliente por su ID y actualizar la información si se encuentra
    for (auto it = vecClientes.begin(); it != vecClientes.end(); ++it) {
        if (it->getidCliente() == idCliente) {
            encontrado = true;

            cout << "¿Qué desea actualizar?" << endl;
            cout << "1. Nombre del cliente" << endl;
            cout << "2. Fecha de nacimiento del cliente" << endl;
            cout << "Ingrese su opción: ";
            cin >> opcion;

            if (opcion == "1") {
                // Actualizar el nombre del cliente
                string nuevoNombre;
                cout << "Ingrese el nuevo nombre del cliente: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                it->setnameCliente(nuevoNombre);
                cout << "Nombre actualizado correctamente." << endl;
            } else if (opcion == "2") {
                // Actualizar la fecha de nacimiento del cliente
                int day, month, year;
                cout << "Ingrese la nueva fecha de nacimiento del cliente (Dia Mes Año): ";
                cin >> day >> month >> year;
                if (cin.fail() || day <= 0 || month <= 0 || month > 12 || year < 1900) {
                    cin.clear();
                    cin.ignore();
                    cout << "Error: Ingrese una fecha de nacimiento válida" << endl;
                } else {
                    it->setfechaNacimiento(chrono::year_month_day(chrono::year(year), chrono::month(month), chrono::day(day)));
                    cout << "Fecha de nacimiento actualizada correctamente." << endl;
                }
            } else {
                cout << "Opción no válida." << endl;
            }
            break;
        }
    }

    // Si el cliente no se encontró, mostrar un mensaje de error
    if (!encontrado) {
        cout << "No se encontró ningún cliente con el ID proporcionado." << endl;
    }
}