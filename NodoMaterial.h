#include <iostream>
#include <string>
#include "Material.h"

using namespace std;

class NodoMaterial {

private:
	Material* mat;
	NodoMaterial* siguiente;

public:
	NodoMaterial(Material* m) : mat(m), siguiente(nullptr) {}

	NodoMaterial* getSiguiente() const { return siguiente; }
	void setSiguiente(NodoMaterial* sig) { siguiente = sig; }

	Material* getMaterial() const { return mat; }
	void setMaterial(Material* m) { mat = m; }

};