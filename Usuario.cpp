#include "Usuario.h"

Usuario::Usuario(string nom, string ced, bool est) {
    nombre = nom;
    cedula = ced;
    estado = est;
}

Usuario::Usuario(Usuario* u) {
    nombre = u->nombre;
    cedula = u->cedula;
    estado = u->estado;
}

Usuario::Usuario(string nom, string ced) : nombre(nom), cedula(ced), estado(true) {
}


string Usuario::getNombre() {
    return nombre;
}

string Usuario::getCedula() {
    return cedula;
}

bool Usuario::getEstado() {
    return estado;
}

void Usuario::setNombre(string n) {
    nombre = n;
}

string Usuario::toString() const {
    stringstream s;
    s << "Cedula: " << cedula << ", Nombre: " << nombre << endl;
    s << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
    return s.str();
}
