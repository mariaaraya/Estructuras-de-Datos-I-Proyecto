#pragma once
#include "MenuPrincipal.h"

class Controler
{
public:
	Controler();
	Controler(NavegadorWeb*);
	~Controler();
	//Principal
	void controlPrincipal();
	// Vistar Pagina Web
	void Vistar();
	// Nueva pesta�a
	void NuevaPestana();
	// Marcador
	void MMarcador();
	// Modo inc�gnito
	void ModoIncognito();
	//B�squeda
	void Busqueda();
	//Configuraci�
	void CConfiguracion();
	//Importaci�n y exportaci�n
	void Archivos();
	void Archivos1();
	void Archivos2();
	// Navegar
	void Navegar();
	//Salir
	void Finalizar();
	//

private:
	NavegadorWeb* navegador;
	int opcion;
};

/*
	std::cout << "6. Configuraci�n\n";
	std::cout << "7. Importaci�n y exportaci�n\n";
	std::cout << "8. Salir\n";  class Controler
	*/