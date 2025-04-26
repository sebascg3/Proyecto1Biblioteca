#include "ListaUsuario.h"

ListaUsuario::ListaUsuario() {
	primero = nullptr;
	actual = nullptr;
}

bool ListaUsuario::encontrado(string ced) {
	actual = primero;

	while (actual != nullptr) {
		Usuario* usu = dynamic_cast<Usuario*>(actual->getInfo());
		if (usu != nullptr && usu->getCedula() == ced) {
			return true;
		}
		actual = actual->getSig();
	}

	return false;
}

Usuario* ListaUsuario::obtenerUsuario(string ced) {  
actual = primero;  

while (actual != nullptr) {  
	Usuario* usuarioActual = dynamic_cast<Usuario*>(actual->getInfo());  
	if (usuarioActual != nullptr && usuarioActual->getCedula() == ced) {  
		return new Usuario(*usuarioActual);  
	}  
	actual = actual->getSig();  
}  

return nullptr;  
}


Nodo* ListaUsuario::getPrimero() {
	return primero;
}

void ListaUsuario::setPrimeroNull()
{
	primero = NULL;
}

ListaUsuario::~ListaUsuario() {
	while (primero != nullptr) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
	}
}
