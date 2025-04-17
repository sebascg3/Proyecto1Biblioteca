#include "GestorPrestamos.h"

GestorPrestamos::GestorPrestamos(string fP, string fD, bool ret)
	: fPrestamo(fP), fDevolucion(fD), retrasado(ret) {
}

string GestorPrestamos::getfechaP()
{
	return fPrestamo;
}

string GestorPrestamos::getfechaD()
{
	return fDevolucion;
}

void GestorPrestamos::setFechaP(string fechUs) {
	fPrestamo = fechUs;
}

void GestorPrestamos::setFechaD(string fechUs2) {
	fDevolucion = fechUs2;
}

bool GestorPrestamos::getRet()
{
	return retrasado;
}

void GestorPrestamos::setRet(bool ret)
{
	retrasado = ret;
}
