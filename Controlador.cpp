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

    string codigo, titulo;
    cout << "Ingrese el codigo del material: ";
    cin >> codigo;

    try {
        if (materiales->buscarMaterial(codigo) != nullptr) {
            throw runtime_error("Ya existe un material con ese codigo.");
        }

        cout << "Ingrese el titulo del material: ";
        cin.ignore();
        getline(cin, titulo);

        Material* nuevo = new Material(codigo, titulo);
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
    cout << "Ingrese la cedula del usuario: ";
    cin >> cedula;

    try {
        if (usuarios->obtenerUsuario(cedula) != nullptr) {
            throw UsuarioDuplicadoException(cedula);
        }

        cout << "Ingrese el nombre del usuario: ";
        cin.ignore();
        getline(cin, nombre);

        Usuario* nuevo = new Usuario(cedula, nombre);
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


