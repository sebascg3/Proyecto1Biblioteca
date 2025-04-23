#include "ListaBase.h"

ListaBase::ListaBase() {
	primero = nullptr;
	actual = nullptr;
}

ListaBase::~ListaBase() {
	while (!listaVacia()) {
		eliminaFinal();
	}
}

void ListaBase::insertarFinal(ObjetoBase* Obj) {
	actual = primero;
	if (primero == nullptr) {
		primero = new Nodo(Obj, nullptr); //Si está vacío
	} else {
		while (actual->getSig() != nullptr) { //Va hasta el final
			actual = actual->getSig();
		}
		actual->setSig(new Nodo(Obj, nullptr));
	}
}

string ListaBase::toString() {
	stringstream s;

	actual = primero;
	while (actual != nullptr) {
		s << actual->toString() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

bool ListaBase::eliminaFinal() {
	
	actual = primero;	
	if (primero == nullptr) { //Vacío
		return false;
	} else {
		
		if (primero->getSig() == nullptr) { //Solo un Elemento
			delete primero;
			primero = nullptr;
		} else {

			while (actual->getSig()->getSig() != nullptr) {
				actual = actual->getSig();
			}
			delete  actual->getSig();
			actual->setSig(nullptr);
		}
		return true;
	}
}

bool ListaBase::listaVacia() {
	if (primero == nullptr) return true;
	else return false;
}

void ListaBase::elUltimo() {
	actual = primero;
	if (primero != nullptr) {
		while (actual->getSig() != nullptr) {
			actual = actual->getSig();
		}
	}
}

int ListaBase::cuentaNodos() {
	actual = primero;
	int can = 0;

	while (actual != nullptr) {
		can++;
		actual = actual->getSig();
	}
	return can;
}
