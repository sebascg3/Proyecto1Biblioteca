#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "Usuario.h"
#include "Material.h"
#include "GestorPrestamos.h"
#include <string>

using namespace std;

class Solicitud {
private:
    Usuario* usuario;
    Material* material;
    GestorPrestamos* gest;

public:
    Solicitud(Usuario*, Material*, string, string, bool);
    Solicitud(Solicitud*);
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

#endif
