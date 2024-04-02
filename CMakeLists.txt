cmake_minimum_required(VERSION 3.27)
project(proyecto)

set(CMAKE_CXX_STANDARD 20)

add_executable(proyecto main.cpp
        src/Modelo/Cliente.cpp
        headers/Modelo/Cliente.h
        headers/Modelo/Factura.h
        src/Modelo/Factura.cpp
        headers/Vista/MenuFactura.h
        src/Vista/MenuFactura.cpp
        utils/sources/PrintUtils.cpp
        utils/headers/PrintUtils.h
        headers/Services/FacturaService.h
        src/Services/FacturaService.cpp
        src/Vista/MenuCliente.cpp
        headers/Vista/MenuCliente.h
        src/Vista/MenuInicio.cpp
        headers/Vista/MenuInicio.h
        src/Services/ClienteService.cpp
        headers/Services/ClienteService.h
)
