#ifndef SOLICITUD_H
#define SOLICITUD_H

#include "Usuario.h"
#include "Material.h"
#include "GestorPrestamos.h"
#include "ObjetoBase.h"
#include <string>

using namespace std;

class Solicitud : public ObjetoBase {
private:
    Usuario* usuario;
    Material* material;
    GestorPrestamos* gest;

public:
    Solicitud(Usuario*, Material*, string);
    Solicitud(Usuario*, Material*, Fecha*, Fecha*, bool);
    /*Solicitud(Solicitud*);*/
    Solicitud();
    ~Solicitud();
    Usuario* getUsuario();
    Material* getMaterial();
    string getfechaP();
    string getfechaD();
    bool getRet();
    void setRet(bool);
    virtual string toString() const;
    GestorPrestamos* getGestor();
};

#endif
