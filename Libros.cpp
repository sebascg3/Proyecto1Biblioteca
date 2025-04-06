#include "Libros.h"
#include <iostream>

Libros::Libros(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string ISBN, string editorial, string formato)
    : Material(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado), ISBN(ISBN), editorial(editorial), formato(formato) {
}

string Libros::getISBN() const {
    return ISBN;
}

string Libros::getEditorial() const {
    return editorial;
}

string Libros::getFormato() const {
    return formato;
}

void Libros::mostrarInformacion() const {
    Material::mostrarInformacion();
    cout << "ISBN: " << ISBN << endl;
    cout << "Editorial: " << editorial << endl;
    cout << "Formato: " << formato << endl;
}

