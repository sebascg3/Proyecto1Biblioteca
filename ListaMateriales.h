#ifndef LISTAMATERIALES_H
#define LISTAMATERIALES_H

#include <string>
#include <sstream>

#include "Material.h"
#include "Nodo.h"
#include "ListaBase.h"


class ListaMateriales : public ListaBase {
public:
    ListaMateriales();
    ~ListaMateriales();

    Material* buscarMaterial(string codigo); 
    string mostrarMaterialesPrestados();

    Material* obtenerEnPosicion(int pos);

    Nodo* getPrimero();
    void setPrimeroNull();
};

#endif
