#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H


#include "Controlador.h"  

class InterfazUsuario {
private:
    Controlador* controlador; 

public:
    InterfazUsuario();
    ~InterfazUsuario();

#include "Biblioteca.h"

class InterfazUsuario {
private:
    Biblioteca* biblio;
public:
    InterfazUsuario();

    void mostrarMenuPrincipal();
    void menuMateriales();
    void menuUsuarios();
    //void agregarUsuario();
    void menuPrestamos();
    void menuReportes();
};

#endif
