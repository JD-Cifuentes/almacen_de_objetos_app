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
    int idProducto, cantidad, year, month, day;
    string nombre_producto;
    double precio_venta;
    chrono::year_month_day fecha_vencimiento;

public:
    Product(int idProducto, string nombre_producto, int cantidad,
            double precio_venta,
            chrono::year_month_day fecha_vencimiento);
    bool descontarCantidadVendida(int cantidadVendida);
    void show_product();
    void set_IdProducto(int idProducto_nuevo);
    void set_nombre_producto(string nuevo_nombre);
    void set_cantidad(int cantidad_vendida);
    void set_precio_venta(double nuevo_precio);
    void set_fecha_vencimiento(chrono::year_month_day nueva_fecha);

    int get_IdProducto();
    string get_nombre_producto();
    int get_cantidad();
    double get_precio_venta();
    chrono::year_month_day get_fecha_vencimiento();
};

#endif //ALMACEN_DE_OBJETOS_APP_PRODUCT_H
