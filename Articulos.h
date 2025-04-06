
#include "Material.h"


class Articulos : public Material {
private:
	string formato;
public:
	Articulos(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string formato);
	string getFormato() const;
	void mostrarInformacion() const;
};

