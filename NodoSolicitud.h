#pragma once
#include "Solicitud.h"

class NodoSolicitud {
private:
	Solicitud* info;
	NodoSolicitud* sig;
public:
	NodoSolicitud(Solicitud*, NodoSolicitud*);
	~NodoSolicitud();
	void setInfo(Solicitud*);
	void setSig(NodoSolicitud*);
	Solicitud* getInfo();
	NodoSolicitud* getSig();
	string toStringInfo();
};
