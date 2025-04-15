#include "NodoSolicitud.h"

NodoSolicitud::NodoSolicitud(Solicitud* info_, NodoSolicitud* sig_) {
	info = info_;
	sig = sig_;
}

NodoSolicitud::~NodoSolicitud() {}

void NodoSolicitud::setInfo(Solicitud* info_) {
	info = info_;
}

void NodoSolicitud::setSig(NodoSolicitud* sig_) {
	sig = sig_;
}

Solicitud* NodoSolicitud::getInfo() {
	return info;
}

NodoSolicitud* NodoSolicitud::getSig() {
	return sig;
}

string NodoSolicitud::toStringInfo() {
	return info->mostrarSoli();
}
