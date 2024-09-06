#pragma once
#include "Libreria.h"
#include "Pagina.h"

class Historial
{
public:
    Historial();
    ~Historial();

    Pagina* getPaginas(int index);
    void agregarPagina(Pagina* nuevaPagina = new Pagina());
    void eliminarPagina(int index);
    void mostrarHistorial(std::ostream&);
    friend std::ostream& operator<<(std::ostream& outp, const Historial&);

private:
    std::vector<Pagina*> paginas;
};
