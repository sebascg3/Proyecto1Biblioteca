#include "Solicitud.h"

#include "Solicitud.h"

Solicitud::Solicitud(Usuario* u, Material* m, string tipo)
	: usuario(u), material(m), gest(nullptr) {
	if (tipo == "prestamo") {
		gest = new GestorPrestamos(NULL, NULL, false);
	}
}


Solicitud::Solicitud(Usuario* us, Material* mat, Fecha* fP, Fecha* fD, bool ret)
{
	usuario = us;
	material = mat;
	gest = new GestorPrestamos(fP, fD, ret);
}

//Solicitud::Solicitud(Solicitud* s) {
//	usuario = s->usuario;
//	material = s->material;
//	gest = new GestorPrestamos(s->getfechaD(), s->getfechaP(), s->getRet());
//}

Solicitud::Solicitud()
{
	usuario = nullptr;
	material = nullptr;
	gest = new GestorPrestamos(NULL, NULL, false);
}

Solicitud::~Solicitud()
{
	delete usuario;
	delete material;
	delete gest;
}

Usuario* Solicitud::getUsuario()
{
	return usuario;
}

Material* Solicitud::getMaterial()
{
	return material;
}

string Solicitud::getfechaP()
{
	return gest->getfechaP()->toString();
}

string Solicitud::getfechaD()
{
	return gest->getfechaD()->toString();
}

bool Solicitud::getRet()
{
	return gest->getRet();
}

void Solicitud::setRet(bool ret)
{
	gest->setRet(ret);
}

string Solicitud::toString() const {
	stringstream s;
	s << "Usuario:" << usuario->getNombre() << endl;
	s << "Material: " << material->getTitulo() <<";"<<"Nombre: "<<material->getTitulo()<< endl;
	s << "Fecha de prestamo:" << gest->getfechaP()->toString() << endl;
	s << "Fecha devolucion:" << gest->getfechaD()->toString() << endl;
	if (gest->getRet() == true) {
		s << "Entrega retrasada" << endl;
	}
	s << "/////////////////////////////////////////////" << endl;
	return s.str();
}

GestorPrestamos* Solicitud::getGestor()
{
	return gest;
}
