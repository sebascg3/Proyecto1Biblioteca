#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "Controlador.h"  

class InterfazUsuario {
private:
    Controlador* controlador; 

public:
    InterfazUsuario();
    ~InterfazUsuario();
    void mostrarMenuPrincipal();
    void menuMateriales();
    void menuUsuarios();
    void menuPrestamos();
    void menuReportes();
};

#endif
