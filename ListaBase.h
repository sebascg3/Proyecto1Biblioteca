#pragma once

#include <iostream>
#include <sstream>
using namespace std;

#include "Nodo.h"

class ListaBase {
protected:
	Nodo* primero;
	Nodo* actual;
public:
	ListaBase();
	virtual ~ListaBase();
	virtual void insertarFinal(ObjetoBase*);
	virtual string toString();
	virtual bool eliminaFinal();
	virtual bool listaVacia();
	virtual void elUltimo();
	virtual int cuentaNodos();
};
