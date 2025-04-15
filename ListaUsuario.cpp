#include "ListaUsuario.h"

ListaUsuario::ListaUsuario() {
	primero = nullptr;
	actual = nullptr;
}

bool ListaUsuario::insertarFinal(Usuario* u) {
	bool tof = false;

	Usuario* UsuPtr = new Usuario(u);
	NodoUsuario* nuevoN = new NodoUsuario(UsuPtr, nullptr);

	actual = primero;
	if (primero == nullptr) {
		primero = nuevoN;
		tof = true;
	}
	else {
		while (actual->getSig() != nullptr) {
			actual = actual->getSig();
		}
		actual->setSig(nuevoN);
		tof = true;
	}
	return tof;
}

string ListaUsuario::toString() {
	stringstream s;
	int numUsu = 1;

	actual = primero;
	if (actual != nullptr) {
		while (actual != nullptr) {
			s << "Usuario #" << numUsu << endl << endl;
			s << actual->toStringInfo() << endl;
			s << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";

			actual = actual->getSig();
			numUsu++;
		}
	}
	else {
		s << "No existen Usuarios registrados actualmente...\n\n";
	}

	return s.str();
}

bool ListaUsuario::eliminaFinal() {
	if (primero == nullptr) {
		return false;
	}

	if (primero->getSig() == nullptr) {
		delete primero;
		primero = nullptr;
		return true;
	}

	actual = primero;
	while (actual->getSig()->getSig() != nullptr) {
		actual = actual->getSig();
	}

	delete actual->getSig();
	actual->setSig(nullptr);
	return true;
}

bool ListaUsuario::encontrado(string ced) {
	actual = primero;

	while (actual != nullptr) {
		if (actual->getInfo()->getCedula() == ced) {
			return true;
		}
		actual = actual->getSig();
	}

	return false;
}

Usuario* ListaUsuario::obtenerUsuario(string ced) {
	actual = primero;

	while (actual != nullptr) {
		if (actual->getInfo()->getCedula() == ced) {
			return actual->getInfo();
		}
		actual = actual->getSig();
	}

	return nullptr;
}

ListaUsuario::~ListaUsuario() {
	while (primero != nullptr) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}
