//
// Created by juan- on 28/03/2024.
//

#include "../../headers/Services/FacturaService.h"
vector<Factura> FacturaService::Facturas;

void FacturaService::crearYGuardarFactura() {
    int idClienteFactura;
    cout << "\nIngrese la identificación del cliente: ";
    cin >> idClienteFactura;
    //en espera de la creación de la clase cliente para validar la existencia de este
    /*
     * if(ClienteVector.empty()){
     *  cout << "No hay facturas creadas\n";
     *  return;
     * }else{
     *  for(Cliente c : Clientes::clientes){
     *   if(c.getIdCliente != idClienteFactura){
     *      continue;
     *   }else{
     *      Factura nuevaFactura(idClienteFactura);
     *      //CREAR METODO PARA AGREGAR PRODUCTOS
     *      break;
     *   }
     *
     *  }
     *
     * }
     */

}

void agregarProducto(){
//Validar fecha de vencimineto y cantidades
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
        /*for (int i = 0; i < Facturas.size(); ++i) {
            if(Facturas[i].getIdFactura() == idFactura){
                Facturas[i].descripcionFactura();
                return;
            }
        }*/
        cout << "No se encontro la factura solicitada\n";

    }
}

void FacturaService::consultarTodasLasFactura() {
    if (FacturaService::Facturas.empty()){
        cout << "No hay facturas creadas\n";
    }else{
        for (Factura &f: Facturas) {

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
