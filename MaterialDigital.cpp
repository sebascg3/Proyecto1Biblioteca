#include "MaterialDigital.h"
#include <iostream>

MaterialDigital::MaterialDigital(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string formato)
    : Material(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado), formato(formato) {
}

string MaterialDigital::getFormato() const {
    return formato;
}

void MaterialDigital::mostrarInformacion() const {
    Material::mostrarInformacion();
    cout << "Formato: " << formato << endl;
}


