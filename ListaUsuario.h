#pragma once
#include "NodoUsuario.h"
#include "Usuario.h"

class ListaUsuario {
private:
	NodoUsuario* primero;
	NodoUsuario* actual;
public:
	ListaUsuario();
	bool insertarFinal(Usuario*);
	string toString();
	bool eliminaFinal();
	bool encontrado(string);// retorna true si encuentra la cedula en la Lista y false sino
	Usuario* obtenerUsuario(string); // retorna al Usuario en caso de encontrar la cedula ingresada
	NodoUsuario* getPrimero();
	void setPrimeroNull();
	~ListaUsuario();
};
