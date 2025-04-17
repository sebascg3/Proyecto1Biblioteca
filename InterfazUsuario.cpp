#include "InterfazUsuario.h"
#include <iostream>
using namespace std;

void InterfazUsuario::mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "\n===== SISTEMA DE BIBLIOTECA =====\n";
        cout << "1. Gestionar materiales\n";
        cout << "2. Gestionar usuarios\n";
        cout << "3. Registrar préstamo/devolución\n";
        cout << "4. Reportes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: menuMateriales(); break;
        case 2: menuUsuarios(); break;
        case 3: menuPrestamos(); break;
        case 4: menuReportes(); break;
        case 0: cout << "Saliendo del sistema...\n"; break;
        default: cout << "Opción inválida.\n"; break;
        }
    } while (opcion != 0);
}

void InterfazUsuario::menuMateriales() {
    int opcion;
    do {
        cout << "\n--- GESTIÓN DE MATERIALES ---\n";
        cout << "1. Incluir nuevo material\n";
        cout << "2. Modificar material existente\n";
        cout << "3. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Función para incluir material\n";
            break;
        case 2:
            cout << "Función para modificar material\n";
            break;
        case 3:
            return;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 3);
}

void InterfazUsuario::menuUsuarios() {
    int opcion;
    do {
        cout << "\n--- GESTIÓN DE USUARIOS ---\n";
        cout << "1. Incluir nuevo usuario\n";
        cout << "2. Modificar datos de usuario\n";
        cout << "3. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Función para incluir usuario\n";
            break;
        case 2:
            cout << "Función para modificar usuario\n";
            break;
        case 3:
            return;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 3);
}

void InterfazUsuario::menuPrestamos() {
    int opcion;
    do {
        cout << "\n--- PRÉSTAMOS Y DEVOLUCIONES ---\n";
        cout << "1. Registrar préstamo\n";
        cout << "2. Registrar devolución\n";
        cout << "3. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Función para registrar préstamo\n";
            break;
        case 2:
            cout << "Función para registrar devolución\n";
            break;
        case 3:
            return;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 3);
}

void InterfazUsuario::menuReportes() {
    int opcion;
    do {
        cout << "\n--- REPORTES ---\n";
        cout << "1. Reporte de inventario de materiales\n";
        cout << "2. Reporte de usuarios\n";
        cout << "3. Reporte de materiales en préstamo\n";
        cout << "4. Reporte de préstamos por usuario\n";
        cout << "5. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Mostrando inventario...\n";
            break;
        case 2:
            cout << "Mostrando usuarios...\n";
            break;
        case 3:
            cout << "Mostrando materiales en préstamo...\n";
            break;
        case 4:
            cout << "Mostrando préstamos por usuario...\n";
            break;
        case 5:
            return;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 5);
}
