#include "Usuario.h"
#include "Material.h"
class Solicitud
{
private:
	Usuario* usuario;
	Material* material;
	string fPrestamo;
	string fDevolucion;
	bool retrasado;

public:
	Solicitud(Usuario*,Material*,string,string,bool);
	Solicitud();
	~Solicitud();
	Usuario* getUsuario();
	Material* getMaterial();
	string getfechaP();
	string getfechaD();
	bool getRet();
	void setRet(bool);
	string mostrarSoli();
};

