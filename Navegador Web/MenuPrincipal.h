#pragma once

#include "Libreria.h"
#include "Clases.h"
class MenuPrincipal
{
public:
	/*---Principla---*/
	static int menuPrincipal();
	/*---Navegar---*/
	static std::string URl();
	static void pagina404();
	/*---Marcador---*/
	static std::string nombreMarcador();
	static Marcador* marcador();
	/*Configuracion*/
	static Configuracion* crearConfiguracion();
	/*Archivos*/
	static int menuArchivo();
	static std::string nombreArchivo();
	static std::string nombreArchivoLeer();
	/*---Comprobacion---*/
	static void comprobarint(int&);
	/*---Excepcion---*/
	static void excepcion(Excepcion*);
	static void error();
	/*--Salida---*/
	static void bienvenida();
	static void salir();
private:

};

