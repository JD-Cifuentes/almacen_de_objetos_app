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
            int IdDelUltimoProducto = ProductService::Productos.back().getIdProducto();
            for(Product& p : ProductService::Productos){
                if(p.getIdProducto() != CodProducto){
                    if(IdDelUltimoProducto == p.getIdProducto()) {
                        cout << "No se encontro el producto.\n"<<endl;
                    }
                    continue;
                }else{
                    if(p.getCantidad() < 1 || p.getFechaVencimiento() <= nuevaFactura.getFechaFactura()){
                        cout << "Lo sentimos, no hay cantidad suficiente del producto \n"
                              "o se ha cumplido su fecha de vencimiento.\n" << endl;
                    } else{
                        int cantidadAVender;
                        PrintUtils::printDosColumnas("Poducto:", p.getNombreProducto());
                        PrintUtils::printDosColumnas("Cantidad disponible:", p.getCantidad());
                        cout << "Cuantas unidades desea comprar?" << endl;
                        cin >> cantidadAVender;
                        if(p.descontarCantidadVendida(cantidadAVender) && cantidadAVender > 0) {
                            Product productoAAgregar(p.getIdProducto(),
                                                     p.getNombreProducto(),
                                                     cantidadAVender,
                                                     p.getPrecioVenta(),
                                                     p.getFechaVencimiento());

                            nuevaFactura.agregarProductoVendido(productoAAgregar);
                            double nuevoMonto = productoAAgregar.getPrecioVenta() *
                                                productoAAgregar.getCantidad() + nuevaFactura.getTotalFactura();
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
    try{
         if(ClienteService::vecClientes.empty() || ProductService::Productos.empty()){
             cout << "No hay clientes o productos creados\n";
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
                     cout << "Se cierra la factura con referencia ID: "<< nuevaFactura.getIdFactura() << endl;
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
