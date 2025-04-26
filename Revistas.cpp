#include "Revistas.h"
#include <iostream>

Revistas::Revistas(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, int Numero, int Volumen, string Formato)
    : Material(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, "revista", estado), Numero(Numero), Volumen(Volumen), Formato(Formato) {
}

int Revistas::getNumero() const {
    return Numero;
}

int Revistas::getVolumen() const {
    return Volumen;
}

string Revistas::getFormato() const {
    return Formato;
}

void Revistas::mostrarInformacion() const {
    Material::toString();
    cout << "Numero: " << Numero << endl;
    cout << "Volumen: " << Volumen << endl;
    cout << "Formato: " << Formato << endl;
}
