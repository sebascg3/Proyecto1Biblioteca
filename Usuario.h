#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <sstream>
using namespace std;

class Usuario {
private:
    string nombre;
    string cedula;
    bool estado;

public:
    Usuario(string, string, bool);
    Usuario(Usuario*);
    string getNombre();
    string getCedula();
    bool getEstado();
    string mostrarUsuario();
};

#endif // USUARIO_H
