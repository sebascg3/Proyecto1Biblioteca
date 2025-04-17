#include "Solicitud.h"

Solicitud::Solicitud(Usuario* us, Material* mat, string fP, string fD, bool ret)
{
	usuario = us;
	material = mat;
	gest = new GestorPrestamos(fP, fD, ret);
}

Solicitud::Solicitud(Solicitud* s) {
	usuario = s->usuario;
	material = s->material;
	gest = new GestorPrestamos(s->getfechaP(), s->getfechaD(), s->getRet());
}

Solicitud::Solicitud()
{
	usuario = nullptr;
	material = nullptr;
	gest = new GestorPrestamos(" ", " ", false);
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
	return gest->getfechaP();
}

string Solicitud::getfechaD()
{
	return gest->getfechaD();
}

bool Solicitud::getRet()
{
	return gest->getRet();
}

void Solicitud::setRet(bool ret)
{
	gest->setRet(ret);
}

string Solicitud::mostrarSoli()
{
	stringstream s;
	s << "Usuario:" << usuario->getNombre() << endl;
	s << "Material: " << material->getTipo() <<";"<<"Nombre: "<<material->getTitulo()<< endl;
	s << "Fecha de prestamo:" << gest->getfechaP() << endl;
	s << "Fecha devolucion:" << gest->getfechaD() << endl;
	if (gest->getRet() == true) {
		s << "Entrega retrasada" << endl;
	}
	s << "/////////////////////////////////////////////" << endl;
	return s.str();
}
