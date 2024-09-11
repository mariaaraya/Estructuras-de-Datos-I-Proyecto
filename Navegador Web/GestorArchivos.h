#pragma once
#include "Clases.h"

class GestorArchivos
{
public:
	GestorArchivos() = default;
	~GestorArchivos() = default;
	void Guardar(const std::string, NavegadorWeb*);
	void Leer(const std::string, NavegadorWeb*);
private:

};
