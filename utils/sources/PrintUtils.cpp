//
// Created by juan- on 28/03/2024.
//

#include "../headers/PrintUtils.h"


void PrintUtils::printTabular(const string& oracion) {
    unsigned int anchoSangria = 15;
    cout << setw(anchoSangria) << "." << oracion << endl;
}

void PrintUtils::printCenter(const string& oracion) {
    unsigned int anchoDeLinea = 100;
    unsigned int espacios = (anchoDeLinea - oracion.size()) / 2;
    cout << setw(espacios) << "" << oracion << endl;
}

void PrintUtils::printDosColumnas(const string &oracion1, const string &oracion2) {
    unsigned int anchoEspacio = 15;
    string espaciador(anchoEspacio, '.');
    cout << oracion1 << espaciador << "" << oracion2 << endl;
}

void PrintUtils::printDosColumnas(const string &oracion1, int oracion2) {
    unsigned int anchoEspacio = 15;
    string espaciador(anchoEspacio, '.');
    cout << oracion1 << espaciador << "" << oracion2 << endl;
}

void PrintUtils::printDosColumnas(const string &oracion1, chrono::year_month_day oracion2) {
    unsigned int anchoEspacio = 15;
    string espaciador(anchoEspacio, '.');
    cout << oracion1 << espaciador << "" << oracion2 << endl;
}

void PrintUtils::printDosColumnas(const string &oracion1, double oracion2) {
    unsigned int anchoEspacio = 25;
    string espaciador(anchoEspacio, '.');
    cout << oracion1 << espaciador << "" << oracion2 << endl;
}
