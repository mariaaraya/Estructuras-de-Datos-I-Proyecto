#pragma once
#include "ListaPestana.h"

class GestorArchivos
{
public:
	GestorArchivos() = default;
	~GestorArchivos() = default;
	void Guardar(const std::string, ListaPestana*);
	bool verificarArchivo(const std::string nombreArchivo);
	ListaPestana* Leer(const std::string);
private:

};
