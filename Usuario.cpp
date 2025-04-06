#include "Usuario.h"

Usuario::Usuario(string nom, string ced, bool est)
{
	nombre = nom;
	cedula = ced;
	estado = est;
}

string Usuario::getNombre()
{
	return nombre;
}

string Usuario::getCedula()
{
	return cedula;
}

bool Usuario::getEstado()
{
	return estado;
}

string Usuario::mostrarUsuario()
{
	stringstream s;
	s << cedula << ";" << nombre << endl;
	s << estado << endl;
	return s.str();
}
