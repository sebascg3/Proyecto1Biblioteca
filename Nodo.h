#pragma once

#include "ObjetoBase.h"

class Nodo {
private:
	ObjetoBase* info;
	Nodo* sig;
public:
	Nodo(ObjetoBase*, Nodo*);
	~Nodo();
	void setInfo(ObjetoBase*);
	ObjetoBase* getInfo();
	void setSig(Nodo*);
	Nodo* getSig();
	string toString();
};
