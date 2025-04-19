#include "administradorAlmacenamiento.h"

administradorAlmacenamiento::administradorAlmacenamiento() {};

void administradorAlmacenamiento::saveListaMateriales(ListaMateriales* lis, ofstream& file)
{

	NodoMaterial* actual = lis->getPrimero();

	while (actual != NULL) {
		Material* materialTemp = actual->getMaterial();

		file << materialTemp->getCodigo() << endl
			<< materialTemp->getTitulo() << endl
			<< materialTemp->getAutor() << endl
			<< materialTemp->getPalabraClave() << endl
			<< materialTemp->getNumeroCatalogo() << endl
			<< materialTemp->getTipo() << endl;
		if (materialTemp->getTipo() == "libro") {

			Libros* libro = dynamic_cast<Libros*>(materialTemp);

			file << libro->getISBN() << endl
				<< libro->getEditorial() << endl
				<< libro->getFormato() << endl;
		}

		if (materialTemp->getTipo() == "revista") {

			Revistas* revista = dynamic_cast<Revistas*>(materialTemp);

			file << revista->getNumero() << endl
				<< revista->getVolumen() << endl
				<< revista->getFormato() << endl;
		}

		if (materialTemp->getTipo() == "video") {

			Videos* video = dynamic_cast<Videos*>(materialTemp);

			file << video->getDuracion() << endl
				<< video->getFormato() << endl
				<< video->getTema() << endl;
		}

		if (materialTemp->getTipo() == "articulo") {

			Articulos* articulo = dynamic_cast<Articulos*>(materialTemp);

			file << articulo->getFormato() << endl;
		}

		if (materialTemp->getTipo() == "materialDigital") {

			MaterialDigital* materialdigital = dynamic_cast<MaterialDigital*>(materialTemp);

			file << materialdigital->getFormato() << endl;
		}

		actual = actual->getSiguiente();

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
			lis->insertarMaterial(mat);
		}

		if (tipo == "revista") {

			int numero = 0;
			file >> numero;
			int volumen = 0;
			file >> volumen;
			string formato = "";
			file >> formato;

			mat = new Revistas(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, numero, volumen, formato);
			lis->insertarMaterial(mat);
		}

		if (tipo == "video") {

			string duracion = "";
			file >> duracion;
			string formato = "";
			file >> formato;
			string tema = "";
			file >> tema;

			mat = new Videos(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, duracion, formato, tema);
			lis->insertarMaterial(mat);
		}

		if (tipo == "video") {

			string duracion = "";
			file >> duracion;
			string formato = "";
			file >> formato;
			string tema = "";
			file >> tema;

			mat = new Videos(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, duracion, formato, tema);
			lis->insertarMaterial(mat);
		}

		if (tipo == "articulo") {

			string formato = "";
			file >> formato;
			

			mat = new Articulos(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, formato);
			lis->insertarMaterial(mat);
		}

		if (tipo == "materialDigital") {

			string formato = "";
			file >> formato;


			mat = new MaterialDigital(codigo, numeroCatalogo, titulo, autor, palabraClave, tipo, true, formato);
			lis->insertarMaterial(mat);
		}
	}
}

void administradorAlmacenamiento::saveListaUsuarios(ListaUsuario* lis, ofstream& file)
{

	NodoUsuario* actual = lis->getPrimero();

	while (actual != NULL) {
		Usuario* usuarioTemp = actual->getInfo();

		file << usuarioTemp->getNombre() << endl
			<< usuarioTemp->getCedula() << endl
			<< usuarioTemp->getEstado() << endl;

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


