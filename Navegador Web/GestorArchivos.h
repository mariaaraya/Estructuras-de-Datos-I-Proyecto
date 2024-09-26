#pragma once
#include "ListaPestana.h"

class GestorArchivos
{
public:
	GestorArchivos() = default;
	~GestorArchivos() = default;
	void Guardar(const std::string, ListaPestana*);
	void Leer(const std::string, ListaPestana*);
private:

};
