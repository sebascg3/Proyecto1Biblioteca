#include "ListaMateriales.h"

ListaMateriales::ListaMateriales() {
    primero = nullptr;
}

ListaMateriales::~ListaMateriales() {
    while (primero != nullptr) {
        Nodo* temp = primero;
        primero = primero->getSig();
        delete temp->getInfo();
        delete temp;
    }
}

Material* ListaMateriales::buscarMaterial(string codigo) {
    actual = primero;

    while (actual != nullptr) {
        Material* mat = dynamic_cast<Material*>(actual->getInfo());
        if (mat != nullptr && mat->getCodigo() == codigo) {
            return mat;
        }
        actual = actual->getSig();
    }
    return nullptr;
}

string ListaMateriales::mostrarMaterialesPrestados() {
    stringstream s;
   actual = primero;
    int cont = 1;

    while (actual != nullptr) {
        Material* mat = dynamic_cast<Material*>(actual->getInfo());
        if (!mat->isDisponible()) {
            s << "Material Prestado #" << cont++ << endl;
            mat->toString();
            s << "\n";
        }
        actual = actual->getSig();
    }

    if (cont == 1) s << "No hay materiales prestados actualmente.\n";

    return s.str();
}

Material* ListaMateriales::obtenerEnPosicion(int pos) {
    actual = primero;
    int i = 0;

    while (actual != nullptr && i < pos) {
        actual = actual->getSig();
        i++;
    }

    Material* mat = dynamic_cast<Material*>(actual->getInfo());
    return (mat != nullptr) ? mat : nullptr;
}

Nodo* ListaMateriales::getPrimero() {
    return primero;
}

void ListaMateriales::setPrimeroNull()
{
    primero = NULL;
}
