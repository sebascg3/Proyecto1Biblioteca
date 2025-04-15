#pragma once
#include "Usuario.h"

class NodoUsuario {
private:
	Usuario* info;
	NodoUsuario* sig;
public:
	NodoUsuario(Usuario*, NodoUsuario*);
	~NodoUsuario();
	void setInfo(Usuario*);
	void setSig(NodoUsuario*);
	Usuario* getInfo();
	NodoUsuario* getSig();
	string toStringInfo();
};
