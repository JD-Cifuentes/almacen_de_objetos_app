#ifndef ALMACEN_DE_OBJETOS_APP_PRODUCT_H
#define ALMACEN_DE_OBJETOS_APP_PRODUCT_H

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;


class Product {
private:
    static vector<Product> Productos;
    static int contaIdProducto;
    int idProducto, cantidad;
    string nombreProducto;
    double precioVenta;
    chrono::year_month_day fechaVencimiento;

public:
    Product(int idProducto, string nombreProductos, int cantidad,
            double precioVentas,
            chrono::year_month_day fechaVence);
    bool descontarCantidadVendida(int cantidadVendida);
    void mostrarProducto();
    void setNombreProducto(string nuevoNombre);
    void setCantidad(int cantidadVendida);
    void setPrecioVenta(double nuevoPrecio);
    void setFechaVencimiento(chrono::year_month_day nuevaFecha);

    int getIdProducto();
    string getNombreProducto();
    int getCantidad();
    double getPrecioVenta();
    chrono::year_month_day getFechaVencimiento();
};

#endif //ALMACEN_DE_OBJETOS_APP_PRODUCT_H
