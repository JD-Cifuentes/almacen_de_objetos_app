#include "../../headers/Services/ProductService.h"

vector<Product> ProductService::Productos;

void ProductService::crearProducto() {
    //system("cls");

    int idProducto, day, month, year, cantidad;
    double precioVenta;
    string nombreProducto;
    chrono::year_month_day fechaVencimiento;

    do {
        try {
            bool bandera = false;
            cout << "Ingrese Id del Producto: " << endl;
            cin >> idProducto;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un numero entero");
            }
            for (Product Producto: Productos) {
                if (Producto.getIdProducto() == idProducto) {
                    cout << "Codigo de Producto ya Existe" << endl;
                    bandera = true;
                    break;
                }
            }
            if (!bandera) {
                break;
            }
        }catch (runtime_error &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    }while(true);

    do {
        try {
            cout << "Ingrese el Nombre del Producto: " << endl;
            cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
            getline(cin, nombreProducto);
            if (nombreProducto.empty()) {
                throw invalid_argument("Error: Nombre del Producto no puede estar vacio");
            }
            break;
        } catch (runtime_error &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    } while (true);

    do{
        try{
            cout << "Ingrese las cantidades del producto: " << endl;
            cin >> cantidad;
            if (cin.fail() || cantidad <= 0) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese una Cantidad Valida");
            }
            break;
        }catch (runtime_error &ex) {
            cout << ex.what() << endl;
        }catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    }while (true);

    do {
        try {
            cout << "Ingrese el precio de venta del producto: " << endl;
            cin >> precioVenta;
            if (cin.fail() || precioVenta <= 0) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un Precio Valido");
            }
            break;
        }catch (runtime_error &ex) {
            cout << ex.what() << endl;
        }catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    }while (true);

    do {
        try {
            cout << "Ingrese la fecha de vencimiento del producto (Dia): " << endl;
            cin >> day;
            if (cin.fail() || day <= 0 || day > 31) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un Dia Valido");
            }
            break;
        }catch(runtime_error &ex) {
            cout << ex.what() << endl;
        }catch (...) {
            cout << "Error: Entrada Invalida" << endl;
        }
    }while (true);

    do{
        try{
            cout << "Ingrese la fecha de vencimiento del producto (Mes): " << endl;
            cin >> month;
            if (cin.fail() || month <= 0 || month > 12) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un Mes Valido");
            }
            break;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
            cin.clear();
            cin.ignore();
        } catch (...) {
            cout << "Error: Ocurrió un error inesperado" << endl;
            cin.clear();
            cin.ignore();
        }
    }while (true);

    do {
        try{
            cout << "Ingrese la fecha de vencimiento del producto (Anio): " << endl;
            cin >> year;
            if (cin.fail() || year < 2023) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un Anio Valido");
            }
            break;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
            cin.clear();
            cin.ignore();
        } catch (...) {
            cout << "Error: Ocurrió un error inesperado" << endl;
            cin.clear();
            cin.ignore();
        }
    }while (true);

    fechaVencimiento = chrono::year_month_day(chrono::year(year),
                                              chrono::month(month),
                                              chrono::day(day));
    Productos.push_back(Product(idProducto, nombreProducto, cantidad, precioVenta, fechaVencimiento));
    cout << "Producto ha sido Registrado" << endl;
}


void ProductService::buscarProducto() {
    do{
        try {
            int buscar_producto;
            cout << "Ingrese el codigo del Producto: " << endl;
            cin >> buscar_producto;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un Numero Entero");
            }
            bool bandera = false;
            for (Product Producto: Productos) {
                if (Producto.getIdProducto() == buscar_producto) {
                    Producto.showProduct();
                    bandera = true;
                    break;
                }
            }
            if (!bandera) {
                cout << "No existe producto con el codigo: " << buscar_producto << endl;
                mostrarProductos();
            }
            break;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Ocurrió un error inesperado" << endl;
        }
    } while (true);
}

void ProductService::actualizarProducto(){
    int idProducto, day, month, year, cantidad;
    double precioVenta;
    string nombreProducto;
    bool bandera = false;
    chrono::year_month_day fechaVencimiento;
    do {
        try {
            cout << "Ingrese Id del Producto a ACTUALIZAR: " << endl;
            cin >> idProducto;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un numero entero");
            }
            break;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
            cin.clear();
            cin.ignore();
        }
    }while(true);
    for (auto it = Productos.begin(); it != Productos.end(); ++it) {
        if (it->getIdProducto() == idProducto) {
            // Actualizamos el producto si se encuentra
            do{
                try{
                    cout << "Ingrese el Nombre del Producto: " << endl;
                    cout << "Ingrese el Nombre del Producto: " << endl;
                    cin.ignore(); // Ignorar el salto de línea pendiente en el buffer
                    getline(cin, nombreProducto);
                    if (nombreProducto.empty()) {
                        throw invalid_argument("Error: Nombre del Producto no puede estar vacio");
                    }
                    break;
                } catch (runtime_error &ex) {
                    cout << ex.what() << endl;
                } catch (...) {
                    cout << "Error: Entrada Invalida" << endl;
                }
            } while (true);
            do{
                try{
                    cout << "Ingrese las cantidades del producto: " << endl;
                    cin >> cantidad;
                    if (cin.fail() || cantidad <= 0) {
                        cin.clear();
                        cin.ignore();
                        throw invalid_argument("Error: Ingrese una Cantidad Valida");
                    }
                    break;
                }catch (runtime_error &ex) {
                    cout << ex.what() << endl;
                }catch (...) {
                    cout << "Error: Entrada Invalida" << endl;
                }
            }while (true);
            do {
                try {
                    cout << "Ingrese el precio de venta del producto: " << endl;
                    cin >> precioVenta;
                    if (cin.fail() || precioVenta <= 0) {
                        cin.clear();
                        cin.ignore();
                        throw invalid_argument("Error: Ingrese un Precio Valido");
                    }
                    break;
                }catch (runtime_error &ex) {
                    cout << ex.what() << endl;
                }catch (...) {
                    cout << "Error: Entrada Invalida" << endl;
                }
            }while (true);
            do {
                try {
                    cout << "Ingrese la fecha de vencimiento del producto (Dia): " << endl;
                    cin >> day;
                    if (cin.fail() || day <= 0 || day > 31) {
                        cin.clear();
                        cin.ignore();
                        throw invalid_argument("Error: Ingrese un Dia Valido");
                    }
                    break;
                }catch(runtime_error &ex) {
                    cout << ex.what() << endl;
                }catch (...) {
                    cout << "Error: Entrada Invalida" << endl;
                }
            }while (true);

            do{
                try{
                    cout << "Ingrese la fecha de vencimiento del producto (Mes): " << endl;
                    cin >> month;
                    if (cin.fail() || month <= 0 || month > 12) {
                        cin.clear();
                        cin.ignore();
                        throw invalid_argument("Error: Ingrese un Mes Valido");
                    }
                    break;
                } catch (invalid_argument &ex) {
                    cout << ex.what() << endl;
                    cin.clear();
                    cin.ignore();
                } catch (...) {
                    cout << "Error: Ocurrió un error inesperado" << endl;
                    cin.clear();
                    cin.ignore();
                }
            }while (true);

            do {
                try{
                    cout << "Ingrese la fecha de vencimiento del producto (Anio): " << endl;
                    cin >> year;
                    if (cin.fail() || year < 2023) {
                        cin.clear();
                        cin.ignore();
                        throw invalid_argument("Error: Ingrese un Anio Valido");
                    }
                    break;
                } catch (invalid_argument &ex) {
                    cout << ex.what() << endl;
                    cin.clear();
                    cin.ignore();
                } catch (...) {
                    cout << "Error: Ocurrió un error inesperado" << endl;
                    cin.clear();
                    cin.ignore();
                }
            }while (true);
            fechaVencimiento = chrono::year_month_day(chrono::year(year),
                                                      chrono::month(month),
                                                      chrono::day(day));

            //Producto.setIdProducto(idProducto);
            it->setNombreProducto(nombreProducto);
            it->setCantidad(cantidad);
            it->setPrecioVenta(precioVenta);
            it->setFechaVencimiento(fechaVencimiento);

            cout << "Producto Actualizado Correctamente" << endl;
            bandera = true;
            break;
        }
    }if(!bandera){
        cout << "No se encontro ningun Producto con el ID: " << endl;
    }
}

void ProductService::eliminarProducto() {
    int idProducto;
    bool bandera = false;
    do{
        try{
            cout << "Ingrese Id del Producto a ELIMINAR: " << endl;
            cin >> idProducto;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Error: Ingrese un numero entero");
            }break;
        } catch (invalid_argument &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "Error: Entrada Invalida" << endl;
            cin.clear();
            cin.ignore();
        }
    }while(true);

    for (auto it = Productos.begin(); it != Productos.end(); ++it) {
        if (it->getIdProducto() == idProducto) {
            // Eliminar el producto si se encuentra
            Productos.erase(it);
            cout << "Producto Eliminado Correctamente" << endl;
            bandera = true;
            break;
        }
    }if(!bandera){
        cout << "No se encontro ningun Producto con el ID: " << endl;
    }


    /*
    for (Product Producto: Productos) {
        if (Producto.getIdProducto() == idProduct) {
            cout << "Producto Eliminado Correctamente" << endl;
            bandera = true;
            break;
        }
    }if(!bandera){
        cout << "No se encontro ningun Producto con el ID: " << endl;
    }
    */
}

void ProductService::mostrarProductos() {
    for (Product Producto: Productos) {
        Producto.showProduct();
    }
}