#pragma once
//#include "Libreria.h"
#include<string>
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
private:
	std::string titulo;
	std::string URL;
	bool modoIncognito; // true incognito
};

