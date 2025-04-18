#include "InterfazUsuario.h"
#include <iostream>
#include <cstdlib>
using namespace std;

InterfazUsuario::InterfazUsuario() {

    controlador = new Controlador();
}

InterfazUsuario::~InterfazUsuario() {
    delete controlador;

}

void InterfazUsuario::mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "===== SISTEMA DE BIBLIOTECA =====\n";
        cout << "1. Gestionar materiales\n";
        cout << "2. Gestionar usuarios\n";
        cout << "3. Registrar prestamo/devolucion\n";
        cout << "4. Reportes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:

            system("pause"); system("cls");
            menuMateriales();
            break;
        case 2:
            system("pause"); system("cls");
            menuUsuarios();
            break;
        case 3:
            system("pause"); system("cls");
            menuPrestamos();
            break;
        case 4:
            system("pause"); system("cls");

            menuMateriales();
            break;
 /*       case 2:
            menuUsuarios();
            break;
        case 3:
            menuPrestamos();
            break;
        case 4:

            menuReportes();
            break;*/
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
            system("pause"); system("cls");
        }
    } while (opcion != 0);
}

void InterfazUsuario::menuMateriales() {
    int opcion;
    do {
        cout << "--- GESTION DE MATERIALES ---\n";
        cout << "1. Incluir nuevo material\n";
        cout << "2. Modificar material existente\n";
        cout << "3. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            controlador->incluirMaterial();
            break;
        case 2:
            controlador->modificarMaterial();
            break;
        case 3:
            return;
        default:
            cout << "Opcion invalida.\n";
        }
        system("pause"); system("cls");
    } while (opcion != 3);
}

void InterfazUsuario::menuUsuarios() {
    int opcion;
    do {
        cout << "--- GESTION DE USUARIOS ---\n";
        cout << "1. Incluir nuevo usuario\n";
        cout << "2. Modificar datos de usuario\n";
        cout << "3. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:

            controlador->incluirUsuario();

            agregarUsuario();

            break;
        case 2:
            controlador->modificarUsuario();
            break;
        case 3:
            return;
        default:
            cout << "Opcion invalida.\n";
        }
        system("pause"); system("cls");
    } while (opcion != 3);
}

void InterfazUsuario::agregarUsuario() {
    string nomU, cedU;
    bool estU;

    cout << "--- 1. INCLUIR NUEVO USUARIO ---\n";
    cout << "Ingrese el nombre: "; cin >> nomU;
    cout << "Ingrese el numero de cedula: "; cin >> cedU;
    system("cls");
    int estado;
    cout << "Activo = 1 / Inactivo = 0\n";
    cout << "Ingrese el estado del Usuario: "; cin >> estado;
    while (estado != 0 && estado != 1) {
        cout << "Entrada invalida. Ingrese 1 o 0: ";
        cin >> estado;
    }
    estU = static_cast<bool>(estado);

    if (biblio->getLisUsu()->encontrado(cedU)) {
        cout << "Error: Ya existe un Usuario registrado con el mismo ID...\n\n";
        system("pause");
        system("cls");
        return;
    }

    Usuario* nuevoU = new Usuario(nomU, cedU, estU);
    biblio->getLisUsu()->insertarFinal(nuevoU);
    cout << "Usuario ingresado satisfactoriamente...\n\n";

    cout << "<<Digita ENTER>>\n";
    cin.get();
    cin.get();
}

void InterfazUsuario::menuPrestamos() {
    int opcion;
    do {
        cout << "--- PRESTAMOS Y DEVOLUCIONES ---\n";
        cout << "1. Registrar prestamo\n";
        cout << "2. Registrar devolucion\n";
        cout << "3. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            controlador->registrarPrestamo();
            break;
        case 2:
            controlador->registrarDevolucion();
            break;
        case 3:
            return;
        default:
            cout << "Opcion invalida.\n";
        }
        system("pause"); system("cls");
    } while (opcion != 3);
}

void InterfazUsuario::menuReportes() {
    int opcion;
    do {
        cout << "--- REPORTES ---\n";
        cout << "1. Reporte de inventario de materiales\n";
        cout << "2. Reporte de usuarios\n";
        cout << "3. Reporte de materiales en prestamo\n";
        cout << "4. Reporte de prestamos por usuario\n";
        cout << "5. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion) {
        case 1:
            controlador->reporteInventario();
            break;
        case 2:

            controlador->reporteUsuarios();

            cout << "---2. REPORTE DE USUARIOS---\n";
            cout << biblio->getLisUsu()->toString() << endl;

            cout << "<<Digita ENTER>>\n";
            cin.get();
            cin.get();


            break;
        case 3:
            controlador->reporteMaterialesPrestados();
            break;
        case 4:
            controlador->reportePrestamosPorUsuario();
            break;
        case 5:
            return;
        default:
            cout << "Opcion invalida.\n";
        }
        system("pause"); system("cls");
    } while (opcion != 5);
}
