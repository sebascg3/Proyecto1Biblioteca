#include "Controlador.h"
#include <iostream>
#include <string>

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
    cout << "== Incluir nuevo material ==" << endl;

    string codigo, titulo;
    cout << "Ingrese el codigo del material: ";
    cin >> codigo;
    cout << "Ingrese el titulo del material: ";
    cin.ignore(); // para limpiar buffer
    getline(cin, titulo);

    Material* nuevo = new Material(codigo, titulo);
    materiales->insertarMaterial(nuevo);

    cout << "Material incluido exitosamente.\n";
}

void Controlador::modificarMaterial() {
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
}

// === USUARIOS ===

void Controlador::incluirUsuario() {
    cout << "== Incluir nuevo usuario ==" << endl;

    string cedula, nombre;
    cout << "Ingrese la cedula del usuario: ";
    cin >> cedula;
    cout << "Ingrese el nombre del usuario: ";
    cin.ignore();
    getline(cin, nombre);

    Usuario* nuevo = new Usuario(cedula, nombre);
    usuarios->insertarFinal(nuevo);

    cout << "Usuario incluido exitosamente.\n";
}


void Controlador::modificarUsuario() {
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
}

// === PRESTAMOS ===

void Controlador::registrarPrestamo() {
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
}

void Controlador::registrarDevolucion() {
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
}

// === REPORTES ===

void Controlador::reporteInventario() {
    cout << "== Reporte de inventario de materiales ==\n";
    materiales->toString();
}

void Controlador::reporteUsuarios() {
    cout << "== Reporte de usuarios ==\n";
    usuarios->toString();
}

void Controlador::reporteMaterialesPrestados() {
    cout << "== Reporte de materiales en prestamo ==\n";
    materiales->mostrarMaterialesPrestados();
}

void Controlador::reportePrestamosPorUsuario() {
    cout << "== Reporte de prestamos por usuario ==\n";
    string cedula;
    cout << "Ingrese la cedula del usuario: ";
    cin >> cedula;

    solicitudes->mostrarPrestamosPorUsuario(cedula);
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


