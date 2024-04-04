//
// Created by juan- on 28/03/2024.
//

#include "../../headers/Services/FacturaService.h"

vector<Factura> FacturaService::Facturas;

void agregarProducto(Factura nuevaFactura){
    while(true){
        try {
            string entradaCodProducto;
            cout << "Ingresé a continuación el código del producto que desea agregar a la factura, \n"
                    "o ingrese s/S para terminar de agregar productos y finalizar la facturación." << endl;
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
                              "o se ha cumplido su fecha de vencimiento." << endl;
                    } else{
                        int cantidadAVender;
                        PrintUtils::printDosColumnas("Poducto:", p.get_nombre_producto());
                        PrintUtils::printDosColumnas("Cantidad disponible:", p.get_cantidad());
                        cout << "Cuántas unidades desea comprar?" << endl;
                        cin >> cantidadAVender;
                        if(p.descontarCantidadVendida(cantidadAVender)) {
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
    int idClienteFactura;
    try
    {
        cout << "\nIngrese la identificación del cliente: ";
        cin >> idClienteFactura;
         if(ClienteService::vecClientes.empty()){
             cout << "No hay clilentes creados\n";
             return;
         }else{
             for(Cliente c : ClienteService::vecClientes){
                 if(c.getidCliente() != idClienteFactura){
                    continue;
                 }else{
                     Factura nuevaFactura(idClienteFactura);
                     agregarProducto(nuevaFactura);
                     cout << "Se cierra la factura\n" << endl;
                     return;
                 }
             }
             cout << "El cliente no se encuentra en la base de datos" << endl;
         }

    }catch(...) {
        cout << "Has ingresado un dato errado, intenta nuevamente " << endl;
    }


}



void FacturaService::consultarFactura() {
    int idFactura;
    cout << "\nIngrese el código de la factura: ";
    cin >> idFactura;
    if (FacturaService::Facturas.empty()){
        cout << "No hay facturas creadas\n";
    }else{
        for (Factura &f: Facturas) {
            if(f.getIdFactura() == idFactura){
                f.descripcionFactura();
                return;
            }
        }
        cout << "No se encontro la factura solicitada\n";
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
    int idFactura;
    cout << "\nIngrese el código de la factura: ";
    cin >> idFactura;
    if (FacturaService::Facturas.empty()){
        cout << "No hay facturas creadas\n";
    }else{
        for (Factura &f: Facturas) {
            if(f.getIdFactura() == idFactura){

            }
            cout << "No se encontro la factura solicitada\n";
        }
    }
}
