#include "Material.h"

Material::Material(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado)
    : numeroClasificacion(numeroClasificacion), numeroCatalogo(numeroCatalogo), titulo(titulo), autor(autor), palabraClave(palabraClave), tipo(tipo), estado(estado) {
}

string Material::getNumeroClasificacion() const {
    return numeroClasificacion;
}

int Material::getNumeroCatalogo() const {
    return numeroCatalogo;
}

string Material::getTitulo() const {
    return titulo;
}

string Material::getAutor() const {
    return autor;
}

string Material::getPalabraClave() const {
    return palabraClave;
}

string Material::getTipo() const {
    return tipo;
}

bool Material::getEstado() const {
    return estado;
}

void Material::setEstado(bool nuevoEstado) {
    estado = nuevoEstado;
}

void Material::mostrarInformacion() const {
    cout << "Numero de Clasificacion: " << numeroClasificacion << endl;
    cout << "Numero de Catalogo: " << numeroCatalogo << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Palabra Clave: " << palabraClave << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Estado: " << (estado ? "Disponible" : "No Disponible") << endl;
}
