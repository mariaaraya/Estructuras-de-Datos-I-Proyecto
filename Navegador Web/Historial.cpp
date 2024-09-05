#include "Historial.h"

Historial::Historial() {}

Historial::~Historial()
{
    for (auto lista : pesta�as) {
        delete lista;
    }
    pesta�as.clear();
}

Pagina* Historial::getPaginas(int index)
{
    if (index >= 0 && index < pesta�as.size()) {
        return pesta�as[index];
    }
    return nullptr;
}

void Historial::agregarPesta�a(Pagina* nuevaPesta�a)
{
    pesta�as.push_back(nuevaPesta�a);

}

void Historial::eliminarPesta�a(int index)
{
    if (index >= 0 && index < pesta�as.size()) {
        delete pesta�as[index];
        pesta�as.erase(pesta�as.begin() + index);
    }
}

std::ostream& operator<<(std::ostream& outp, const Historial& historial)
{
    for (const auto& pesta�a : historial.pesta�as) {
        outp << *pesta�a << std::endl;
    }
    return outp;
}
