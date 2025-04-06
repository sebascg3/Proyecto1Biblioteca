#pragma once
#include "Material.h"

class MaterialDigital : public Material {
private:
	string formato;
public:
	MaterialDigital(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string formato);
	string getFormato() const;
	void mostrarInformacion() const;


};

