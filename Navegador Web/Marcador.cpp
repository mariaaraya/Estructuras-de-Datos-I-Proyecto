#include "Marcador.h"

// Constructor
Marcador::Marcador(std::string nombre) : nombre(nombre)
{
}
// Destructor
Marcador::~Marcador() {  }

std::string Marcador::getNombre() const { return nombre; }
std::vector<std::string> Marcador::getEtiquetas() const { return etiquetas; }

void Marcador::setNombre(std::string nuevoNombre) { nombre = nuevoNombre; }

void Marcador::agregarEtiqueta(const std::string& etiqueta)
{
    if (std::find(etiquetas.begin(), etiquetas.end(), etiqueta) == etiquetas.end()) {
        etiquetas.push_back(etiqueta);
    }
}

void Marcador::eliminarEtiqueta(const std::string& etiqueta)
{
    auto it = std::remove(etiquetas.begin(), etiquetas.end(), etiqueta);
    if (it != etiquetas.end()) {
        etiquetas.erase(it, etiquetas.end());
    }
}

Marcador& Marcador::operator=(const Marcador& m)
{
    if (this != &m) {
        nombre = m.nombre;
        etiquetas = m.etiquetas; // Copiar etiquetas también
    }
    return *this;
}

bool Marcador::operator==(const Marcador& m) const
{
    return nombre == m.nombre && etiquetas == m.etiquetas;
}

std::ostream& operator<<(std::ostream& outp, const Marcador& m)
{
    outp << m.nombre << ": ";
    for (const auto& etiqueta : m.etiquetas) {
        outp << etiqueta << " ";
    }
    return outp;

}
