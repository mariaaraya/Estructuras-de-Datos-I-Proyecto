#include "Historial.h"

Historial::Historial() {}

Historial::~Historial()
{
    for (auto lista : paginas) {
        delete lista;
    }
    paginas.clear();
}

Pagina* Historial::getPaginas(int index)
{
    if (index >= 0 && index < paginas.size()) {
        return paginas[index];
    }
    return nullptr;
}

void Historial::agregarPagina(Pagina* nuevaPagina)
{
    paginas.push_back(nuevaPagina);

}

void Historial::eliminarPagina(int index)
{
    if (index >= 0 && index < paginas.size()) {
        delete paginas[index];
        paginas.erase(paginas.begin() + index);
    }
}

void Historial::mostrarHistorial(std::ostream& outp)
{
    for (const auto& pagina : paginas) {
        outp << *pagina << std::endl;
    }
}

std::ostream& operator<<(std::ostream& outp, const Historial& historial)
{
    for (const auto& pestaña : historial.paginas) {
        outp << *pestaña << std::endl;
    }
    return outp;
}
