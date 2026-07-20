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
    void leer_catalogo(ifstream &is);
};

//definimos a las funciones
void Producto::leer_catalogo(){
    ifstream archivo("catalogo.txt");
    
    if(!archivo.is_open()){
        std::cerr << "Error no se pudo leer el archivo."<<std::endl;
        return 1; //Termina el programa
    }

    T1 cantidad_total;
    archivo >> cantidad_total;
    archivo.ignore();



}

#endif