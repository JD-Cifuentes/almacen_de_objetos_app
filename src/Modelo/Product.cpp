#include "../../headers/Modelo/Product.h"

vector<Product> Product::Productos;

int Product::contaIdProducto = 0;

Product::Product(int idProducto, string nombreProductos, int cantidad, double precioVentas, chrono::year_month_day fechaVence){
    Product::idProducto = idProducto;
    Product::nombreProducto = nombreProductos;
    Product::cantidad = cantidad;
    Product::precioVenta = precioVentas;
    //se corrige asignacion de fecha
    Product::fechaVencimiento = fechaVence;
}
//se agrega metodo para descontar cantidad
bool Product::descontarCantidadVendida(int cantidadVendida){
    if(cantidadVendida > getCantidad()){
        cout << "No hay cantidad suficiente\n" << endl;
        return false;
    }else{
        int cantidadActualizada = getCantidad() - cantidadVendida;
        setCantidad(cantidadActualizada);
        return true;
    }
}

void Product::showProduct() {
    cout << "Codigo: " << idProducto << endl;
    cout << "Nombre: " << nombreProducto << endl;
    cout << "Precio: " << precioVenta << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Fecha de Vencimiento: " << fechaVencimiento << endl;

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
    //se corrige asignacion de fecha
    fechaVencimiento = nuevaFecha;
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
chrono::year_month_day Product::getFechaVencimiento() {
    return fechaVencimiento;
}