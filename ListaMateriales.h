#include "NodoMaterial.h"

#pragma once
class ListaMateriales {
private:
	NodoMaterial* primero;

public:
    ListaMateriales() : primero(nullptr) {}

    void insertar(Material* m);
    void toString();
    NodoMaterial* buscar(Material* m);
    bool estaVacia();
    Material* obtenerEnPosicion(int pos);
    ~ListaMateriales();
};


