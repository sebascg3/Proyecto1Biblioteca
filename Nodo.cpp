#include "Nodo.h"

Nodo::Nodo(ObjetoBase* i, Nodo* s) {
	info = i;
	sig = s;
}

Nodo::~Nodo() {}

void Nodo::setInfo(ObjetoBase* i) {
	info = i;
}

ObjetoBase* Nodo::getInfo() {
	return info;
}

void Nodo::setSig(Nodo* s) {
	sig = s;
}

Nodo* Nodo::getSig() {
	return sig;
}

string Nodo::toString() {
	return info->toString();
}
