#include "Solicitud.h"

Solicitud::Solicitud(Usuario* us, Material* mat, string fP, string fD, bool ret)
{
	usuario = us;
	material = mat;
	fPrestamo = fP;
	fDevolucion = fD;
	retrasado = ret;
}

Solicitud::Solicitud()
{
	usuario = nullptr;
	material = nullptr;
	fPrestamo = " ";
	fDevolucion = " ";
	retrasado = false;
}

Solicitud::~Solicitud()
{
	delete usuario;
	delete material;
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
	return fPrestamo;
}

string Solicitud::getfechaD()
{
	return fDevolucion;
}

bool Solicitud::getRet()
{
	return retrasado;
}

void Solicitud::setRet(bool ret)
{
	retrasado = ret;
}

string Solicitud::mostrarSoli()
{
	stringstream s;
	s << "/////////Solicitud/////////" << endl;
	s << "Usuario:" << usuario->getNombre() << endl;
	s << "Material: " << material->getTipo() <<";"<<"Nombre: "<<material->getTitulo()<< endl;
	s << "Fecha de prestamo:" << fPrestamo << endl;
	s << "Fecha devolucion:" << fDevolucion << endl;
	if (retrasado == true) {
		s << "Entrega retrasada" << endl;
	}
	s << "/////////////////////////////////////////////" << endl;
	return s.str();
}
