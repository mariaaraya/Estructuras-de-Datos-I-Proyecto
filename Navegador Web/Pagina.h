#pragma once
#include "Libreria.h"
#include "Marcador.h"

class Pagina
{
public:
	Pagina(std::string = "TITULO", std::string = "URL", bool = false);
	virtual~Pagina();

	// Getters
	std::string getTitulo() const;
	std::string getURL() const;
	bool getModoIncognito() const;
	// Setters
	void setTitulo(std::string);
	void setURL(std::string);
	void setModoIncognito(bool);

	Pagina& operator=(const Pagina&);
	bool operator==(const Pagina&);
	friend std::ostream& operator<<(std::ostream& outp, const Pagina&);

    // M�todos est�ticos para manejo de lista de p�ginas (ya no hay clase lista pagina)
    static bool agregarPagina(Pagina* p);
    static void cambiarPagina(Pagina* p);
    static Pagina* obtenerPaginaActiva();
	static void mostrarPaginas(std::ostream& outp);
	static void navegarAtras();
	static void navegarAdelante();

private:
	std::string titulo;
	std::string URL;
	bool modoIncognito; // true incognito

    // Atributos est�ticos para la lista de p�ginas y navegaci�n
    static std::list<Pagina*> listaP;
    static std::list<Pagina*>::iterator PaginaActiva;
};
