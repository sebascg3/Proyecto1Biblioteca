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

    string numeroClasificacion;
    cout << "Ingrese el numero de clasificacion: ";
    cin >> numeroClasificacion;

    try {
        if (materiales->buscarMaterial(numeroClasificacion) != nullptr) {
            throw runtime_error("Ya existe un material con ese numero de clasificacion.");
        }

        int numeroCatalogo, estadoInt, opcion;
        string titulo, autor, palabraClave, tipo, formato;
        bool estado;

        cin.ignore();

        cout << "Ingrese el titulo: ";
        getline(cin, titulo);

        cout << "Ingrese el autor o autores: ";
        getline(cin, autor);

        cout << "Ingrese la(s) palabra(s) clave: ";
        getline(cin, palabraClave);

        cout << "Ingrese el numero de catalogo: ";
        cin >> numeroCatalogo;

        cout << "Estado del material:\n1. Buen estado\n2. Regular\n3. Mal estado\nSeleccione una opcion: ";
        cin >> estadoInt;
        estado = (estadoInt == 1 || estadoInt == 2);

        cin.ignore(); // limpiar buffer
        cout << "Ingrese el formato: ";
        getline(cin, formato);

        cout << "\nSeleccione el tipo especifico del material:\n";
        cout << "1. Revista\n2. Libro\n3. Material digital\n4. Video\n5. Articulo\n";
        cout << "Opcion: ";
        cin >> opcion;

        Material* nuevo = nullptr;

        switch (opcion) {
        case 1: { // Revista
            int numero, volumen;
            cout << "Ingrese el numero: ";
            cin >> numero;
            cout << "Ingrese el volumen: ";
            cin >> volumen;
            tipo = "revista";
            nuevo = new Revistas(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado, numero, volumen, formato);
            break;
        }
        case 2: { // Libro
            string ISBN, editorial;
            cin.ignore();
            cout << "Ingrese el ISBN: ";
            getline(cin, ISBN);
            cout << "Ingrese la editorial: ";
            getline(cin, editorial);
            tipo = "libro";
            nuevo = new Libros(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado, ISBN, editorial, formato);
            break;
        }
        case 3: { // Material Digital
            tipo = "materialDigital";
            nuevo = new MaterialDigital(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado, formato);
            break;
        }
        case 4: { // Video
            string duracion, tema;
            cin.ignore();
            cout << "Ingrese la duracion: ";
            getline(cin, duracion);
            cout << "Ingrese el tema: ";
            getline(cin, tema);
            tipo = "video";
            nuevo = new Videos(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado, duracion, formato, tema);
            break;
        }
        case 5: { // Articulo
            tipo = "articulo";
            nuevo = new Articulos(numeroClasificacion, numeroCatalogo, titulo, autor, palabraClave, tipo, estado, formato);
            break;
        }
        default:
            cout << "Opcion invalida.\n";
            system("pause");
            system("cls");
            return;
        }

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
    cout << "Ingrese el numero de clasificacion del material a modificar: ";
    cin >> codigo;

    Material* encontrado = materiales->buscarMaterial(codigo);
    if (encontrado != nullptr) {
        int nuevoCatalogo, estadoInt;
        string nuevoTitulo, nuevoAutor, nuevaPalabraClave, nuevoTipo;
        bool nuevoEstado;

        cin.ignore(); // Limpiar buffer

        cout << "Ingrese el nuevo titulo: ";
        getline(cin, nuevoTitulo);

        cout << "Ingrese el nuevo autor o autores: ";
        getline(cin, nuevoAutor);

        cout << "Ingrese la(s) nueva(s) palabra(s) clave: ";
        getline(cin, nuevaPalabraClave);

        cout << "Ingrese el nuevo tipo de material: ";
        getline(cin, nuevoTipo);

        cout << "Ingrese el nuevo numero de catalogo: ";
        cin >> nuevoCatalogo;

        cout << "Nuevo estado del material:\n";
        cout << "1. Buen estado\n";
        cout << "2. Regular\n";
        cout << "3. Mal estado\n";
        cout << "Seleccione una opcion: ";
        cin >> estadoInt;

        if (estadoInt == 1 || estadoInt == 2) {
            nuevoEstado = true;
        }
        else {
            nuevoEstado = false;
        }

        // Asignar nuevos valores
        encontrado->setTitulo(nuevoTitulo);
        encontrado->setAutor(nuevoAutor);
        encontrado->setPalabraClave(nuevaPalabraClave);
        encontrado->setTipo(nuevoTipo);
        encontrado->setNumeroCatalogo(nuevoCatalogo);
        encontrado->setDisponible(nuevoEstado);

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
        cout << "Seleccione una opcion: ";
        cin >> estadoInt;

        if (estadoInt == 1)
            estado = true;
        else if (estadoInt == 2)
            estado = false;
        else {
            cout << "Opción inválida. Se establecerá estado por defecto (activo).\n";
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

    try {
        if (materiales->cuentaNodos() == 0 || usuarios->cuentaNodos() == 0) { throw string("La lista de materiales o usuarios esta vacia, porfavor inserte usuarios/materiales antes de crear prestamos."); }

    cout << "== Registrar prestamo ==" << endl;

    string cedula, codigo;
    cout << "Ingrese cedula del usuario: ";
    cin >> cedula;
    cout << "Ingrese el numero de clasificacion del material: ";
    cin >> codigo;

    Usuario* usuario = usuarios->obtenerUsuario(cedula);
    Material* material = materiales->buscarMaterial(codigo);

    if (usuario && material && material->esDisponible()) {

        Fecha* fecha = NULL;
        Fecha* fechaD = NULL;

        while (fecha == NULL) {
            try {
                cout << "Porfavor digite la fecha a usar para los prestamos" << endl;
                cout << "Digite el dia:" << endl;
                int dia;
                cin >> dia;
                if (dia > 31)throw string("Porfavor digite un numero menor a 31");

                cout << "Digite el mes:" << endl;
                int mes;
                cin >> mes;
                if (mes > 12)throw string("Porfavor digite un numero menor a 12");

                cout << "Digite el anno:" << endl;
                int anno;
                cin >> anno;

                fecha = new Fecha(dia, mes, anno);
            }
            catch (string x) { cout << "Ha ocurrido un error: " << x << endl; }
        }

        if (material->getTipo() == "libro") {

            int diaD = fecha->getDia() + 7;

            int mesD = fecha->getMes();
            if (diaD > 31) { mesD++; diaD = diaD - 31; }

            int annoD = fecha->getAnno();

            fechaD = new Fecha(diaD, mesD, annoD);
        }

        if (material->getTipo() == "revista") {

            int diaD = fecha->getDia() + 2;

            int mesD = fecha->getMes();
            if (diaD > 31) { mesD++; diaD = diaD - 31; }

            int annoD = fecha->getAnno();

            fechaD = new Fecha(diaD, mesD, annoD);
        }

        if (material->getTipo() == "articulo") {

            int diaD = fecha->getDia() + 3;

            int mesD = fecha->getMes();
            if (diaD > 31) { mesD++; diaD = diaD - 31; }

            int annoD = fecha->getAnno();

            fechaD = new Fecha(diaD, mesD, annoD);
        }

        if (material->getTipo() == "video") {

            int diaD = fecha->getDia() + 5;

            int mesD = fecha->getMes();
            if (diaD > 31) { mesD++; diaD = diaD - 31; }

            int annoD = fecha->getAnno();

            fechaD = new Fecha(diaD, mesD, annoD);
        }

        if (material->getTipo() == "materialDigital") {

            int diaD = fecha->getDia();

            int mesD = fecha->getMes();
            if (diaD > 31) { mesD++; diaD = diaD - 31; }

            int annoD = fecha->getAnno();

            fechaD = new Fecha(diaD, mesD, annoD);
        }

        Solicitud* prestamo = new Solicitud(usuario, material, fecha, fechaD, false);

        solicitudes->insertarFinal(prestamo);
        material->setDisponible(false); 
        cout << "Prestamo registrado correctamente.\n";
    }
    else {
        cout << "No se pudo registrar el prestamo. Verifique cedula, codigo o disponibilidad.\n";
    }
    }
    catch (string x) { cout << "Error: " << x << endl; }
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

    if (material && !material->esDisponible()) {
        material->setDisponible(true);
        cout << "Material devuelto correctamente.\n";
    }
    else {
        cout << "No se puede devolver el material. Verifique el codigo o si ya fue devuelto.\n";
    }
    system("pause");
    system("cls");
}

void Controlador::actualizarPrestamo() {
    system("cls");

    Fecha* fecha = NULL;

    while (fecha == NULL) {
        try {
            cout << "Porfavor digite la fecha a usar para actualizar" << endl;
            cout << "Digite el dia:" << endl;
            int dia;
            cin >> dia;
            if (dia > 31)throw string("Porfavor digite un numero menor a 31");

            cout << "Digite el mes:" << endl;
            int mes;
            cin >> mes;
            if (mes > 12)throw string("Porfavor digite un numero menor a 12");

            cout << "Digite el anno:" << endl;
            int anno;
            cin >> anno;

            fecha = new Fecha(dia, mes, anno);
        }
        catch (string x) { cout << "Ha ocurrido un error: " << x << endl; }
    }

    solicitudes->actualizarPrestamos(fecha);



    cout << "== prestamos actualizados ==" << endl;
}

// === REPORTES ===

void Controlador::reporteInventario() {
    system("cls");
    cout << "== Reporte de inventario de materiales ==\n";
    cout << materiales->toString();
    system("pause");
    system("cls");
}

void Controlador::reporteUsuarios() {
    system("cls");
    cout << "== Reporte de usuarios ==\n";
    cout << usuarios->toString();
    system("pause");
    system("cls");
}

void Controlador::reporteMaterialesPrestados() {
    system("cls");
    cout << "== Reporte de materiales en prestamo ==\n";
    cout << materiales->mostrarMaterialesPrestados();
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


//save y read

void Controlador::saveUsuarios() {

    cout << "Datos Guardados" << endl;

    ofstream fileUsuarios;

    fileUsuarios.open("usuarios.txt", ios::out);

    adm->saveListaUsuarios(usuarios, fileUsuarios);

    fileUsuarios.close();

    cout << "<Digita Enter>" << endl;

    cin.get();
    cin.get();
}

void Controlador::saveMateriales() {

    cout << "Datos Guardados" << endl;

    ofstream fileMateriales;

    fileMateriales.open("materiales.txt", ios::out);

    adm->saveListaMateriales(materiales, fileMateriales);

    fileMateriales.close();

    cout << "<Digita Enter>" << endl;

    cin.get();
    cin.get();
}

void Controlador::savePrestamos() {

    cout << "Datos Guardados" << endl;

    ofstream fileSolicitudes;

    fileSolicitudes.open("solicitudes.txt", ios::out);

    adm->saveListaPrestamos(solicitudes, fileSolicitudes);

    fileSolicitudes.close();

    cout << "<Digita Enter>" << endl;

    cin.get();
    cin.get();
}

void Controlador::readUsuarios() {

    cout << "Datos cargados" << endl;

    ifstream fileUsuarios;

    fileUsuarios.open("usuarios.txt", ios::in);
  
    adm->readListaUsuarios(usuarios, fileUsuarios);

    fileUsuarios.close();

    cout << "<Digita Enter>" << endl;

    cin.get();
    cin.get();
}

void Controlador::readMateriales() {

    cout << "Datos cargados" << endl;

    ifstream fileMateriales;

    fileMateriales.open("materiales.txt", ios::in);

    adm->readListaMateriales(materiales, fileMateriales);

    fileMateriales.close();

    cout << "<Digita Enter>" << endl;

    cin.get();
    cin.get();
}

void Controlador::readPeticiones() {

    cout << "Datos cargados" << endl;

    ifstream filePrestamos;

    filePrestamos.open("solicitudes.txt", ios::in);

    adm->readListaPrestamos(solicitudes, filePrestamos, materiales, usuarios);

    filePrestamos.close();

    cout << "<Digita Enter>" << endl;

    cin.get();
    cin.get();
}