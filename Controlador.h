#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "ListaSolicitud.h"
#include "ListaUsuario.h"
#include "ListaMateriales.h"

class Controlador {
private:
    ListaSolicitud* solicitudes;
    ListaUsuario* usuarios;
    ListaMateriales* materiales;

public:
    Controlador();
    ~Controlador();

    void incluirMaterial();
    void modificarMaterial();
    void incluirUsuario();
    void modificarUsuario();
    void registrarPrestamo();
    void registrarDevolucion();
    void reporteInventario();
    void reporteUsuarios();
    void reporteMaterialesPrestados();
    void reportePrestamosPorUsuario();
};

#endif
