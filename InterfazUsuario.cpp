#include "InterfazUsuario.h"
#include <iostream>
using namespace std;

void InterfazUsuario::mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "\n===== SISTEMA DE BIBLIOTECA =====\n";
        cout << "1. Gestionar materiales\n";
        cout << "2. Gestionar usuarios\n";
        cout << "3. Registrar pr�stamo/devoluci�n\n";
        cout << "4. Reportes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1: menuMateriales(); break;
        case 2: menuUsuarios(); break;
        case 3: menuPrestamos(); break;
        case 4: menuReportes(); break;
        case 0: cout << "Saliendo del sistema...\n"; break;
        default: cout << "Opci�n inv�lida.\n"; break;
        }
    } while (opcion != 0);
}

void InterfazUsuario::menuMateriales() {
    int opcion;
    do {
        cout << "\n--- GESTI�N DE MATERIALES ---\n";
        cout << "1. Incluir nuevo material\n";
        cout << "2. Modificar material existente\n";
        cout << "3. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Funci�n para incluir material\n";
            break;
        case 2:
            cout << "Funci�n para modificar material\n";
            break;
        case 3:
            return;
        default:
            cout << "Opci�n inv�lida.\n";
        }
    } while (opcion != 3);
}

void InterfazUsuario::menuUsuarios() {
    int opcion;
    do {
        cout << "\n--- GESTI�N DE USUARIOS ---\n";
        cout << "1. Incluir nuevo usuario\n";
        cout << "2. Modificar datos de usuario\n";
        cout << "3. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Funci�n para incluir usuario\n";
            break;
        case 2:
            cout << "Funci�n para modificar usuario\n";
            break;
        case 3:
            return;
        default:
            cout << "Opci�n inv�lida.\n";
        }
    } while (opcion != 3);
}

void InterfazUsuario::menuPrestamos() {
    int opcion;
    do {
        cout << "\n--- PR�STAMOS Y DEVOLUCIONES ---\n";
        cout << "1. Registrar pr�stamo\n";
        cout << "2. Registrar devoluci�n\n";
        cout << "3. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Funci�n para registrar pr�stamo\n";
            break;
        case 2:
            cout << "Funci�n para registrar devoluci�n\n";
            break;
        case 3:
            return;
        default:
            cout << "Opci�n inv�lida.\n";
        }
    } while (opcion != 3);
}

void InterfazUsuario::menuReportes() {
    int opcion;
    do {
        cout << "\n--- REPORTES ---\n";
        cout << "1. Reporte de inventario de materiales\n";
        cout << "2. Reporte de usuarios\n";
        cout << "3. Reporte de materiales en pr�stamo\n";
        cout << "4. Reporte de pr�stamos por usuario\n";
        cout << "5. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Mostrando inventario...\n";
            break;
        case 2:
            cout << "Mostrando usuarios...\n";
            break;
        case 3:
            cout << "Mostrando materiales en pr�stamo...\n";
            break;
        case 4:
            cout << "Mostrando pr�stamos por usuario...\n";
            break;
        case 5:
            return;
        default:
            cout << "Opci�n inv�lida.\n";
        }
    } while (opcion != 5);
}
