#pragma once
#include "Libreria.h"
#include "Pagina.h"

class Historial
{
public:
    Historial();
    ~Historial();

    Pagina* getPaginas(int index);
    void agregarPestaña(Pagina* nuevaPestaña = new Pagina());
    void eliminarPestaña(int index);
    friend std::ostream& operator<<(std::ostream& outp, const Historial&);

private:
    std::vector<Pagina*> pestañas;
};
