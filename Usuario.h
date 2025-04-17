#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <sstream>
using namespace std;

class Usuario {
private:
    string nombre;
    string cedula;
    bool estado;

public:
    Usuario(string nom, string ced, bool est);
    Usuario(Usuario* u);
    Usuario(string nom, string ced);

    string getNombre();
    string getCedula();
    bool getEstado();

    void setNombre(string n);

    string mostrarUsuario();
};

#endif