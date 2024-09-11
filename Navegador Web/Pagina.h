#pragma once
#include "Libreria.h"
#include "Marcador.h"

class Pagina
{
public:
	Pagina(std::string = " ", std::string = " ");
	Pagina(std::string, std::string, Marcador*);
	Pagina(const Pagina& otra);
	virtual~Pagina();

	// Getters
	std::string getTitulo() const;
	std::string getURL() const;
	Marcador* getMarcador();
	// Setters
	void setTitulo(std::string);
	void setURL(std::string);
	void setMarcador(Marcador*);
	void agregarEtiqueta(std::string);
	Pagina& operator=(const Pagina&);
	bool operator==(const Pagina&);
	friend std::ostream& operator<<(std::ostream& outp, const Pagina&);


private:
	std::string titulo;
	std::string URL;
	Marcador* marcador;
};

// archivos binarios 
	//void guardarPagina(std::ofstream&);
	//void leerPagina(std::ifstream&);