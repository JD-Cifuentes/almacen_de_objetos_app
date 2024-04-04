//
// Created by juan- on 28/03/2024.
//

#include "../headers/PrintUtils.h"


void PrintUtils::printTabular(const string& oracion) {
    cout << setw(anchoSangria) << oracion << endl;
}

void PrintUtils::printCenter(const string& oracion) {
    unsigned int espacios = (anchoDeLinea - oracion.size()) / 2;
    cout << setw(espacios) << oracion << endl;
}

void PrintUtils::printDosColumnas(const string &oracion1, const string &oracion2) {
    unsigned int espacios = (anchoEspacioDosCol - oracion1.size());
    string espaciador(espacios, '.');
    cout << oracion1 << espaciador << oracion2 << endl;
}

void PrintUtils::printDosColumnas(const string &oracion1, int oracion2) {
    unsigned int espacios = (anchoEspacioDosCol - oracion1.size());
    string espaciador(espacios, '.');
    cout << oracion1 << espaciador << oracion2 << endl;
}

void PrintUtils::printDosColumnas(const string &oracion1, chrono::year_month_day oracion2) {
    unsigned int espacios = (anchoEspacioDosCol - oracion1.size());
    string espaciador(espacios, '.');
    cout << oracion1 << espaciador << oracion2 << endl;
}

void PrintUtils::printDosColumnas(const string &oracion1, double oracion2) {
    unsigned int espacios = (anchoEspacioDosCol - oracion1.size());
    string espaciador(espacios, '.');
    cout << oracion1 << espaciador << oracion2 << endl;
}

void PrintUtils::printFilaProducto(int oracion1,
                                   const string& oracion2,
                                   int oracion3,
                                   double oracion4) {
    unsigned int espacios = (anchoEspacioDosCol - to_string(oracion1).size());
    string espaciador1(espacios, '.');
    espacios = (anchoEspacioDosCol - oracion2.size());
    string espaciador2(espacios, '.');
    espacios = (anchoEspacioDosCol - to_string(oracion3).size());
    string espaciador3(espacios, '.');

    cout << oracion1 << espaciador1 << oracion2 << espaciador2 <<
            oracion3 << espaciador3 << oracion4 << endl;

}

void PrintUtils::printFilaProducto(const string &oracion1,
                                   const string &oracion2,
                                   const string &oracion3,
                                   const string &oracion4) {
    unsigned int espacios = (anchoEspacioDosCol - oracion1.size());
    string espaciador1(espacios, ' ');
    espacios = (anchoEspacioDosCol - oracion2.size());
    string espaciador2(espacios, ' ');
    espacios = (anchoEspacioDosCol - oracion3.size());
    string espaciador3(espacios, ' ');

    cout << oracion1 << espaciador1 << oracion2 << espaciador2 <<
            oracion3 << espaciador3 << oracion4 << endl;
}

