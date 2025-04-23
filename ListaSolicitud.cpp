#include "ListaSolicitud.h"
#include "Solicitud.h"


ListaSolicitud::ListaSolicitud() {
	primero = nullptr;
	actual = nullptr;
}

bool ListaSolicitud::insertarFinal(Solicitud* s) {
	bool tof = false;

	Solicitud* SoliPtr = new Solicitud(s);
	NodoSolicitud* nuevoN = new NodoSolicitud(SoliPtr, nullptr);

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

string ListaSolicitud::toString() {
	stringstream s;
	int numSoli = 1;

	actual = primero;
	if (actual != nullptr) {
		while (actual != nullptr) {
			s << "Solicitud #" << numSoli << endl << endl;
			s << actual->toStringInfo() << endl;
			s << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";

			actual = actual->getSig();
			numSoli++;
		}
	}
	else {
		s << "No existen Solicitudes registradas actualmente...\n\n";
	}

	return s.str();
}

bool ListaSolicitud::eliminaFinal() {
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

Solicitud* ListaSolicitud::obtenerEnPosicion(int pos) {
	if (pos < 0) return nullptr;

	NodoSolicitud* aux = primero;
	int i = 0;

	while (aux != nullptr && i < pos) {
		aux = aux->getSig();
		i++;
	}

	if (aux == nullptr) return nullptr; // Posición fuera de rango

	return aux->getInfo();
}

void ListaSolicitud::mostrarPrestamosPorUsuario(string cedula) {
	NodoSolicitud* actual = primero;
	bool encontrado = false;

	while (actual != nullptr) {
		Solicitud* solicitud = actual->getInfo();
		if (solicitud->getUsuario()->getCedula() == cedula) {
			cout << solicitud->toString() << endl;
			encontrado = true;
		}
		actual = actual->getSig();
	}

	if (!encontrado) {
		cout << "No se encontraron prestamos para el usuario con cedula: " << cedula << endl;
	}
}

