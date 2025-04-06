#include <iostream>
#include <sstream>
using namespace std;
class Usuario
{
private:
	string nombre;
	string cedula;
	bool estado;

public:
	Usuario(string,string,bool);
	string getNombre();
	string getCedula();
	bool getEstado();
	string mostrarUsuario();
};

