#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "ListaSolicitud.h"
#include "ListaUsuario.h"
#include "ListaMateriales.h"
#include "administradorAlmacenamiento.h"

class Controlador {
private:
    ListaSolicitud* solicitudes;
    ListaUsuario* usuarios;
    ListaMateriales* materiales;
    administradorAlmacenamiento* adm;

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

    void saveMateriales(ListaMateriales* lis, ofstream& file);
    void saveUsuarios(ListaUsuario* lis, ofstream& file);

    void readMateriales(ListaMateriales* lis, ifstream& file);
    void readUsuarios(ListaUsuario* lis, ifstream& file);


};

#endif
