#include "../../headers/Modelo/Product.h"

vector<Product> Product::Productos;

int Product::contaIdProducto = 0;

Product::Product(int idProducto, string nombre_producto, int cantidad, double precio_venta, chrono::year_month_day fecha_vencimiento){
    Product::idProducto = idProducto;
    Product::nombre_producto = nombre_producto;
    Product::cantidad = cantidad;
    Product::precio_venta = precio_venta;
    //se corrige asignacion de fecha
    Product::fecha_vencimiento = fecha_vencimiento;
}
//se agrega metodo para descontar cantidad
bool Product::descontarCantidadVendida(int cantidadVendida){
    if(cantidadVendida > get_cantidad()){
        cout << "No hay cantidad suficiente\n" << endl;
        return false;
    }else{
        int cantidadActualizada = get_cantidad() - cantidadVendida;
        set_cantidad(cantidadActualizada);
        return true;
    }
}

void Product::show_product() {
    cout << "Codigo: " << idProducto << endl;
    cout << "Nombre: " << nombre_producto << endl;
    cout << "Precio: " << precio_venta << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Fecha de Vencimiento: " << fecha_vencimiento << endl;

}



void Product::set_IdProducto(int idProducto_nuevo) {
    idProducto = idProducto_nuevo;
}

void Product::set_nombre_producto(string nuevo_nombre) {
    nombre_producto = nuevo_nombre;
}

void Product::set_cantidad(int cantidad_vendida) {
    cantidad = cantidad_vendida;
}

void Product::set_precio_venta(double nuevo_precio) {
    precio_venta = nuevo_precio;
}

void Product::set_fecha_vencimiento(chrono::year_month_day nueva_fecha) {
    //se corrige asignacion de fecha
    fecha_vencimiento = nueva_fecha;
}

int Product::get_IdProducto() {
    return idProducto;
}

string Product::get_nombre_producto() {
    return nombre_producto;
}

int Product::get_cantidad() {
    return cantidad;
}

double Product::get_precio_venta() {
    return precio_venta;

}
chrono::year_month_day Product::get_fecha_vencimiento() {
    return fecha_vencimiento;
}