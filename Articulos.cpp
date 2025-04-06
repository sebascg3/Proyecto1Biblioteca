#include "Articulos.h"
#include <iostream>

Articulos::Articulos(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string formato)
    : Material(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado), formato(formato) {
}

string Articulos::getFormato() const {
    return formato;
}

void Articulos::mostrarInformacion() const {
    Material::mostrarInformacion();
    cout << "Formato: " << formato << endl;
}


