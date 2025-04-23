#ifndef USUARIODUPLICADOEXCEPTION_H
#define USUARIODUPLICADOEXCEPTION_H
using namespace std;
#include <stdexcept>
#include <string>

class UsuarioDuplicadoException : public runtime_error {
public:
    UsuarioDuplicadoException(const string& cedula)
        : runtime_error("El usuario con cedula '" + cedula + "' ya existe.") {}
};

#endif
