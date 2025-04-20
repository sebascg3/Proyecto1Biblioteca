#include "Material.h"  

Material::Material(string numeroClasificacion, int numeroCatalogo_, string titulo, string autor_, string palabraClave_, string tipo_, bool estado)
    : codigo(numeroClasificacion), titulo(titulo), disponible(estado) {

    numeroCatalogo = numeroCatalogo_;
    autor = autor_;
    palabraClave = palabraClave_;

}

Material::Material(string codigo, string titulo):
    codigo(codigo), titulo(titulo), disponible(true){ }

string Material::getCodigo() {
    return codigo;
}

string Material::getTitulo() {
    return titulo;
}

string Material::getTipo() {
    return titulo;
}

string Material::getNumeroCatalogo() {
    return titulo;
}

string Material::getAutor() {
    return titulo;
}

string Material::getPalabraClave() {
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
    cout << "Numero de catalogo: " << numeroCatalogo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Palabra clave: " << palabraClave << endl;
    cout << "Tipo: " << tipo << endl;
}