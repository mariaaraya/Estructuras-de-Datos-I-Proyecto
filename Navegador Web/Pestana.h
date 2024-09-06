#pragma once
#include "Libreria.h"
#include "Historial.h"

class Pestana
{
public:
	Pestana(Historial* = nullptr);
	~Pestana();

	Historial* getHistorial();
	void setHistorial(Historial*);

	void irAdelante();
	void irAtras();
	void visitarPagina(std::string);

	void mostrarHistorial(std::ostream&) const;

private:
	Historial* historial;

};

