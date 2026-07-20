#ifndef __PRODUCTO_H__
#define __PRODUCTO_H__

//incluimos las librerias
#include <iostream>
#include <cstddef>
#include "types.h"
#include <fstream>

//Struct para los productos
struct Producto{
    T1 codigo;
    T3 nombre;
    T2 precio;
    T3 imagen;

    //nombramos funciones
    void leer_catalogo();
};

//definimos a las funciones
void Producto::leer_catalogo(){

}

#endif