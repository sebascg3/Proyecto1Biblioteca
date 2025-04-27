#include "administradorAlmacenamiento.h"

administradorAlmacenamiento::administradorAlmacenamiento() {};

void administradorAlmacenamiento::saveListaMateriales(ListaMateriales* lis, ofstream& file)
{
	Nodo* actual = lis->getPrimero();

	while (actual != nullptr) {
		Material* materialTemp = dynamic_cast<Material*>(actual->getInfo());

		file << "Codigo: " << materialTemp->getCodigo() << endl
			<< "Titulo: " << materialTemp->getTitulo() << endl
			<< "Autor: " << materialTemp->getAutor() << endl
			<< "Palabra clave: " << materialTemp->getPalabraClave() << endl
			<< "Numero de catalogo: " << materialTemp->getNumeroCatalogo() << endl
			<< "Tipo: " << materialTemp->getTipo() << endl;

		if (materialTemp->getTipo() == "libro") {
			Libros* libro = dynamic_cast<Libros*>(materialTemp);

			file << "ISBN: " << libro->getISBN() << endl
				<< "Editorial: " << libro->getEditorial() << endl
				<< "Formato: " << libro->getFormato() << endl;
		}
		else if (materialTemp->getTipo() == "revista") {
			Revistas* revista = dynamic_cast<Revistas*>(materialTemp);

			file << "Numero: " << revista->getNumero() << endl
				<< "Volumen: " << revista->getVolumen() << endl
				<< "Formato: " << revista->getFormato() << endl;
		}
		else if (materialTemp->getTipo() == "video") {
			Videos* video = dynamic_cast<Videos*>(materialTemp);

			file << "Duracion: " << video->getDuracion() << endl
				<< "Formato: " << video->getFormato() << endl
				<< "Tema: " << video->getTema() << endl;
		}
		else if (materialTemp->getTipo() == "articulo") {
			Articulos* articulo = dynamic_cast<Articulos*>(materialTemp);

			file << "Formato: " << articulo->getFormato() << endl;
		}
		else if (materialTemp->getTipo() == "materialDigital") {
			MaterialDigital* materialdigital = dynamic_cast<MaterialDigital*>(materialTemp);

			file << "Formato: " << materialdigital->getFormato() << endl;
		}

		file << endl;
		actual = actual->getSig();
	}
}

void administradorAlmacenamiento::readListaMateriales(ListaMateriales* lis, ifstream& file)
{

	Material* mat = nullptr;

	lis->setPrimeroNull();

	if (file.fail()) {
		cerr << "No se pudo abrir el archivo" << endl;
		exit(1);
	}

	while (!file.eof()) {
		string codigo = "";
		file >> codigo;
		string titulo = "";
		file >> titulo;
		string autor = "";
		file >> autor;
		string palabraClave = "";
		file >> palabraClave;
		int numeroCatalogo = 0;
		file >> numeroCatalogo;
		string tipo = "";
		file >> tipo;

		if (tipo == "libro") {

			string ISBN = "";
			file >> ISBN;
			string editorial = "";
			file >> editorial;
			string formato = "";
			file >> formato;

			mat = new Libros(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, ISBN, editorial, formato);
			lis->insertarFinal(mat);
		}

		if (tipo == "revista") {

			int numero = 0;
			file >> numero;
			int volumen = 0;
			file >> volumen;
			string formato = "";
			file >> formato;

			mat = new Revistas(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, numero, volumen, formato);
			lis->insertarFinal(mat);
		}

		if (tipo == "video") {

			string duracion = "";
			file >> duracion;
			string formato = "";
			file >> formato;
			string tema = "";
			file >> tema;

			mat = new Videos(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, duracion, formato, tema);
			lis->insertarFinal(mat);
		}


		if (tipo == "articulo") {

			string formato = "";
			file >> formato;
			

			mat = new Articulos(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, formato);
			lis->insertarFinal(mat);
		}

		if (tipo == "materialDigital") {

			string formato = "";
			file >> formato;


			mat = new MaterialDigital(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, formato);
			lis->insertarFinal(mat);
		}
	}
}

void administradorAlmacenamiento::saveListaUsuarios(ListaUsuario* lis, ofstream& file)
{
	Nodo* actual = lis->getPrimero();

	while (actual != nullptr) {
		Usuario* usuarioTemp = dynamic_cast<Usuario*>(actual->getInfo());

		file << "Nombre: " << usuarioTemp->getNombre() << endl
			<< "Cedula: " << usuarioTemp->getCedula() << endl
			<< "Estado: " << (usuarioTemp->getEstado() ? "Activo" : "Inactivo") << endl;

		file << endl;
		actual = actual->getSig();
	}
}

void administradorAlmacenamiento::readListaUsuarios(ListaUsuario* lis, ifstream& file)
{

	Usuario* usu = nullptr;

	lis->setPrimeroNull();

	if (file.fail()) {
		cerr << "No se pudo abrir el archivo" << endl;
		exit(1);
	}

	/*while (!file.eof()) {
		string nombre = "";
		file >> nombre;
		string cedula = "";
		file >> cedula;
		bool estado;            //si no funcionara el while de abajo, probar este
		file >> estado;

		usu = new Usuario(nombre, cedula, estado);

		lis->insertarFinal(usu);
	}*/

	string nombre, cedula;
	bool estado;

	while (file >> nombre >> cedula >> estado) {

		usu = new Usuario(nombre, cedula, estado);

		lis->insertarFinal(usu);
	}
}

void administradorAlmacenamiento::readListaPrestamos(ListaSolicitud* lis, ifstream& file, ListaMateriales* lisMat,ListaUsuario* lisUs)
{
	Solicitud* soli = nullptr;

	lis->setPrimeroNull();

	if (file.fail()) {
		cerr << "No se pudo abrir el archivo" << endl;
		exit(1);
	}

	string cedula = "";
	string codigo = "";
	while(true){

		if (!(file >> cedula >> codigo)) break;

		int fechaDDia = -1;
		int fechaDMes = -1;
		int fechaDAnno = -1;
		file >> fechaDDia;
		file >> fechaDMes;
		file >> fechaDAnno;

		int fechaPDia = -1;
		int fechaPMes = -1;
		int fechaPAnno = -1;
		file >> fechaPDia;
		file >> fechaPMes;
		file >> fechaPAnno;

		bool retraso = false;
		file >> retraso;



		Usuario* usu = lisUs->obtenerUsuario(cedula);
		Material* mat = lisMat->buscarMaterial(codigo);

		Fecha* fechaP = new Fecha(fechaPDia, fechaPMes, fechaPAnno);
		Fecha* fechaD = new Fecha(fechaDDia, fechaDMes, fechaDAnno);

		soli = new Solicitud(usu, mat, fechaP, fechaD, retraso);

		soli->getMaterial()->setDisponible(false);

		lis->insertarFinal(soli);

	}

	

}

void administradorAlmacenamiento::saveListaPrestamos(ListaSolicitud* lis, ofstream& file) {
	Nodo* actual = lis->getPrimero();

	while (actual != nullptr) {
		Solicitud* solicitudTemp = dynamic_cast<Solicitud*>(actual->getInfo());

		file << "Cedula Usuario: " << solicitudTemp->getUsuario()->getCedula() << endl
			<< "Codigo Material: " << solicitudTemp->getMaterial()->getCodigo() << endl

			<< "Dia de Solicitud: " << solicitudTemp->getGestor()->getfechaD()->getDia() << endl
			<< "Mes de Solicitud: " << solicitudTemp->getGestor()->getfechaD()->getMes() << endl
			<< "Anno de Solicitud: " << solicitudTemp->getGestor()->getfechaD()->getAnno() << endl

			<< "Dia de Prestamo: " << solicitudTemp->getGestor()->getfechaP()->getDia() << endl
			<< "Mes de Prestamo: " << solicitudTemp->getGestor()->getfechaP()->getMes() << endl
			<< "Anno de Prestamo: " << solicitudTemp->getGestor()->getfechaP()->getAnno() << endl

			<< "Retornado: " << (solicitudTemp->getRet() ? "Si" : "No") << endl;

		file << endl;
		actual = actual->getSig();
	}
}


