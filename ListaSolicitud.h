#pragma once
#include "Nodo.h"
#include "Solicitud.h"
#include "ListaBase.h"

class ListaSolicitud : public ListaBase {
public:
	ListaSolicitud();
	Solicitud* obtenerEnPosicion(int);
	void mostrarPrestamosPorUsuario(string cedula);

};
