#ifndef __ROUTE_H__
#define __ROUTE_H__

#include "crow/app.h"
#include "producto.h" 
#include <vector>
#include <cstddef>

using namespace std;

inline void registrar_ruta_productos(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/api/productos")
    ([]() {
        vector<Producto> catalogo = leer_catalogo();
        crow::json::wvalue json_respuesta;

        for (size_t i = 0; i < catalogo.size(); ++i) {
            json_respuesta[i]["id"]     = catalogo[i].codigo;
            json_respuesta[i]["nombre"] = catalogo[i].nombre;
            json_respuesta[i]["precio"] = catalogo[i].precio;
            json_respuesta[i]["img"]    = catalogo[i].imagen;
        }

        crow::response res(json_respuesta);
        res.add_header("Access-Control-Allow-Origin", "*");
        return res;
    });
}

#endif