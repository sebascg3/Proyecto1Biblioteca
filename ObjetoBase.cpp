#include "ObjetoBase.h"

ObjetoBase::~ObjetoBase() {}

ostream& operator<<(ostream& salida, const ObjetoBase& obj) {
	salida << obj.toString() << endl;
	return salida;
}
