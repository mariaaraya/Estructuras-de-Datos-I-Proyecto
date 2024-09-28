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
	/*----Historial de navegación----*/
	bool navegar(int);
	/*----Administrador de pestañas----*/
	// 1- Creacion de paginas y pestañas
	bool visitarPagina(std::string);
	void crearPestana(bool); // Metodo tambien usado para creacion de pestaña incognita
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
	/*----Búsqueda y filtrado de historial----*/
	// 1- Guardar
	void guardarSeccion(const std::string);
	// 2- Cargar una seccion
	void cargarSeccion(const std::string);
	/*----Navegación privada----*/
	 //1- Crear Pestaña incognito
	// meto en  Administrador de pestañas
	/*----Políticas de administración del historial----*/
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


