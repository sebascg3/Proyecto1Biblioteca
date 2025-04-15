#include "ListaMateriales.h"

void ListaMateriales::insertar(Material* m) {
    NodoMaterial* nuevo = new NodoMaterial(m);
    nuevo->setSiguiente(primero);
    primero = nuevo;
}

void ListaMateriales::toString()  {
    NodoMaterial* aux = primero;
    while (aux != nullptr) {
        aux->getMaterial()->mostrarInformacion();
        aux = aux->getSiguiente();
    }
}

NodoMaterial* ListaMateriales::buscar(Material* m) {
    NodoMaterial* aux = primero;
    while (aux != nullptr) {
        if (aux->getMaterial() == m) return aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}


bool ListaMateriales::estaVacia()  {
    return primero == nullptr;
}


ListaMateriales::~ListaMateriales() {
    while (primero != nullptr) {
        NodoMaterial* temp = primero;
        primero = primero->getSiguiente();
        delete temp->getMaterial();
        delete temp;
    }
}

Material* ListaMateriales::obtenerEnPosicion(int pos) {
    if (pos < 0) return nullptr;

    NodoMaterial* aux = primero;
    int i = 0;

    while (aux != nullptr && i < pos) {
        aux = aux->getSiguiente();
        i++;
    }

    if (aux == nullptr) return nullptr; // Posición fuera de rango

    return aux->getMaterial();
}