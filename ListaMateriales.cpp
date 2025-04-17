#include "ListaMateriales.h"

ListaMateriales::ListaMateriales() {
    primero = nullptr;
}

ListaMateriales::~ListaMateriales() {
    while (primero != nullptr) {
        NodoMaterial* temp = primero;
        primero = primero->getSiguiente();
        delete temp->getMaterial();
        delete temp;
    }
}

void ListaMateriales::insertarMaterial(Material* m) {
    NodoMaterial* nuevo = new NodoMaterial(m);
    nuevo->setSiguiente(primero);
    primero = nuevo;
}

Material* ListaMateriales::buscarMaterial(string codigo) {
    NodoMaterial* aux = primero;
    while (aux != nullptr) {
        if (aux->getMaterial()->getCodigo() == codigo) {
            return aux->getMaterial();
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

string ListaMateriales::mostrarMaterialesPrestados() {
    stringstream s;
    NodoMaterial* aux = primero;
    int cont = 1;

    while (aux != nullptr) {
        Material* mat = aux->getMaterial();
        if (!mat->isDisponible()) {
            s << "Material Prestado #" << cont++ << endl;
            mat->mostrarInformacion();
            s << "\n";
        }
        aux = aux->getSiguiente();
    }

    if (cont == 1) s << "No hay materiales prestados actualmente.\n";

    return s.str();
}

bool ListaMateriales::estaVacia() {
    return primero == nullptr;
}

Material* ListaMateriales::obtenerEnPosicion(int pos) {
    NodoMaterial* aux = primero;
    int i = 0;

    while (aux != nullptr && i < pos) {
        aux = aux->getSiguiente();
        i++;
    }

    return (aux != nullptr) ? aux->getMaterial() : nullptr;
}

string ListaMateriales::toString() {
    stringstream s;
    NodoMaterial* aux = primero;
    int num = 1;

    while (aux != nullptr) {
        s << "Material #" << num++ << ":\n";
        aux->getMaterial()->mostrarInformacion();
        s << "\n";
        aux = aux->getSiguiente();
    }

    if (num == 1) s << "No hay materiales registrados.\n";

    return s.str();
}
