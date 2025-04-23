#include "ListaSolicitud.h"
#include "Solicitud.h"


ListaSolicitud::ListaSolicitud() {
	primero = nullptr;
	actual = nullptr;
}

Solicitud* ListaSolicitud::obtenerEnPosicion(int pos) {
	if (pos < 0) return nullptr;

	actual = primero;
	int i = 0;

	while (actual != nullptr && i < pos) {
		actual = actual->getSig();
		i++;
	}

	if (actual == nullptr) return nullptr; // Posición fuera de rango

	Solicitud* soli = dynamic_cast<Solicitud*>(actual->getInfo());

	return soli;
}

void ListaSolicitud::mostrarPrestamosPorUsuario(string cedula) {
	actual = primero;
	bool encontrado = false;

	while (actual != nullptr) {
		Solicitud* soli = dynamic_cast<Solicitud*>(actual->getInfo());
		if (soli->getUsuario()->getCedula() == cedula) {
			cout << soli->toString() << endl;
			encontrado = true;
		}
		actual = actual->getSig();
	}

	if (!encontrado) {
		cout << "No se encontraron prestamos para el usuario con cedula: " << cedula << endl;
	}
}

Nodo* ListaSolicitud::getPrimero() {
	return primero;
}

void ListaSolicitud::setPrimeroNull()
{
	primero = NULL;
}

Usuario* ListaSolicitud::buscarUsuarioPorCedula(string cedula)
{
	actual = primero;
	bool encontrado = false;
	Usuario* usu = nullptr;

	while (actual != nullptr) {

		Solicitud* soli = dynamic_cast<Solicitud*>(actual->getInfo());

		if (soli->getUsuario()->getCedula() == cedula) {
			usu = soli->getUsuario();
			encontrado = true;
		}
		actual = actual->getSig();
	}

	return usu;
}

Material* ListaSolicitud::buscarMaterialPorCodigo(string codigo)
{
	actual = primero;
	bool encontrado = false;
	Material* mat = nullptr;

	while (actual != nullptr) {

		Solicitud* soli = dynamic_cast<Solicitud*>(actual->getInfo());

		if (soli->getUsuario()->getCedula() == codigo) {
			mat = soli->getMaterial();
			encontrado = true;
		}
		actual = actual->getSig();
	}

	return mat;
}

