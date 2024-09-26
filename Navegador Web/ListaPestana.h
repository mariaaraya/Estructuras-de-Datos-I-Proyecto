#pragma once

#include "Pestana.h"
class ListaPestana
{
public:
	ListaPestana();
	virtual~ListaPestana();
	bool agregarPestana(bool);
	void agregarPestana(Pestana*);
	Pagina* obtenerPaginaActiva();
	Pestana* obtenerPestanaActiva();
	void mostrarPestanaActiva();
	bool navegarArriba();
	bool navegarAbajo();
	const std::list<Pestana*>& obtenerListaPestanas() const;
	friend std::ostream& operator<<(std::ostream&, const ListaPestana&);
	/*Metdos relaciondos con las paginas*/
	void visitarPagina(Pagina*);
	bool navegarAtrasP();
	bool navegarAdelanteP();
	void mostarPagina();
	void PMostrar();
	//Metodo del marcadores
	bool agregarMarcador(Marcador*);
	bool agregarEtiqueta(std::string);
	std::string buscarPaginas(const std::string&) const;
	/*Metodo de comfiguracion*/
	void aplicarPoliticasHistorial(int, int);
private:
	std::list<Pestana*> listaP;
	std::list<Pestana*>::iterator PestanaActiva;
};
