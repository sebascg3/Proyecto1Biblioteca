#include "Controlador.h"  
#include "Biblioteca.h"

#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

class InterfazUsuario {
private:
    Controlador* controlador; 
    Biblioteca* biblio;
public:
    InterfazUsuario();
    ~InterfazUsuario();
   void mostrarMenuPrincipal();
    void menuMateriales();
    void menuUsuarios();
    //void agregarUsuario();
    void menuPrestamos();
    void menuReportes();


};

#endif
