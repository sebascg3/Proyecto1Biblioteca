#include "NodoUsuario.h"

NodoUsuario::NodoUsuario(Usuario* info_, NodoUsuario* sig_) {
	info = info_;
	sig = sig_;
}

NodoUsuario::~NodoUsuario() {}

void NodoUsuario::setInfo(Usuario* info_) {
	info = info_;
}

void NodoUsuario::setSig(NodoUsuario* sig_) {
	sig = sig_;
}

Usuario* NodoUsuario::getInfo() {
	return info;
}

NodoUsuario* NodoUsuario::getSig() {
	return sig;
}

string NodoUsuario::toStringInfo() {
	return info->toString();
}
