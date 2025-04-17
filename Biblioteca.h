#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "ListaMateriales.h"
#include "Material.h"
#include "ListaSolicitud.h"
#include "Solicitud.h"
#include "ListaUsuario.h"
#include "Usuario.h"

class Biblioteca {
private:
	string nombre;
	ListaMateriales* lisMat;
	ListaSolicitud* lisSoli;
	ListaUsuario* lisUsu;
	const int tam = 100;
public:
	Biblioteca(string);
	string getNombre();
	ListaMateriales* getLisMat();
	ListaSolicitud* getLisSoli();
	ListaUsuario* getLisUsu();
};
