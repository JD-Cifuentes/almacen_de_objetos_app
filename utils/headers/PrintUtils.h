//
// Created by juan- on 28/03/2024.
//

#ifndef PROYECTO_PRINTUTILS_H
#define PROYECTO_PRINTUTILS_H

#include <iomanip>
#include <iostream>
#include <chrono>

using namespace std;

class PrintUtils {
public:
    static void printTabular(const string& oracion);
    static void printCenter(const string& oracion);
    static void printDosColumnas(const string& oracion1, const string& oracion2);
    static void printDosColumnas(const string& oracion1, int oracion2);
    static void printDosColumnas(const string& oracion1, chrono::year_month_day oracion2);
    static void printDosColumnas(const string& oracion1, double oracion2);
};


#endif //PROYECTO_PRINTUTILS_H
