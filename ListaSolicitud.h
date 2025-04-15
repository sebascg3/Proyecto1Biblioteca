#pragma once
#include "NodoSolicitud.h"
#include "Solicitud.h"

class ListaSolicitud {
private:
	NodoSolicitud* primero;
	NodoSolicitud* actual;
public:
	ListaSolicitud();
	bool insertarFinal(Solicitud*);
	string toString();
	bool eliminaFinal();
	Solicitud* obtenerEnPosicion(int);
};
