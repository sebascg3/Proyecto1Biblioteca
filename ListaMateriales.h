#ifndef LISTAMATERIALES_H
#define LISTAMATERIALES_H

#include "NodoMaterial.h"
#include <string>
#include <sstream>

class ListaMateriales {
private:
    NodoMaterial* primero;

public:
    ListaMateriales();
    ~ListaMateriales();

    void insertarMaterial(Material* m);
    Material* buscarMaterial(string codigo); 
    string mostrarMaterialesPrestados();

    bool estaVacia();
    Material* obtenerEnPosicion(int pos);
    string toString();

    NodoMaterial* getPrimero();
    void setPrimeroNull();
};

#endif
