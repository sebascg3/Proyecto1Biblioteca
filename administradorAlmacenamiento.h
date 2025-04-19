#include "ListaMateriales.h"
#include "ListaUsuario.h"
#include "Libros.h"
#include "Articulos.h"
#include "MaterialDigital.h"
#include "Revistas.h"
#include "Videos.h"
#include "fstream"
#include "sstream"

#pragma once
class administradorAlmacenamiento
{
public:
	administradorAlmacenamiento();
	void saveListaMateriales(ListaMateriales* lis, ofstream& file);
	void readListaMateriales(ListaMateriales* lis, ifstream& file);

	void saveListaUsuarios(ListaUsuario* lis, ofstream& file);
	void readListaUsuarios(ListaUsuario* lis, ifstream& file);
};

