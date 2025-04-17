#include "Material.h"  

Material::Material(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado)
    : codigo(numeroClasificacion), titulo(titulo), disponible(estado) {
}

Material::Material(string codigo, string titulo):
    codigo(codigo), titulo(titulo), disponible(true){ }

string Material::getCodigo() {
    return codigo;
}

string Material::getTitulo() {
    return titulo;
}

bool Material::isDisponible() {
    return disponible;
}

void Material::setTitulo(string tit) {
    titulo = tit;
}

void Material::setDisponible(bool disp) {
    disponible = disp;
}

void Material::mostrarInformacion() const {
    cout << "Código: " << codigo << endl;
    cout << "Título: " << titulo << endl;
    cout << "Disponible: " << (disponible ? "Sí" : "No") << endl;
}