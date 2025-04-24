#include "Controlador.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Controlador::Controlador() {
    solicitudes = new ListaSolicitud();
    usuarios = new ListaUsuario();
    materiales = new ListaMateriales();
    adm = new administradorAlmacenamiento();
}

Controlador::~Controlador() {
    delete solicitudes;
    delete usuarios;
    delete materiales;
}

// === MATERIALES ===

void Controlador::incluirMaterial() {
    system("cls");
    cout << "== Incluir nuevo material ==" << endl;

    string numeroClasificacion, titulo, autor, palabraClave, tipo;
    int numeroCatalogo, estadoInt;
    bool estado;

    cout << "Ingrese el n�mero de clasificaci�n: ";
    cin >> numeroClasificacion;

    try {
        if (materiales->buscarMaterial(numeroClasificacion) != nullptr) {
            throw runtime_error("Ya existe un material con ese n�mero de clasificaci�n.");
        }

        cout << "Ingrese el n�mero de cat�logo: ";
        cin >> numeroCatalogo;
        cin.ignore();

        cout << "Ingrese el t�tulo del material: ";
        getline(cin, titulo);

        cout << "Ingrese el/los autor(es): ";
        getline(cin, autor);

        cout << "Ingrese la(s) palabra(s) clave: ";
        getline(cin, palabraClave);

        cout << "Ingrese el tipo de material: ";
        getline(cin, tipo);

        cout << "Estado del material:\n";
        cout << "1. Buen estado\n";
        cout << "2. Regular\n";
        cout << "3. Mal estado\n";
        cout << "Seleccione una opci�n: ";
        cin >> estadoInt;
        
        if (estadoInt == 1 || estadoInt == 2) {
            estado = true;
        }
        else if (estadoInt == 3) {
            estado = false;
        }
        else {
            cout << "Opci�n inv�lida. Se establecer� estado por defecto (buen estado).\n";
            estado = true;
        }

        Material* nuevo = new Material(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado);
        materiales->insertarFinal(nuevo);

        cout << "Material incluido exitosamente.\n";
    }
    catch (const exception& e) {
        cout << "Error al incluir material: " << e.what() << endl;
    }

    system("pause");
    system("cls");
}



void Controlador::modificarMaterial() {
    system("cls");
    cout << "== Modificar material ==" << endl;

    string codigo;
    cout << "Ingrese el codigo del material a modificar: ";
    cin >> codigo;

    Material* encontrado = materiales->buscarMaterial(codigo);
    if (encontrado != nullptr) {
        string nuevoTitulo;
        cout << "Ingrese el nuevo titulo: ";
        cin.ignore();
        getline(cin, nuevoTitulo);
        encontrado->setTitulo(nuevoTitulo);
        cout << "Material modificado correctamente.\n";
    }
    else {
        cout << "Material no encontrado.\n";
    }

    system("pause");
    system("cls");
}

// === USUARIOS ===

void Controlador::incluirUsuario() {
    system("cls");
    cout << "== Incluir nuevo usuario ==" << endl;

    string cedula, nombre;
    int estadoInt;
    bool estado;

    cout << "Ingrese la cedula del usuario: ";
    cin >> cedula;

    try {
        if (usuarios->obtenerUsuario(cedula) != nullptr) {
            throw UsuarioDuplicadoException(cedula);
        }

        cin.ignore();
        cout << "Ingrese el nombre del usuario: ";
        getline(cin, nombre);

        cout << "Estado del usuario:\n";
        cout << "1. Activo\n";
        cout << "2. Inactivo\n";
        cout << "Seleccione una opci�n: ";
        cin >> estadoInt;

        if (estadoInt == 1)
            estado = true;
        else if (estadoInt == 2)
            estado = false;
        else {
            cout << "Opci�n inv�lida. Se establecer� estado por defecto (activo).\n";
            estado = true;
        }

        Usuario* nuevo = new Usuario(nombre, cedula, estado);
        usuarios->insertarFinal(nuevo);

        cout << "Usuario incluido exitosamente.\n";
    }
    catch (const UsuarioDuplicadoException& e) {
        cout << "Error: " << e.what() << endl;
    }

    system("pause");
    system("cls");
}




void Controlador::modificarUsuario() {
    system("cls");
    cout << "== Modificar usuario ==" << endl;

    string cedula;
    cout << "Ingrese la cedula del usuario a modificar: ";
    cin >> cedula;

    Usuario* encontrado = usuarios->obtenerUsuario(cedula);
    if (encontrado != nullptr) {
        string nuevoNombre;
        cout << "Ingrese el nuevo nombre: ";
        cin.ignore();
        getline(cin, nuevoNombre);
        encontrado->setNombre(nuevoNombre);
        cout << "Usuario modificado correctamente.\n";
    }
    else {
        cout << "Usuario no encontrado.\n";
    }
    system("pause");
    system("cls");
}

// === PRESTAMOS ===

void Controlador::registrarPrestamo() {
    system("cls");
    cout << "== Registrar prestamo ==" << endl;

    string cedula, codigo;
    cout << "Ingrese cedula del usuario: ";
    cin >> cedula;
    cout << "Ingrese codigo del material: ";
    cin >> codigo;

    Usuario* usuario = usuarios->obtenerUsuario(cedula);
    Material* material = materiales->buscarMaterial(codigo);

    if (usuario && material && material->isDisponible()) {
        Solicitud* prestamo = new Solicitud(usuario, material, "prestamo");
        solicitudes->insertarFinal(prestamo);
        material->setDisponible(false); // marcar como prestado
        cout << "Prestamo registrado correctamente.\n";
    }
    else {
        cout << "No se pudo registrar el prestamo. Verifique cedula, codigo o disponibilidad.\n";
    }
    system("pause");
    system("cls");
}

void Controlador::registrarDevolucion() {
    system("cls");
    cout << "== Registrar devolucion ==" << endl;

    string codigo;
    cout << "Ingrese el codigo del material a devolver: ";
    cin >> codigo;

    Material* material = materiales->buscarMaterial(codigo);

    if (material && !material->isDisponible()) {
        material->setDisponible(true);
        cout << "Material devuelto correctamente.\n";
    }
    else {
        cout << "No se puede devolver el material. Verifique el codigo o si ya fue devuelto.\n";
    }
    system("pause");
    system("cls");
}

// === REPORTES ===

void Controlador::reporteInventario() {
    system("cls");
    cout << "== Reporte de inventario de materiales ==\n";
    materiales->toString();
    system("pause");
    system("cls");
}

void Controlador::reporteUsuarios() {
    system("cls");
    cout << "== Reporte de usuarios ==\n";
    usuarios->toString();
    system("pause");
    system("cls");
}

void Controlador::reporteMaterialesPrestados() {
    system("cls");
    cout << "== Reporte de materiales en prestamo ==\n";
    materiales->mostrarMaterialesPrestados();
    system("pause");
    system("cls");
}

void Controlador::reportePrestamosPorUsuario() {
    system("cls");
    cout << "== Reporte de prestamos por usuario ==\n";
    string cedula;
    cout << "Ingrese la cedula del usuario: ";
    cin >> cedula;

    solicitudes->mostrarPrestamosPorUsuario(cedula);
    system("pause");
    system("cls");
}

void Controlador::saveMateriales(ListaMateriales* lis, ofstream& file)
{
    adm->saveListaMateriales(lis, file);
}

void Controlador::saveUsuarios(ListaUsuario* lis, ofstream& file)
{
    adm->saveListaUsuarios(lis, file);
}

void Controlador::readMateriales(ListaMateriales* lis, ifstream& file)
{
    adm->readListaMateriales(lis, file);
}

void Controlador::readUsuarios(ListaUsuario* lis, ifstream& file)
{
    adm->readListaUsuarios(lis, file);
}


