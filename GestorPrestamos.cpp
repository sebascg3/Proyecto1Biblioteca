#include "GestorPrestamos.h"

GestorPrestamos::GestorPrestamos(Fecha* fP, Fecha* fD, bool ret)
	: fPrestamo(fP), fDevolucion(fD), retrasado(ret) {
}

Fecha* GestorPrestamos::getfechaP()
{
	return fPrestamo;
}

Fecha* GestorPrestamos::getfechaD()
{
	return fDevolucion;
}

void GestorPrestamos::setFechaP(Fecha* fechUs) {
	fPrestamo = fechUs;
}

void GestorPrestamos::setFechaD(Fecha* fechUs2) {
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
