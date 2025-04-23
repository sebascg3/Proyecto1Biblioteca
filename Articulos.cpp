#include "Articulos.h"
#include <iostream>  

Articulos::Articulos(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string formato)
    : Material(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, "articulo", estado), formato(formato) {
}

string Articulos::getFormato() const {
    return formato;
}

void Articulos::mostrarInformacion() const {
    Material::toString();
    cout << "Formato: " << formato << endl;
}