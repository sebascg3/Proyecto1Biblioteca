
#include "Material.h"
class Videos :public Material {
private:
	string duracion;
	string formato;
	string tipo;
	string tema;
	string nombre;
public:
	Videos(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado, string duracion, string formato, string tema);
	string getDuracion() const;
	string getFormato() const;
	string getTema() const;
	void mostrarInformacion() const;
};

