
#include <iostream>
#include <string>

using namespace std;

class Material{
private:
	string numeroClasificacion;
	int numeroCatalogo;
	string titulo;
	string autor;
	string palabraClave;
	string tipo;
	bool estado;
public:
	Material(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado);
	string getNumeroClasificacion() const;
	int getNumeroCatalogo() const;
	string getTitulo() const;
	string getAutor() const;
	string getPalabraClave() const;
	string getTipo() const;
	bool getEstado() const;
	void setEstado(bool nuevoEstado);
	void mostrarInformacion() const;
};

