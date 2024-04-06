//
// Created by juan- on 26/03/2024.
//

#include "../../headers/Modelo/Factura.h"


int Factura::contadorIdFactura = 0;

Factura::Factura(int idCliente) {
    auto actual = chrono::system_clock::now();
    Factura::idCliente = idCliente;
    Factura::idFactura = Factura::contadorIdFactura;
    Factura::fechaFactura = chrono::year_month_day(chrono::floor<chrono::days>(actual));
    Factura::contadorIdFactura++;
}
void Factura::agregarProductoVendido(const Product& nuevoProducto) {
    productosFacturados.push_back(nuevoProducto);
}

void Factura::descripcionFactura() {
    PrintUtils::printDosColumnas("Factura ID", idFactura);
    PrintUtils::printDosColumnas("Cliente ID", idCliente);
    PrintUtils::printDosColumnas("Fecha de compra", fechaFactura);
    PrintUtils::printDosColumnas("Total de la compra", totalFactura);
    PrintUtils::printFilaProducto("ID_Producto", "Nombre",
                                  "Cantidad Vendida", "Precio");
    for(Product productoFac : productosFacturados){
        PrintUtils::printFilaProducto(productoFac.getIdProducto(),
                                      productoFac.getNombreProducto(),
                                      productoFac.getCantidad(),
                                      productoFac.getPrecioVenta());
    }
    cout << "\n" << endl;
}

int Factura::getIdFactura() const {
    return idFactura;
}

chrono::year_month_day Factura::getFechaFactura() {
    return fechaFactura;
}

void Factura::setTotalFactura(double nuevoMonto) {
    totalFactura = nuevoMonto;
}

double Factura::getTotalFactura() {
    return totalFactura;
}




