#pragma once
#include "Material.h"

class Revistas:public Material{
private:
	int Numero;
	int Volumen;
	string Formato;
public:
	Revistas(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, int Numero, int Volumen, string Formato);
	int getNumero() const;
	int getVolumen() const;
	string getFormato() const;
	void mostrarInformacion() const;
};

