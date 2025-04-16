#include "GestorPrestamos.h"

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
