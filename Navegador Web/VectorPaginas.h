#pragma once
#include "Pagina.h"
// clase que va a tener las paginas del cvs 
class VectorPaginas {
public:
	VectorPaginas();
	~VectorPaginas();
	bool leerCVS();
	void agregarPagina(Pagina*);
	Pagina* buscarPagina(std::string);
	friend std::ostream& operator<<(std::ostream& outp, const VectorPaginas&);
private:
	std::vector<Pagina*> paginas;
};