//
// Created by juan- on 28/03/2024.
//

#include "../headers/PrintUtils.h"


void PrintUtils::printTabular(const string& oracion) {
    unsigned int anchoSangria = 15;
    cout << setw(anchoSangria) << "" << oracion << std::endl;
}

void PrintUtils::printCenter(const string& oracion) {
    unsigned int anchoDeLinea = 100;
    unsigned int espacios = (anchoDeLinea - oracion.size()) / 2;
    cout << setw(espacios) << "" << oracion << std::endl;
}
