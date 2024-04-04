//
// Created by juan- on 28/03/2024.
//

#include "../../headers/Services/FacturaService.h"

vector<Factura> FacturaService::Facturas;

void agregarProductos(Factura& nuevaFactura){
    while(true){
        try {
            string entradaCodProducto;
            cout << "Ingrese a continuacion el codigo del producto que desea agregar a la factura,"<< endl;
            cout << "o ingrese s/S para terminar de agregar productos y finalizar la facturacion." << endl;
            cin >> entradaCodProducto;
            if(entradaCodProducto == "s" || entradaCodProducto == "S"){
                break;
            }
            int CodProducto = stoi(entradaCodProducto);
            for(Product& p : ProductService::Productos){
                if(p.get_IdProducto() != CodProducto){
                    continue;
                }else{
                    if(p.get_cantidad()<1 || p.get_fecha_vencimiento() <= nuevaFactura.getFechaFactura()){
                        cout << "Lo sentimos, no hay cantidad suficiente del producto \n"
                              "o se ha cumplido su fecha de vencimiento.\n" << endl;
                    } else{
                        int cantidadAVender;
                        PrintUtils::printDosColumnas("Poducto:", p.get_nombre_producto());
                        PrintUtils::printDosColumnas("Cantidad disponible:", p.get_cantidad());
                        cout << "Cuantas unidades desea comprar?" << endl;
                        cin >> cantidadAVender;
                        if(p.descontarCantidadVendida(cantidadAVender) && cantidadAVender > 0) {
                            Product productoAAgregar(p.get_IdProducto(),
                                                     p.get_nombre_producto(),
                                                     cantidadAVender,
                                                     p.get_precio_venta(),
                                                     p.get_fecha_vencimiento());

                            nuevaFactura.agregarProductoVendido(productoAAgregar);
                            double nuevoMonto = productoAAgregar.get_precio_venta() *
                                    productoAAgregar.get_cantidad() + nuevaFactura.getTotalFactura();
                            nuevaFactura.setTotalFactura(nuevoMonto);
                            cout << "Producto facturado exitosamente" << endl;
                        }
                    }
                    break;
                }
            }
        }catch (...){
            cout << "El dato ingresado es erróneo, intenta nuevamente.\n" << endl;
        }
    }
}

void FacturaService::crearYGuardarFactura() {
//!!!!!!!cliente y producto creado para pruebas!!!!!!!!
Cliente clientePrueba(111,
                      "Juan D",
                      chrono::year_month_day(chrono::year(1995),
                                                            chrono::month(4),
                                                            chrono::day(2)));
ClienteService::vecClientes.push_back(clientePrueba);

Product product1(1,
                 "coke",
                 20,
                 1000.0,
                 chrono::year_month_day(chrono::year(2024),
                                                            chrono::month(4),
                                                            chrono::day(7)));
ProductService::Productos.push_back(product1);
//!!!!!!!!!!!!!!!!!!!!!!!!
    try{
         if(ClienteService::vecClientes.empty() || ProductService::Productos.empty()){
             cout << "No hay clilentes o productos creados\n";
             return;
         }else{
             int idClienteFactura;
             cout << "Ingrese la identificacion del cliente: ";
             cin >> idClienteFactura;
             for(Cliente c : ClienteService::vecClientes){
                 if(c.getidCliente() != idClienteFactura){
                    continue;
                 }else{
                     Factura nuevaFactura(idClienteFactura);
                     agregarProductos(nuevaFactura);
                     FacturaService::Facturas.push_back(nuevaFactura);
                     cout << "Se cierra la factura" << endl;
                     return;
                 }
             }
             cout << "El cliente no se encuentra en la base de datos." << endl;
         }

    }catch(...) {
        cout << "Has ingresado un dato errado, intenta nuevamente " << endl;
    }
}

void FacturaService::consultarFactura() {
    if (FacturaService::Facturas.empty()){
        cout << "No hay facturas creadas\n";
    }else{
        try{
            int idFactura;
            cout << "\nIngrese el código de la factura: ";
            cin >> idFactura;
            for (Factura &f: Facturas) {
                if(f.getIdFactura() == idFactura){
                    f.descripcionFactura();
                    return;
                }
            }
            cout << "No se encontro la factura solicitada\n";
        }catch(...){
            cout << "Recuerde que sólo puede ingresar números" << endl;
        }

    }
}

void FacturaService::consultarTodasLasFactura() {
    if (FacturaService::Facturas.empty()){
        cout << "No hay facturas creadas\n";
    }else{
        for (Factura &f: Facturas) {
            f.descripcionFactura();
        }
    }
}

void FacturaService::eliminarFactura() {
    /********************/
    if (FacturaService::Facturas.empty()){
        cout << "No hay facturas creadas\n";
    }else{
        try {
            int idFactura;
            cout << "\nIngrese el codigo de la factura: ";
            cin >> idFactura;
            for (int i = 0; i < Facturas.size(); ++i) {
                if(Facturas[i].getIdFactura() == idFactura){
                    Facturas.erase(Facturas.begin() + i);
                    cout << "Factura eliminada con exito\n";
                    break;
                }
            }
            cout << "No se encontro la factura solicitada\n";
        }catch(...){
            cout << "Recuerde que sólo puede ingresar números" << endl;
        }
    }
}
