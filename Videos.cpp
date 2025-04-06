#include "Videos.h"
#include <iostream>

Videos::Videos(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string duracion, string formato, string tema)
    : Material(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado), duracion(duracion), formato(formato), tema(tema) {
}

string Videos::getDuracion() const {
    return duracion;
}

string Videos::getFormato() const {
    return formato;
}

string Videos::getTema() const {
    return tema;
}

void Videos::mostrarInformacion() const {
    Material::mostrarInformacion();
    cout << "Duracion: " << duracion << endl;
    cout << "Formato: " << formato << endl;
    cout << "Tema: " << tema << endl;
}

