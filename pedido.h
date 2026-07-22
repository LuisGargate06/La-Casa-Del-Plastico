#ifndef __PEDIDO_H__
#define __PEDIDO_H__

#include "crow/app.h"
#include <iostream>
#include <string>

using namespace std;

inline void registrar_ruta_pedido(crow::SimpleApp& app) {
    // Escucha peticiones POST en /api/pedido
    CROW_ROUTE(app, "/api/pedido").methods(crow::HTTPMethod::POST)
    ([](const crow::request& req) {
        // Carga el JSON enviado desde el frontend
        auto pedido = crow::json::load(req.body);

        if (!pedido) {
            crow::response res(400, "JSON invalido");
            res.add_header("Access-Control-Allow-Origin", "*");
            return res;
        }

        cout << "\n==========================================" << endl;
        cout << "   ¡NUEVA VENTA RECIBIDA!        " << endl;
        cout << "==========================================" << endl;

        double total_general = 0.0;
        for (const auto& item : pedido) {
            string nombre = item["nombre"].s();
            int cantidad = item["cantidad"].i();
            double precio = item["precio"].d();
            double subtotal = precio * cantidad;
            total_general += subtotal;

            cout << "- " << nombre << " | Cantidad: " << cantidad 
                 << " | Subtotal: S/. " << subtotal << endl;
        }

        cout << "------------------------------------------" << endl;
        cout << "TOTAL VENDIDO: S/. " << total_general << endl;
        cout << "==========================================\n" << endl;

        // Respuesta de confirmación al navegador
        crow::json::wvalue res_json;
        res_json["status"] = "ok";
        res_json["mensaje"] = "Venta registrada exitosamente";
        
        crow::response res(res_json);
        res.add_header("Access-Control-Allow-Origin", "*");
        return res;
    });
}

#endif