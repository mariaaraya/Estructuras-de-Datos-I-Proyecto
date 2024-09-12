#pragma once
#include "Libreria.h"
#include "Clases.h"

class Controladora
{
public:
	Controladora();
	~Controladora();

	void menuPrincipal();
	void manejoOpcion(int);
	//void mostrarPestanaActual();
	
	void visitarSitio();
	void agregarMarcador();
	void importarExportar();
	void verMarcadores();
	void buscarYFiltrar();
	void alternarModoIncognito();
	void nuevaPestana();
	void configuracion();
private:
	NavegadorWeb* navegador;
	//GestorArchivos* gestor;
};