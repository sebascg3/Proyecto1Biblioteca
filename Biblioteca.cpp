#include "Biblioteca.h"

Biblioteca::Biblioteca(string n) {
	nombre = n;
	lisMat = new ListaMateriales();
	lisSoli = new ListaSolicitud();
	lisUsu = new ListaUsuario();
}

string Biblioteca::getNombre() {
	return nombre;
}

ListaMateriales* Biblioteca::getLisMat() {
	return lisMat;
}

ListaSolicitud* Biblioteca::getLisSoli() {
	return lisSoli;
}

ListaUsuario* Biblioteca::getLisUsu() {
	return lisUsu;
}
