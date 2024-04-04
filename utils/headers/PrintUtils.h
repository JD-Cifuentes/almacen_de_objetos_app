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
private:
    static const unsigned int anchoSangria = 15;
    static const unsigned int anchoDeLinea = 100;
    static const unsigned int anchoEspacioDosCol = 25;
public:
    static void printTabular(const string& oracion);
    static void printCenter(const string& oracion);
    static void printDosColumnas(const string& oracion1, const string& oracion2);
    static void printDosColumnas(const string& oracion1, int oracion2);
    static void printDosColumnas(const string& oracion1, chrono::year_month_day oracion2);
    static void printDosColumnas(const string& oracion1, double oracion2);
    static void printFilaProducto(int oracion1,
                                  const string& oracion2,
                                  int oracion3,
                                  double oracion4);
    static void printFilaProducto(const string& oracion1,
                                  const string& oracion2,
                                  const string& oracion3,
                                  const string& oracion4);
};


#endif //PROYECTO_PRINTUTILS_H
