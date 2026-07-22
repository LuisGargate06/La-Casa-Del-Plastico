#ifndef __PRODUCTO_H__
#define __PRODUCTO_H__

//incluimos las librerias
#include <iostream>
#include <cstddef>
#include "types.h"
#include <fstream>
#include <vector>

//Struct para los productos
struct Producto{
    T1 codigo;
    T3 nombre;
    T2 precio;
    T3 imagen;
};

inline std::vector<Producto> leer_catalogo() {
    std::ifstream archivo("catalogo.txt");
    std::vector<Producto> lista_productos;
    
    if (!archivo.is_open()) {
        std::cerr << "Error: no se pudo leer el archivo catalogo.txt." << std::endl;
        return lista_productos;
    }

    T1 cantidad_total = 0;
    archivo >> cantidad_total;
    
    for (size_t i = 0; i < cantidad_total; i++) {
        Producto p;
        archivo >> p.codigo >> p.nombre >> p.precio >> p.imagen;
        lista_productos.push_back(p);
    }

    archivo.close();
    return lista_productos;
}

#endif