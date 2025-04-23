#include "MaterialDigital.h"
#include <iostream>

MaterialDigital::MaterialDigital(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string formato)
    : Material(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, "materialDigital", estado), formato(formato) {
}

string MaterialDigital::getFormato() const {
    return formato;
}

void MaterialDigital::mostrarInformacion() const {
    Material::toString();
    cout << "Formato: " << formato << endl;
}


