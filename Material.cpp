#include "Material.h"  

Material::Material(string numeroClasificacion, int numeroCatalogo_, string titulo, string autor_, string palabraClave_, string tipo_, bool estado)
    : codigo(numeroClasificacion), titulo(titulo), disponible(estado), numeroCatalogo(numeroCatalogo_), autor(autor_), palabraClave(palabraClave_), tipo(tipo_) {
}

Material::Material(string codigo, string titulo)
    : codigo(codigo), titulo(titulo), disponible(true), numeroCatalogo(0), autor(""), palabraClave(""), tipo("") {
}

void Material::setCodigo(string cod) {  
   codigo = cod;  
}

void Material::setNumeroCatalogo(int numCat){
    numeroCatalogo = numCat;
}
void Material::setAutor(string aut) {
	autor = aut;
}
void Material::setPalabraClave(string palabra) {
	palabraClave = palabra;
}
void Material::setTipo(string t) {
	tipo = t;
}
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

void Material::setTitulo(string tit){
    titulo = tit;
}

void Material::setDisponible(bool disp){
    disponible = disp;
}

bool Material::esDisponible() const {
    return disponible;
}


string Material::toString() const {
    stringstream s;

    s << "Codigo: " << codigo << endl;
    s << "Titulo: " << titulo << endl;
    s << "Disponible: " << (disponible ? "Si" : "No") << endl;
    s << "Numero de catalogo: " << numeroCatalogo << endl;
    s << "Autor: " << autor << endl;
    s << "Palabra clave: " << palabraClave << endl;
    s << "Tipo: " << tipo << endl;

    return s.str();
}