#pragma once
#include "Marcador.h"
#include "Libreria.h"

class VectorMarcador
{
public:
	VectorMarcador();
	virtual~VectorMarcador();
	bool agregarMarcador(Marcador*);
	Marcador* buscarMarcador(Marcador*);
	bool eliminarMarcador(Marcador*);

	friend std::ostream& operator<<(std::ostream& outp, const VectorMarcador&);
private:
	std::vector <Marcador*> vecmarcador;
};