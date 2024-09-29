#pragma once
#include "ListaPestana.h"

class GestorArchivos
{
public:
	GestorArchivos() = default;
	~GestorArchivos() = default;
	void Guardar(const std::string, ListaPestana*);
	ListaPestana* Leer(const std::string);
private:

};
// guardar el historial de navegaci�n en un archivo (binario)