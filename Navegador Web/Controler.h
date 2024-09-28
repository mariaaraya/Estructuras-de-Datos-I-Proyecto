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
	// Nueva pestaña
	void NuevaPestana();
	// EliminarPestaña
	void EliminarPestana();
	// Marcador
	void MMarcador();
	// Modo incógnito
	void ModoIncognito();
	//Búsqueda
	void Busqueda();
	//Configuració
	void CConfiguracion();
	//Importación y exportación
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
