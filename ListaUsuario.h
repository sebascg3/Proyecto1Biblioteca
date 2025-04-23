#pragma once
#include "Nodo.h"
#include "Usuario.h"
#include "ListaBase.h"

class ListaUsuario : public ListaBase {
public:
	ListaUsuario();
	bool encontrado(string);// retorna true si encuentra la cedula en la Lista y false sino
	Usuario* obtenerUsuario(string); // retorna al Usuario en caso de encontrar la cedula ingresada
	Nodo* getPrimero();
	void setPrimeroNull();
	~ListaUsuario();
};
