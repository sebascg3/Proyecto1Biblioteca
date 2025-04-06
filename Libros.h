
#include "Material.h"

class Libros :public Material {
private:
	string ISBN;
	string editorial;
	string formato;
public:
	Libros(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string ISBN, string editorial, string formato);
	string getISBN() const;
	string getEditorial() const;
	string getFormato() const;
	void mostrarInformacion() const;
};

