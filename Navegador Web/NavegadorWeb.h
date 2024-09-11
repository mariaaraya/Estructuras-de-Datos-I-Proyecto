#pragma once
#include "Pestana.h"
#include "VectorPaginas.h"

class NavegadorWeb
{
public:
	NavegadorWeb();
	virtual~NavegadorWeb();
	bool agregarPestana(bool);
	void agregarPestana(Pestana*);
	Pagina* obtenerPaginaActiva();
	Pestana* obtenerPestanaActiva();
	void mostrarPestanaActiva();
	void navegarArriba();
	void navegarAbajo();
	const std::list<Pestana*>& obtenerListaPestanas() const;
	//Metodo del marcadores
	void agregarMarcador(Marcador*);
	void agregarEtiqueta(std::string);
	//Metodos de Pestana
	void PnavegarAdelante();
	void PnavegarAtras();
	bool visitarPagina(std::string);

	friend std::ostream& operator<<(std::ostream&, const NavegadorWeb&);
private:
	std::list<Pestana*> listaP;
	std::list<Pestana*>::iterator PestanaActiva;
	VectorPaginas* paginas;
};

// Archivos binarios 
	/*void guardarNavegadorWeb(std::string&);
	void leerNavegadorWeb(std::string&);*/