#pragma once
#include "Libreria.h"
#include "Pagina.h"

class Historial
{
public:
    Historial();
    ~Historial();

    Pagina* getPaginas(int index);
    void agregarPesta�a(Pagina* nuevaPesta�a = new Pagina());
    void eliminarPesta�a(int index);
    friend std::ostream& operator<<(std::ostream& outp, const Historial&);

private:
    std::vector<Pagina*> pesta�as;
};
