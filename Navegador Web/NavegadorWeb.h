#pragma once
#include "Pestana.h"
#include "VectorPaginas.h"

class NavegadorWeb
{
public:
	NavegadorWeb();
	virtual~NavegadorWeb();
	bool agregarPestana(bool);
	Pestana* obtenerPaginaActiva();
	void mostrarPestanaActiva();
	void navegarArriba();
	void navegarAbajo();
	//Metodo del marcadores
	void agregarMarcador(Marcador*);
	void agregarEtiqueta(std::string);
	//Metodos de Pestana
	void PnavegarAdelante();
	void PnavegarAtras();
	bool visitarPagina(std::string);
	// Archivos binarios 
	void guardarNavegadorWeb(std::string&);
	void leerNavegadorWeb(std::string&);

	friend std::ostream& operator<<(std::ostream&, const NavegadorWeb&);
private:
	std::list<Pestana*> listaP;
	std::list<Pestana*>::iterator PestanaActiva;
	VectorPaginas* paginas;
};
