#pragma once
#include "Clases.h"


class NavegadorWeb
{
public:
	virtual~NavegadorWeb();
	/*Get del NavegarWeb*/
	static NavegadorWeb& getNavegadorWeb();
	ListaPestana* getPestanaLista();
	Configuracion* getConfiguracion();
	/*----Historial de navegaci�n----*/
	bool navegar(int);
	/*----Administrador de pesta�as----*/
	// 1- Creacion de paginas y pesta�as
	bool visitarPagina(std::string);
	void crearPestana(bool); // Metodo tambien usado para creacion de pesta�a incognita
	// 2- Mostare la pagina activa o el historial de la pestana
	void Mostrar();
	// 3- Configuracion
	void actualizarConfiguracion(Configuracion*);
	// 4- Eliminar PestanaActiva
	bool EliminarPestana();
	// 5- Filtro
	void Filtro(std::string);
	/*----Sistema de marcadores----*/
	// 1- Agregar marcador
	bool agregarMarcador(Marcador*);
	// 2- Busqueda de marcador
	std::string busquedaMarcador(const std::string&)const;
	/*----B�squeda y filtrado de historial----*/
	// 1- Guardar
	void guardarSeccion(const std::string);
	// 2- Cargar una seccion
	void cargarSeccion(const std::string);
	/*----Navegaci�n privada----*/
	 //1- Crear Pesta�a incognito
	// meto en  Administrador de pesta�as
	/*----Pol�ticas de administraci�n del historial----*/
	 //-Limitacion de entras
	 //-Limpiar por tiempo 
	 //Realiza en aregar y mostrar 
private:
	NavegadorWeb();
	static NavegadorWeb* navegadorWeb;
	VectorPaginas* csvpaginas;
	ListaPestana* pestanaLista;
	Configuracion* configuracion;
	GestorArchivos* archivos;
};


