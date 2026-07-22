#include "crow/app.h"
#include "route.h"
#include "pedido.h"
#include <iostream>

using namespace std;

int main() {
    crow::SimpleApp app;

    // Registramos los dos endpoints
    registrar_ruta_productos(app);
    registrar_ruta_pedido(app);

    cout << "Servidor backend de C++ corriendo en http://localhost:18080" << endl;
    
    // Inicia el servidor
    app.port(18080).multithreaded().run();
}