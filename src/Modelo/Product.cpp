#include "../../headers/Modelo/Product.h"

vector<Product> Product::Productos;

int Product::contaIdProducto = 0;

Product::Product(int idProducto, string nombreProductos, int cantidad, double precioDeVenta, chrono::year_month_day fechaVence){
    Product::idProducto = idProducto;
    Product::nombreProducto = nombreProductos;
    Product::cantidad = cantidad;
    Product::precioVenta = precioDeVenta;
    Product::fechaVencimiento = chrono::year_month_day{chrono::year(year),
                                                       chrono::month(month),
                                                       chrono::day(day)};
}

void Product::showProduct() {
    //std::time_t date = std::chrono::system_clock::to_time_t(date_expiration);
    cout << "Codigo: " << idProducto << endl;
    cout << "Nombre: " << nombreProducto << endl;
    cout << "Precio: " << precioVenta << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Fecha de Vencimiento: " << fechaVencimiento << endl;
    //cout << "Disponibilidad: " << habilitacion << endl;
}

void Product::setIdProducto(int idProductoNuevo) {
    idProducto = idProductoNuevo;
}

void Product::setNombreProducto(string nuevoNombre) {
    nombreProducto = nuevoNombre;
}

void Product::setCantidad(int cantidadVendida) {
    cantidad = cantidadVendida;
}

void Product::setPrecioVenta(double nuevoPrecio) {
    precioVenta = nuevoPrecio;
}

void Product::setFechaVencimiento(chrono::year_month_day nuevaFecha) {
    fechaVencimiento = chrono::year_month_day(chrono::year(year),
                                              chrono::month(month),
                                              chrono::day(day));
}

int Product::getIdProducto() {
    return idProducto;
}

string Product::getNombreProducto() {
    return nombreProducto;
}

int Product::getCantidad() {
    return cantidad;
}

double Product::getPrecioVenta() {
    return precioVenta;

}