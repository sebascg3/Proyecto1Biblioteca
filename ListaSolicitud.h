#pragma once
#include "Nodo.h"
#include "Solicitud.h"
#include "ListaBase.h"

class ListaSolicitud : public ListaBase {
public:
	ListaSolicitud();
	Solicitud* obtenerEnPosicion(int);
	void mostrarPrestamosPorUsuario(string cedula);

	Nodo* getPrimero();
	void setPrimeroNull();

	Usuario* buscarUsuarioPorCedula(string);
	Material* buscarMaterialPorCodigo(string);
	void actualizarPrestamos(Fecha*);
};