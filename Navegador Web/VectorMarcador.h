#pragma once
#include "Marcador.h"
#include <vector>

class VectorMarcador
{
public:
	VectorMarcador();
	virtual~VectorMarcador();
	bool agregarMarcador(Marcador*);
	Marcador* buscarMarcador(Marcador*);
	friend std::ostream& operator<<(std::ostream& outp, const VectorMarcador&);
private:
	std::vector <Marcador*> vecmarcador;
};