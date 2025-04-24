#include "Fecha.h"

Fecha::Fecha(int dia_, int mes_, int anno_)
{
	dia = dia_;
	mes = mes_;
	anno = anno_;
}

string Fecha::toString()
{
	stringstream s;

	s << dia << "/" << mes << "/" << anno << endl;

	return s.str();
}

int Fecha::getDia()
{
	return dia;
}

int Fecha::getMes()
{
	return mes;
}

int Fecha::getAnno()
{
	return anno;
}


