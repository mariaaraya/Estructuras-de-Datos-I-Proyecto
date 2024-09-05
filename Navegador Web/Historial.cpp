#include "Historial.h"

Historial::Historial() {}

Historial::~Historial()
{
    for (auto lista : pestañas) {
        delete lista;
    }
    pestañas.clear();
}

Pagina* Historial::getPaginas(int index)
{
    if (index >= 0 && index < pestañas.size()) {
        return pestañas[index];
    }
    return nullptr;
}

void Historial::agregarPestaña(Pagina* nuevaPestaña)
{
    pestañas.push_back(nuevaPestaña);

}

void Historial::eliminarPestaña(int index)
{
    if (index >= 0 && index < pestañas.size()) {
        delete pestañas[index];
        pestañas.erase(pestañas.begin() + index);
    }
}

std::ostream& operator<<(std::ostream& outp, const Historial& historial)
{
    for (const auto& pestaña : historial.pestañas) {
        outp << *pestaña << std::endl;
    }
    return outp;
}
